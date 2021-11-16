#include <SDL.h>
#include <stdio.h>
#include <string.h>
#include "typesShorter.h"
#include "initCreate.h"
#include "map.h"
#include "Worm.h"
#include "game.h"
/*	\file Worm.c
*	\brief Contains all functions used for handling worm
*/

/*!
*	\brief Used for initializing every parameter of structure worm
*	\param worm's health
*	\param x coordinate
*	\param y coordinate 
*	\param height
*	\param width
*	\param img directory
*	\param velocity on x axis
*	\param velocity on y axis
*	\param bool if it's rotated
*/
struct Worm InitWorm(int health, int x, int y, int h, int w, char img_directory[], long double vx, long double vy, int rotate) {
	struct Worm worm;
	worm.health = health;
	worm.pos.x = x;
	worm.pos.y = y;
	worm.pos.h = h;
	worm.pos.w = w;
	worm.texture[0] = NULL;
	worm.bazooka_tex[0] = NULL;
	worm.texture[1] = NULL;
	worm.bazooka_tex[1] = NULL;
	worm.marker = NULL;
	worm.vx = vx;
	worm.vy = vy;
	worm.is_stable = 1;
	worm.rotate = rotate;
	worm.bazooka_state = 0;
	worm.missile.fired = 0;
	worm.missile.angle = 0;
	worm.power = 0;
	worm.score = 0;
	worm.name[0] = '\0';
	worm.font = TTF_OpenFont("Resources/Font/Oswald-Regular.ttf", 20);
	return worm;

}


/*!	\brief Used to check if there is collision between worm and map
*	\param worm
*	\param x position of map
*	\param y position of map
*/
int WormMapCollision(struct Worm worm, int posX, int posY) {
	return (((worm.pos.x <= posX) && (posX <= worm.pos.x + worm.pos.h)) && ((worm.pos.y <= posY) && (posY <= worm.pos.y + worm.pos.w)));
}


/*!	\brief Function used for uploading every texture and initializing worm and creating it
*	\param worm render
*	\param render
*	\param bool rotate
*	\param x coordinate
*	\param y coordinat
*	\param height
*	\param width
*/
struct Worm CreateWorm(Renderer worm_render, Window window, int rotate, int x, int y, int h, int w){
	
	
	Texture worm_texture = NULL;
	worm_texture = InitCreateTexture(worm_texture, 0, "Resources/Worm/WormWalk1.png", worm_render, NULL, window);
	struct Worm worm;
	worm.texture[0] = NULL;
	int i;
	worm.bazooka_tex[0] = NULL;
	worm.aim_tex = NULL;
	SDL_Rect worm_rect;
	worm_rect.x = 0;
	worm_rect.y = 0;
	worm_rect.w = 60;
	worm_rect.h = 43;
	worm = InitWorm(100, x, y , h , w, "1", 20, 20, rotate);
	worm.bazooka_tex[0] = InitCreateTexture(worm.bazooka_tex[0], 0, "Resources/Worm/Bazooka.png", worm_render, NULL, window);
	worm.bazooka_tex[1] = InitCreateTexture(worm.bazooka_tex[1], 0, "Resources/Worm/BazookaFlip.png", worm_render, NULL, window);
	worm.texture[1] = InitCreateTexture(worm.texture[1], 0, "Resources/Worm/WormWalk1Flip.png", worm_render, NULL, window);
	worm.aim_tex = InitCreateTexture(worm.aim_tex, 0, "Resources/Worm/Aim.png", worm_render, NULL, window);
	worm.missile.texture[0] = InitCreateTexture(worm.missile.texture[0], 0, "Resources/Worm/Missile.png", worm_render, NULL, window);
	worm.missile.texture[1] = InitCreateTexture(worm.missile.texture[1], 0, "Resources/Worm/MissileFlip.png", worm_render, NULL, window);
	worm.power_bar_tex = InitCreateTexture(worm.power_bar_tex, 0, "Resources/Worm/PowerBar.png", worm_render, NULL, window);
	worm.start_power_bar_tex = InitCreateTexture(worm.start_power_bar_tex, 0, "Resources/Worm/StartPowerBar.png", worm_render, NULL, window);
	worm.marker = InitCreateTexture(worm.marker, 0, "Resources/Worm/Marker.png", worm_render, NULL, window);
	worm.texture[0] = worm_texture;
	SDL_RenderCopy(worm_render, worm.texture[worm.rotate], &worm_rect, &worm.pos);
	SDL_RenderPresent(worm_render);
	return worm;

}

/*!	\brief Function used for drawing bazooka on screen by initializing it's parameters and uploading it's textures
*	\param map
*	\param worm render
*	\param worm
*	\param worm's state
*/
struct Worm DrawBazooka(struct Map map, Renderer worm_render, struct Worm worm, int state) {
	int bazooka_state = 0;
	int i;
	if (!worm.rotate)
		SDL_RenderCopyEx(worm_render, map.sky_tex, NULL, &worm.bazooka_rect, -2.9 * worm.bazooka_state, NULL, SDL_FLIP_NONE);
	else {
		SDL_RenderCopyEx(worm_render, map.sky_tex, NULL, &worm.bazooka_rect, 3.0 * worm.bazooka_state, NULL, SDL_FLIP_NONE);
	}
	SDL_RenderCopy(worm_render, map.sky_tex, NULL, &worm.aim_rect);
	for (i = worm.aim_rect.x - 3; i < worm.aim_rect.x + worm.aim_rect.w + 2; i++) {
		if (CheckBounds(worm.aim_rect, i, 0)) {
			map.pos[i].x = i;
			SDL_RenderCopy(worm_render, map.texture, NULL, &map.pos[i]);
		}
	}
	for (i = worm.bazooka_rect.x - 2; i < worm.bazooka_rect.x + worm.bazooka_rect.w + 2; i++) {
		if (CheckBounds(worm.aim_rect, i, 0)) {
			map.pos[i].x = i;
			SDL_RenderCopy(worm_render, map.texture, NULL, &map.pos[i]);
		}
	}
	SDL_Rect worm_rect;
	worm_rect.x = 0;
	worm_rect.y = 0;
	worm_rect.w = 60;
	worm_rect.h = 43;
	int x_times = 15 + state;
	worm.bazooka_rect.x = worm.pos.x + 10;
	worm.bazooka_rect.y = worm.pos.y + 41;
	worm.bazooka_rect.w = 32;
	worm.bazooka_rect.h =20;
	if (worm.rotate) worm.bazooka_rect.x += 10;
	if (!worm.rotate) {
		worm.aim_rect.x = worm.bazooka_rect.x - 45;
		worm.aim_rect.y = worm.bazooka_rect.y;
	}
	else {
		worm.aim_rect.x = worm.bazooka_rect.x + 53;
		worm.aim_rect.y = worm.bazooka_rect.y;
	}
	worm.aim_rect.w = 20;
	worm.aim_rect.h = 20;
	//SDL_RenderCopy(worm_render, worm.bazooka_tex, &worm_rect, &worm.pos);
	//UpdateWormMove(worm, worm_render, worm.pos);
	SDL_RenderCopy(worm_render, map.sky_tex, NULL, &worm.aim_rect);
	for (i = worm.aim_rect.x; i < worm.aim_rect.x + worm.aim_rect.w; i++) {
		if (CheckBounds(worm.aim_rect, i, 0)) {
			map.pos[i].x = i;
			SDL_RenderCopy(worm_render, map.texture, NULL, &map.pos[i]);
		}
	}
	SDL_RenderCopy(worm_render, map.sky_tex, NULL, &worm.bazooka_rect);
	for (i = worm.bazooka_rect.x; i < worm.bazooka_rect.x + worm.bazooka_rect.w; i++) {
		if (CheckBounds(worm.aim_rect, i, 0)) {
			map.pos[i].x = i;
			SDL_RenderCopy(worm_render, map.texture, NULL, &map.pos[i]);
		}
	}
	SDL_RenderCopy(worm_render, worm.aim_tex, NULL, &worm.aim_rect);
	SDL_RenderCopy(worm_render, worm.texture[worm.rotate], &worm_rect, &worm.pos);
	SDL_RenderCopy(worm_render, worm.bazooka_tex[worm.rotate], NULL, &worm.bazooka_rect);
	SDL_RenderPresent(worm_render);
	return worm;
}



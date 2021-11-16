#include "Worm.h"
#include "typesShorter.h"
#include "game.h"
#include "map.h"
#include "initCreate.h"
#include <SDL.h>
#include <SDL_image.h>
#include "makingMenu.h"
#include <stdio.h>
#include <math.h>
/*!
\file game.c
\brief Contains main functions for playing the game
*/

struct Button save_game_butt;
struct Button exit_pause_butt;
Texture pause_menu;
struct Button resume_butt;



//struct Worm worm1;
//struct Worm worm2;
//struct Map map;

/*!
*	\brief Function used for moving worm left
*	\param worm
*	\param map
*	\param render
*	\param time dT
*/
void MoveLeft(struct Worm *worm, struct Map map, Renderer render, long double dT, struct Worm *wormx) {
	worm->bazooka_state = 0;
	worm->rotate = 0;
	if (worm->pos.x + 26 >= 1) {
		SDL_Rect curr_pos;
		curr_pos.x = worm->pos.x;
		curr_pos.y = worm->pos.y;
		curr_pos.h = worm->pos.h;
		curr_pos.w = worm->pos.w;
		int i;
		if (abs(worm->pos.x - 1 - wormx->pos.x) > 150) {
			worm->is_stable = 0;
			if (map.pos[worm->pos.x + 27].y - map.pos[worm->pos.x + 26].y < 15) {
				worm->pos.y = map.pos[worm->pos.x + 26].y - worm->pos.h;
				worm->pos.x--;
			}
		}
			printf("Position of worm1: %d %d %d %d\n", worm->pos.x, worm->pos.y, worm->pos.w, worm->pos.h);
			printf("Position of worm: %d %d %d %d\n", worm->pos.x, worm->pos.y, worm->pos.w, worm->pos.h);
			printf("Position of worm: %d %d %d %d\n", curr_pos.x, curr_pos.y, curr_pos.w, curr_pos.h);
			*worm = UpdateWormMove(map, *worm, render, curr_pos, wormx);
		

	}
		//for (i = 1; i <= 2; i++) {
			//if (CheckBounds()) break;
			/*if (map.height[worm->pos.x + 26] == map.height[worm->pos.x + 27]) { // ide po ravnom
				worm->pos.x --;
				//worm->pos.x -= worm->vx * dT;
			}
			else if (map.height[worm->pos.x + 26] > map.height[worm->pos.x + 27]) { //penje se 
				worm->pos.x --;
				worm->pos.y --;
				//worm->pos.x -= worm->vx * dT;
				//worm->pos.y -= worm->vy * dT;
			}
			else { // spusta se
				worm->pos.x --;
				worm->pos.y ++;
				//worm->pos.x -= worm->vx * dT;
				//worm->pos.y += worm->vy * dT;
			}
		//}
	*worm = UpdateWormMove(*worm, render, curr_pos);
	//SDL_DestroyTexture(worm->texture);
	//*worm = UpdateWorm(*worm, render);
	//SDL_RenderClear(render);*/
}

/*!
*	\brief Function used for moving worm right
*	\param worm
*	\param map
*	\param render
*	\param time dT
*/
void MoveRight(struct Worm *worm, struct Map map, Renderer render, long double dT, struct Worm *wormx) {
	worm->bazooka_state = 0;
	worm->rotate = 1;
	if (worm->pos.x + 41 <= Width) {
		SDL_Rect curr_pos;
		curr_pos.x = worm->pos.x;
		curr_pos.y = worm->pos.y;
		curr_pos.h = worm->pos.h;
		curr_pos.w = worm->pos.w;
		int i;
		if (abs(worm->pos.x + 1 - wormx->pos.x) > 150) {
			worm->is_stable = 0;
			//for (i = 1; i <= 2; i++) {
			if (map.pos[worm->pos.x + 27].y - map.pos[worm->pos.x + 28].y < 15) {
				worm->pos.y = map.pos[worm->pos.x + 28].y - worm->pos.h;
				worm->pos.x++;
			}
		}
			*worm = UpdateWormMove(map, *worm, render, curr_pos, wormx);
		
	}

		/*if (map.height[worm->pos.x + 28] == map.height[worm->pos.x + 27]) { // ide po ravnom
			worm->pos.x ++;
			//worm->pos.x += worm->vx * dT;
		}
		else if (map.height[worm->pos.x + 28] > map.height[worm->pos.x + 27]) { //penje se 
			worm->pos.x ++;
			worm->pos.y --;
			//worm->pos.x += worm->vx * dT;
			//worm->pos.y -= worm->vy * dT;
		}
		else { // spusta se
			worm->pos.x ++;
			worm->pos.y ++;
			//worm->pos.x += worm->vx * dT;
			//worm->pos.y += worm->vy * dT;
		}
	//}
	*worm = UpdateWormMove(*worm, render, curr_pos);
	//printf("%llf %llf %lld %lld %.12llf \n", worm->vx, worm->vy, worm->pos.x, worm->pos.y, dT);
	//SDL_DestroyTexture(worm->texture);
	//*worm = UpdateWorm(*worm, render);*/
	//SDL_RenderClear(render);
}


/*void Jump(struct Worm* worm, struct Map map, Renderer render, long double dT) {
	long double gravity = 2;
		//if (worm.rotate) {
	Texture sky_texture = InitCreateTexture(sky_texture, )
	worm->vy = -worm->vy;
	SDL_Rect curr_pos;
	while (1) {
		printf("%llf\n", dT);
		curr_pos = worm->pos;
		worm->vy += gravity;
		worm->pos.x += (long double)worm->vx * 0.5;
		worm->pos.y += (long double)worm->vy * 0.5;
		if (worm->pos.y + worm->pos.h >= 680 - map.height[worm->pos.x + 27]) {
			worm->pos.y = 680 + map.height[worm->pos.x + 27] - worm->pos.h;
			*worm = UpdateWorm(*worm, render, curr_pos);
			break;
		}
		SDL_RenderCopy(render)
		printf("%llf\n", dT);
	}
	//}
}
*/

/*!
*	\brief Function used for updating worm on screen and everything that changes
*	\param map
*	\param worm
*	\param render
*	\param previous position (before change)
*/
struct Worm UpdateWormMove(struct Map map, struct Worm worm, Renderer render, SDL_Rect curr_pos, struct Worm *wormx) {
	double one_degree = 3.14 / 180;
	SDL_Rect worm_rect;
	worm_rect.x = 0;
	worm_rect.y = 0;
	worm_rect.w = 60;
	worm_rect.h = 43;
	int i;
	SDL_Rect modified_pos;
	modified_pos.x = curr_pos.x + 22;
	modified_pos.w = curr_pos.w - 44;
	modified_pos.y = curr_pos.y;
	modified_pos.h = curr_pos.h;

	worm.bazooka_rect.x = curr_pos.x + 10;
	worm.bazooka_rect.y = curr_pos.y + 41;
	worm.bazooka_rect.w = 32;
	worm.bazooka_rect.h = 20;
	SDL_Rect bazooka_rect;
	bazooka_rect = worm.bazooka_rect;
	bazooka_rect.x += 10;
	worm.aim_rect.w = 20;
	worm.aim_rect.h = 20;
	//if (worm.rotate) {
		worm.aim_rect.x = worm.bazooka_rect.x + (-45) * cos(3 * worm.bazooka_state * one_degree);
		worm.aim_rect.y = worm.bazooka_rect.y + 45 * sin(3 * worm.bazooka_state * one_degree);
		SDL_RenderCopy(render, map.sky_tex, NULL, &worm.aim_rect);
		
	//}
	//else {
		worm.aim_rect.x = bazooka_rect.x + 55 * cos(2.8 * worm.bazooka_state * one_degree);
		worm.aim_rect.y = bazooka_rect.y + (-55) * sin(2.8 * worm.bazooka_state * one_degree);
		SDL_RenderCopy(render, map.sky_tex, NULL, &worm.aim_rect);
		
	//}
	
	SDL_RenderCopy(render, map.sky_tex, NULL, &modified_pos);
	//if (worm.rotate) {
		SDL_RenderCopy(render, map.sky_tex, NULL, &worm.bazooka_rect);
	//}
	//else {
		SDL_RenderCopy(render, map.sky_tex, NULL, &bazooka_rect);
	//}
	/*SDL_RenderCopy(render, map.sky_tex, NULL, &worm.aim_rect);
	for (i = worm.aim_rect.x; i < worm.aim_rect.x + worm.aim_rect.w; i++) {
		if (CheckBounds(worm.aim_rect, i, 0)) {
			map.pos[i].x = i;
			SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
		}
	}*/
	//if (worm.rotate) {
		for (i = worm.bazooka_rect.x; i < worm.bazooka_rect.x + worm.bazooka_rect.w; i++) {
			if (CheckBounds(worm.aim_rect, i, 0)) {
				map.pos[i].x = i;
				SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
			}
		}
	//}
		for (i = worm.aim_rect.x; i < worm.aim_rect.x + worm.aim_rect.w; i++) {
			if (CheckBounds(worm.aim_rect, i, 0)) {
				map.pos[i].x = i;
				SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
			}
		}

		worm.aim_rect.x = worm.bazooka_rect.x + (-45) * cos(3 * worm.bazooka_state * one_degree);
		worm.aim_rect.y = worm.bazooka_rect.y + 45 * sin(3 * worm.bazooka_state * one_degree);
		for (i = worm.aim_rect.x; i < worm.aim_rect.x + worm.aim_rect.w; i++) {
			if (CheckBounds(worm.aim_rect, i, 0)) {
				map.pos[i].x = i;
				SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
			}
		}
	//else {
		for (i = bazooka_rect.x; i < bazooka_rect.x + bazooka_rect.w; i++) {
			if (CheckBounds(worm.aim_rect, i, 0)) {
				map.pos[i].x = i;
				SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
			}
		}
	//}
		printf("Position of worm: %d %d %d %d\n", curr_pos.x, curr_pos.y, curr_pos.w, curr_pos.h);
		printf("Position of worm: %d %d %d %d\n", worm.pos.x, worm.pos.y, worm.pos.w, worm.pos.h);
	for (i = curr_pos.x; i < curr_pos.x + curr_pos.w; i++) {
		if (CheckBounds(worm.aim_rect, i, 0)) {
			map.pos[i].x = i;
			SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
		}
	}

	SDL_RenderCopy(render, worm.texture[worm.rotate], &worm_rect, &worm.pos);
	SDL_RenderPresent(render);
	return worm;
}

/*!
*	\brief Function used for moving bazooka's aim
*	\param map
*	\param render	
*	\param worm
*	\param increments if aim is moved down and decrements if aim is moved up
*/
struct Worm MoveBazookaAim(struct Map map, Renderer worm_render, struct Worm worm, int add_sub, struct Worm *wormx) {
	//LEFT AIMING
	SDL_Rect bazooka_rect;
	bazooka_rect = worm.bazooka_rect;
	bazooka_rect.x += 10;
	SDL_Rect worm_rect;
	worm_rect.x = 0;
	worm_rect.y = 0;
	worm_rect.w = 60;
	worm_rect.h = 43;
	double one_degree = 3.14 / 180;
	worm.bazooka_state += add_sub;
	if (worm.bazooka_state >= 30) worm.bazooka_state = 30;
	else if (worm.bazooka_state <= -30) worm.bazooka_state = -30;
	printf("Aim pos before: %d %d\n", worm.aim_rect.x, worm.aim_rect.y);
	SDL_RenderCopy(worm_render, map.sky_tex, NULL, &worm.aim_rect);
	int i;
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
	SDL_RenderCopy(worm_render, map.sky_tex, NULL, &worm.pos);
	for (i = worm.pos.x; i < worm.pos.x + worm.pos.w; i++) {
		if (CheckBounds(worm.aim_rect, i, 0)) {
			map.pos[i].x = i;
			SDL_RenderCopy(worm_render, map.texture, NULL, &map.pos[i]);
		}
	}
	if (worm.bazooka_state <= 30 && worm.bazooka_state >= -30) {
		if (!worm.rotate) {
			if (worm.bazooka_state == 0) {
				worm.aim_rect.x = worm.bazooka_rect.x - 45;
				worm.aim_rect.y = worm.bazooka_rect.y;
			}
			else {
				worm.aim_rect.x = worm.bazooka_rect.x + (-45) * cos(3 * worm.bazooka_state * one_degree);
				worm.aim_rect.y = worm.bazooka_rect.y + 45 * sin(3 * worm.bazooka_state * one_degree);
			}
		}
		else {
			if (worm.bazooka_state == 0) {
				worm.aim_rect.x = worm.bazooka_rect.x + 53;
				worm.aim_rect.y = worm.bazooka_rect.y;
			}
			else {
				worm.aim_rect.x = worm.bazooka_rect.x + 55 * cos(-2.8 * worm.bazooka_state * one_degree);
				worm.aim_rect.y = worm.bazooka_rect.y + (-55) * sin(-2.8 * worm.bazooka_state * one_degree);
			}
		}
	}
	SDL_RenderCopy(worm_render, worm.aim_tex, NULL, &worm.aim_rect);
	SDL_RenderCopy(worm_render, worm.texture[worm.rotate], &worm_rect, &worm.pos);
	if (!worm.rotate)
		SDL_RenderCopyEx(worm_render, worm.bazooka_tex[worm.rotate], NULL, &worm.bazooka_rect, -2.9 * worm.bazooka_state, NULL, SDL_FLIP_NONE);
	else {
		SDL_RenderCopyEx(worm_render, worm.bazooka_tex[worm.rotate], NULL, &worm.bazooka_rect, 3.0 * worm.bazooka_state, NULL, SDL_FLIP_NONE);
	}
	SDL_RenderPresent(worm_render);
	printf("Aim pos after: %d %d %lf %lf %d\n", worm.aim_rect.x, worm.aim_rect.y, cos(3 * worm.bazooka_state), sin(3 * worm.bazooka_state * one_degree), worm.bazooka_state);
	if (!worm.rotate) {
		SDL_RenderCopyEx(worm_render, map.sky_tex, NULL, &worm.bazooka_rect, -2.9 * worm.bazooka_state, NULL, SDL_FLIP_NONE);
		for (i = worm.bazooka_rect.x; i < worm.bazooka_rect.x + worm.bazooka_rect.w; i++) {
			if (CheckBounds(worm.aim_rect, i, 0)) {
				map.pos[i].x = i;
				SDL_RenderCopy(worm_render, map.texture, NULL, &map.pos[i]);
			}
		}
	}
	else {
		//SDL_RenderCopy(worm_render, map.sky_tex, NULL, &worm.aim_rect);
		SDL_RenderCopyEx(worm_render, map.sky_tex, NULL, &worm.bazooka_rect, 3.0 * worm.bazooka_state, NULL, SDL_FLIP_NONE);
		for (i = bazooka_rect.x; i < bazooka_rect.x + bazooka_rect.w; i++) {
			if (CheckBounds(worm.aim_rect, i, 0)) {
				map.pos[i].x = i;
				SDL_RenderCopy(worm_render, map.texture, NULL, &map.pos[i]);
			}
		}
	}
	SDL_RenderCopy(worm_render, map.sky_tex, NULL, &worm.aim_rect);
	for (i = worm.aim_rect.x; i < worm.aim_rect.x + worm.aim_rect.w; i++) {
		if (CheckBounds(worm.aim_rect, i, 0)) {
			map.pos[i].x = i;
			SDL_RenderCopy(worm_render, map.texture, NULL, &map.pos[i]);
		}
	}
	return worm;
}


/*!
*	\brief Function used for preparing worm to shoot, handles power bar from pressing space to release
*	\param map
*	\param render
*	\param worm (which contains missile, powerbar, etc)
*/
struct Worm PrepareFire(struct Map *map, Renderer worm_render, struct Worm worm, struct Worm *wormx) {
	worm.power++;
	SDL_Rect bazooka_rect;
	bazooka_rect = worm.bazooka_rect;
	bazooka_rect.x += 10;
	if (worm.power > 50) {
		worm.power = 50;
	} 
	SDL_Rect worm_rect;
	worm_rect.x = 0;
	worm_rect.y = 0;
	worm_rect.w = 60;
	worm_rect.h = 43;
	if (!worm.rotate)
		worm.power_bar_rect.x = worm.pos.x + worm.pos.w + 20;
	else
		worm.power_bar_rect.x = worm.pos.x - 40;
	worm.power_bar_rect.y = worm.pos.y - 50;
	worm.power_bar_rect.w = 20;
	worm.power_bar_rect.h = worm.power;
	worm.start_power_bar_rect.x = worm.power_bar_rect.x;
	worm.start_power_bar_rect.y = worm.power_bar_rect.y;
	worm.start_power_bar_rect.w = 20;
	worm.start_power_bar_rect.h = 50;
	if (worm.start_power_bar_rect.x <= 0) {
		worm.start_power_bar_rect.x = 2;
		worm.start_power_bar_rect.y = 100;
		worm.power_bar_rect.x = worm.start_power_bar_rect.x;
		worm.power_bar_rect.y = worm.start_power_bar_rect.y;
	}
	else if (worm.start_power_bar_rect.x >= Width) {
		worm.start_power_bar_rect.x = Width - 22;
		worm.start_power_bar_rect.y = 100;
		worm.power_bar_rect.x = worm.start_power_bar_rect.x;
		worm.power_bar_rect.y = worm.start_power_bar_rect.y;
	}
	SDL_RenderCopy(worm_render, worm.start_power_bar_tex, NULL, &worm.start_power_bar_rect);
	SDL_RenderCopy(worm_render, worm.power_bar_tex, NULL, &worm.power_bar_rect);
	SDL_RenderCopy(worm_render, worm.texture[worm.rotate], &worm_rect, &worm.pos);
	if (!worm.rotate)
		SDL_RenderCopyEx(worm_render, worm.bazooka_tex[worm.rotate], NULL, &worm.bazooka_rect, -2.9 * worm.bazooka_state, NULL, SDL_FLIP_NONE);
	else 
		SDL_RenderCopyEx(worm_render, worm.bazooka_tex[worm.rotate], NULL, &worm.bazooka_rect, 3.0 * worm.bazooka_state, NULL, SDL_FLIP_NONE);
	SDL_RenderPresent(worm_render);
	return worm;
}

/*!
*	\brief Function used for making missile fly on parabolic trajectory
*	\param map
*	\param render
*	\param worm
*	\param used to determine the rotation speed of missile, determinet by the starting velocity
*/

struct Worm MissileFlight(struct Map *map, Renderer render, struct Worm worm, int rot_speed, struct Worm *wormx) {
	int i;
	double start_vy = -worm.missile.vy, pos_x = worm.missile.pos.x, pos_y = worm.missile.pos.y;
	int start_x, start_y;
	start_x = worm.missile.pos.x;
	start_y = worm.missile.pos.y;
	SDL_RenderCopy(render, map->sky_tex, NULL, &worm.aim_rect);
	for (i = worm.aim_rect.x; i < worm.aim_rect.x + worm.aim_rect.w; i++) {
		map->pos[i].x = i;
		SDL_RenderCopy(render, map->texture, NULL, &map->pos[i]);
	}
	SDL_RenderPresent(render);
	worm.missile.angle = -worm.missile.angle;
	i = 0;
	while (1) {
		if (MissileWormCollision(worm, *wormx)) {
			*map = DestructiveMap(*map, worm.missile.pos, render, &worm, wormx);
			break;
		}

		if (MapMissileCollision(worm.missile.pos, *map, wormx)) {
			if (worm.missile.pos.x + worm.missile.pos.w < Width && worm.missile.pos.x - worm.missile.pos.w > 0)
			*map = DestructiveMap(*map, worm.missile.pos, render, &worm, wormx);
			break;
		}
	
		if (i > 3) {
			SDL_RenderCopy(render, map->sky_tex, NULL, &worm.missile.pos);
			if (!worm.rotate)
				SDL_RenderCopyEx(render, map->sky_tex, NULL, &worm.missile.pos, -rot_speed * i + 1 + worm.missile.angle, NULL, SDL_FLIP_NONE);
			else
				SDL_RenderCopyEx(render, map->sky_tex, NULL, &worm.missile.pos, rot_speed * i + 1 + worm.missile.angle + 2 * (180 - worm.missile.angle), NULL, SDL_FLIP_NONE);
		}
		worm.missile.vy += 9.8 * worm.dt;
		pos_x -= worm.missile.vx * worm.dt;
		pos_y += worm.missile.vy * worm.dt;
		worm.missile.pos.x = pos_x;
		worm.missile.pos.y = pos_y;
		if (i > 2) {
			if (!worm.rotate)
				SDL_RenderCopyEx(render, worm.missile.texture[worm.rotate], NULL, &worm.missile.pos, -rot_speed * i + worm.missile.angle, NULL, SDL_FLIP_NONE);
			else
				SDL_RenderCopyEx(render, worm.missile.texture[worm.rotate], NULL, &worm.missile.pos, rot_speed * i + worm.missile.angle + 2 * (180 - worm.missile.angle), NULL, SDL_FLIP_NONE);
			SDL_Delay(30);
			SDL_RenderPresent(render);
		}
		printf("Missile %d %d %d %lf %lf\n", worm.power, worm.missile.pos.x, worm.missile.pos.y, -rot_speed * i + worm.missile.angle, worm.missile.vx);
		i++;
	}
	return worm;
}

/*!
*	\brief Function which check if collision between map and missile has occured
*	\param missile position
*	\param map
*/
int MapMissileCollision(SDL_Rect missile_pos, struct Map map, struct Worm *wormx) {
	if (map.pos[missile_pos.x].y < missile_pos.y + missile_pos.h)
		return 1;
	return 0;
}

/*!
*	\brief Updating map affected by missile
*	\param map
*	\param where the missile has exploded
*	\param render
*/
struct Map DestructiveMap(struct Map map, SDL_Rect miss_strike, Renderer render, struct Worm *worm, struct Worm *wormx) {
	SDL_Rect center;
	center.x = miss_strike.x - 30;
	center.y = miss_strike.y - 30;
	center.w = 60;
	center.h = 60;
	int i;
	miss_strike.y = miss_strike.y - 30;
	SDL_RenderCopy(render, map.sky_tex, NULL, &center);
	int cnt = 0, cnt2 = 0;
	int sgn = 0;
	printf("worm score and coeff : %d %d\n", worm->score, worm->coeff);
	for (i = center.x; i < center.x + center.w; i++) {
		map.pos[i].x = i;
		if (!CheckBounds(center, i, 0)) {
			cnt++;
			cnt2++;
			continue;
		}
		SDL_RenderCopy(render, map.sky_tex, NULL, &map.pos[i]);
		if (30 - cnt2 >= 0) sgn = 1;
		else sgn = -1;
		if (cnt > 30) cnt = cnt - 30;
		if (map.height[i] >= map.height[miss_strike.x] - sgn * cnt) map.height[i] = map.height[miss_strike.x] - sgn * cnt;
		if (map.pos[i].h >= map.pos[miss_strike.x].h - sgn * cnt) map.pos[i].h = map.pos[miss_strike.x].h - sgn * cnt;
		if (map.pos[i].y <= map.pos[miss_strike.x].y + sgn * cnt) map.pos[i].y = map.pos[miss_strike.x].y + sgn * cnt;
		SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
		if (i > wormx->pos.x + 15 && i < wormx->pos.x + wormx->pos.w - 15) {
			worm->score += worm->coeff;
			printf("worm score: %d\n", worm->score);
			wormx->health--;
		}
		if (i > worm->pos.x + 15 && i < worm->pos.x + worm->pos.w - 15) worm->health--;
		cnt++;
		cnt2++;
	}
	SDL_Rect worm_rect;
	worm_rect.x = 0;
	worm_rect.y = 0;
	worm_rect.w = 60;
	worm_rect.h = 43;
	SDL_RenderCopy(render, map.sky_tex, NULL, &worm->pos);
	SDL_RenderCopy(render, map.sky_tex, NULL, &worm->bazooka_rect);
	SDL_RenderCopy(render, map.sky_tex, NULL, &worm->aim_rect);
	SDL_RenderCopy(render, map.sky_tex, NULL, &wormx->pos);
	SDL_RenderCopy(render, map.sky_tex, NULL, &wormx->bazooka_rect);
	SDL_RenderCopy(render, map.sky_tex, NULL, &wormx->aim_rect);
	for (i = worm->pos.x; i < worm->pos.x + worm->pos.w; i++) {
		if (CheckBounds(center, i, 0)) {
			SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
		}
	}
	for (i = worm->bazooka_rect.x; i < worm->bazooka_rect.x + worm->bazooka_rect.w; i++) {
		if (CheckBounds(center, i, 0)) {
			SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
		}
	}
	for (i = worm->aim_rect.x; i < worm->aim_rect.x + worm->aim_rect.w; i++) {
		if (CheckBounds(center, i, 0)) {
			SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
		}
	}
	for (i = wormx->pos.x; i < wormx->pos.x + wormx->pos.w; i++) {
		if (CheckBounds(center, i, 0)) {
			SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
		}
	}
	for (i = wormx->aim_rect.x; i < wormx->aim_rect.x + wormx->aim_rect.w; i++) {
		if (CheckBounds(center, i, 0)) {
			SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
		}
	}
	for (i = wormx->aim_rect.x; i < wormx->aim_rect.x + wormx->aim_rect.w; i++) {
		if (CheckBounds(center, i, 0)) {
			SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
		}
	}
	worm->pos.y = map.pos[worm->pos.x + 27].y - 64;
	wormx->pos.y = map.pos[wormx->pos.x + 27].y - 64;
	worm->bazooka_rect.y = worm->pos.y + 41;	
	wormx->bazooka_rect.y = wormx->pos.y + 41;
	worm->bazooka_state = 0;
	wormx->bazooka_state = 0;
	if (!worm->rotate) {
		worm->aim_rect.x = worm->bazooka_rect.x - 45;
		worm->aim_rect.y = worm->bazooka_rect.y;
	}
	else {
		worm->aim_rect.x = worm->bazooka_rect.x + 53;
		worm->aim_rect.y = worm->bazooka_rect.y;
	}

	if (!wormx->rotate) {
		wormx->aim_rect.x = wormx->bazooka_rect.x - 45;
		wormx->aim_rect.y = wormx->bazooka_rect.y;
	}
	else {
		wormx->aim_rect.x = wormx->bazooka_rect.x + 53;
		wormx->aim_rect.y = wormx->bazooka_rect.y;
	}
	/*SDL_RenderCopy(render, worm->texture, &worm_rect, &worm->pos);
	SDL_RenderCopy(render, worm->bazooka_tex, NULL, &worm->bazooka_rect);
	SDL_RenderCopy(render, worm->aim_tex, NULL, &worm->aim_rect);
	SDL_RenderCopy(render, wormx->texture, &worm_rect, &wormx->pos);
	SDL_RenderCopy(render, wormx->bazooka_tex, NULL, &wormx->bazooka_rect);
	SDL_RenderCopy(render, wormx->aim_tex, NULL, &wormx->aim_rect);
	*/
	*worm = DrawBazooka(map, render, *worm, 0);
	*wormx = DrawBazooka(map, render, *wormx, 0);
	printf("worm wormx h and score:%d %d %d %d\n", worm->health, worm->score, wormx->health, wormx->score);
	//SDL_Delay(2000);
	//SDL_RenderPresent(render);
	//SDL_Delay(2000);
	//SDL_RenderCopy(render, map1.bomb_tex, NULL, &center);
	SDL_RenderPresent(render);
	return map;
	
}

/*!
*	\brief Preparing and shooting missile, without its flight
*	\param map
*	\param render
*	\param worm
*/
struct Worm Firee(struct Map *map, Renderer render, struct Worm worm, struct Worm *wormx) {
	SDL_Rect bazooka_rect;
	bazooka_rect = worm.bazooka_rect;
	bazooka_rect.x += 10;
	worm.bazooka_flip_rect = bazooka_rect;
	double one_degree = 3.14 / 180;
	if (!worm.rotate) {
		worm.missile.pos.x = worm.bazooka_rect.x + (-15) * cos(3 * worm.bazooka_state * one_degree);
		worm.missile.pos.y = worm.bazooka_rect.y + 15 * sin(3 * worm.bazooka_state * one_degree);
	}
	else {
		worm.missile.pos.x = worm.bazooka_rect.x + 15 * cos(3 * worm.bazooka_state * one_degree);
		worm.missile.pos.y = worm.bazooka_rect.y + 15 * sin(3 * worm.bazooka_state * one_degree);
	}
	worm.missile.pos.w = 16;
	worm.missile.pos.h = 10;
	worm.missile.angle = 3 * worm.bazooka_state;
	
 	if (!worm.rotate)
		worm.missile.vx = worm.power * 2 * cos(worm.missile.angle * one_degree);
	else 
		worm.missile.vx = -worm.power * 2 * cos(worm.missile.angle * one_degree);
	worm.missile.vy = worm.power * 2 * sin(worm.missile.angle * one_degree);
	worm.dt = 0.15;
	int rot_speed = 1;
	if (worm.power < 15) rot_speed = 3;
	worm = MissileFlight(map, render, worm, rot_speed, wormx);
	return worm;
}

/*!	\brief Function used to prepare and shoot missile for ai
*	\param map
*	\param render
*	\param worm
*	\paramm wormx
*/
struct Worm AIFiree(struct Map *map, Renderer render, struct Worm worm, struct Worm *wormx) {
	SDL_Rect bazooka_rect;
	bazooka_rect = worm.bazooka_rect;
	bazooka_rect.x += 10;
	worm.bazooka_flip_rect = bazooka_rect;
	double one_degree = 3.14 / 180;
	worm.missile.angle = -worm.missile.angle / one_degree;
	if (!worm.rotate) {
		worm.missile.pos.x = worm.bazooka_rect.x + (-15) * cos(3 * worm.bazooka_state * one_degree);
		worm.missile.pos.y = worm.bazooka_rect.y + 15 * sin(3 * worm.bazooka_state * one_degree);
	}
	else {
		worm.missile.pos.x = worm.bazooka_rect.x + 15 * cos(3 * worm.bazooka_state * one_degree);
		worm.missile.pos.y = worm.bazooka_rect.y + 15 * sin(3 * worm.bazooka_state * one_degree);
	}
	worm.missile.pos.w = 16;
	worm.missile.pos.h = 10;
	//worm.missile.angle = 3 * worm.bazooka_state;
	
 	if (!worm.rotate)
		worm.missile.vx = worm.power * 2 * cos(worm.missile.angle * one_degree);
	else 
		worm.missile.vx = -worm.power * 2 * cos(worm.missile.angle * one_degree);
	worm.missile.vy = worm.power * 2 * sin(worm.missile.angle * one_degree);
	worm.dt = 0.15;
	int rot_speed = 1;
	if (worm.power < 15) rot_speed = 3;
	worm = MissileFlight(map, render, worm, rot_speed, wormx);
	return worm;
}

/*!
*	\brief Function used to check if an object has reached the end of terrain
*	\param	Position of an object 
*	\param	x coordinate
*	\param if choice != 0, checking for an object, else checking for an x coordinate
*/
int CheckBounds(SDL_Rect position, int x_coord, int choice) {
		int OK = 1;
		if (choice) {
			if (position.x < 0 || position.x >= Width) OK = 0;
		}
		else {
			if (x_coord < 0 || x_coord >= Width) OK = 0;
		}
		return OK;
}

/*!	\brief Function used to check if missile has hit the worm
*	\param worm
*	\param wormx
*/
int MissileWormCollision(struct Worm worm, struct Worm wormx) {
	if (worm.missile.pos.x > wormx.pos.x + 20 && worm.missile.pos.x < wormx.pos.x + wormx.pos.w - 20 && (worm.missile.pos.y > wormx.pos.y + 20 || (worm.missile.pos.y + worm.missile.pos.h > wormx.pos.y + 20 && worm.missile.pos.y + worm.missile.pos.h < wormx.pos.y + wormx.pos.h)))
		return 1;
	return 0;
}

/*!	\brief Function used to determine which button has been pressed by player1
*	\param sdl keysim
*	\param render
*	\param worm
*	\param map
*	\param wormx
*/
int HandlePressedKey1(SDL_Keysym *keysym, Renderer render, struct Worm *worm, struct Map *map, struct Worm *wormx) {
	int mode = 0;
	switch ((keysym->sym)) {
	case SDLK_ESCAPE: {
		mode = 1;
		return mode;
		//Pauziraj i napravi resume-exit menu
		break;
	}
	case SDLK_LEFT: {
		//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
		MoveLeft(worm, *map, render, 0, wormx);
		break;
	}
	case SDLK_RIGHT: {
		//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
		MoveRight(worm, *map, render, 0, wormx);
		break;
	}
	case SDLK_UP: {
		//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
		if (worm->is_stable) *worm = MoveBazookaAim(*map, render, *worm, -1, wormx);
		//Jump(&worm1, map, render, dT);
		break;
	}
	case SDLK_DOWN: {
		//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
		if (worm->is_stable) *worm = MoveBazookaAim(*map, render, *worm, 1, wormx);
		break;
	}
	case SDLK_SPACE: {
		if (!worm->missile.fired)
			*worm = PrepareFire(map, render, *worm, wormx);
		break;
	}
	}
	return mode;
}

/*!	\brief Function used to determine which button has been released  by player1
*	\param sdl keysim
*	\param render
*	\param worm
*	\param map
*	\param wormx
*/
void HandleReleasedKey1(SDL_Keysym *keysym, Renderer render, struct Worm *worm, struct Map *map, struct Worm *wormx) {
	switch((keysym->sym)) {
		case SDLK_LEFT: {
			worm->is_stable = 1;
			//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
			*worm = DrawBazooka(*map, render, *worm, 0);
			//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
			break;
		}
		case SDLK_RIGHT: {
			worm->is_stable = 1;
			//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
			*worm = DrawBazooka(*map, render, *worm, 0);
			//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
			break;
		}
		case SDLK_SPACE: {
			if (!worm->missile.fired) {
				*worm = Firee(map, render, *worm, wormx);
				SDL_Delay(500);
				worm->missile.fired = 1;
				SDL_RenderCopy(render, map->sky_tex, NULL, &worm->start_power_bar_rect);
				int i;
				for (i = worm->start_power_bar_rect.x; i < worm->start_power_bar_rect.x + worm->start_power_bar_rect.w; i++) {
					map->pos[i].x = i;
					SDL_RenderCopy(render, map->texture, NULL, &map->pos[i]);
				}
				SDL_RenderPresent(render);
			}
		//if (worm1.is_stable) worm1.bazooka_state = Firee(render, worm1, -1);
		//Jump(&worm1, map, render, dT);
			break;
		}
	/*case SDLK_DOWN: {
		if (worm1.is_stable) worm1.bazooka_state = MoveBazookaAim(render, worm1, 1);
	}*/
	}

}

/*!	\brief Function used to determine which button has been pressed by player2
*	\param sdl keysim
*	\param render
*	\param worm
*	\param map
*	\param wormx
*/
int HandlePressedKey2(SDL_Keysym *keysym, Renderer render, struct Worm *worm, struct Map *map, struct Worm *wormx) {
	int mode = 0;
	switch ((keysym->sym)) {
	case SDLK_ESCAPE: {
		mode = 1;
		return mode;
		//Pauziraj i napravi resume-exit menu
		break;
	}
	case SDLK_a: {
		//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
		MoveLeft(worm, *map, render, 0, wormx);
		break;
	}
	case SDLK_d: {
		//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
		MoveRight(worm, *map, render, 0, wormx);
		break;
	}
	case SDLK_w: {
		//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
		if (worm->is_stable) *worm = MoveBazookaAim(*map, render, *worm, -1, wormx);
		//Jump(&worm1, map, render, dT);
		break;
	}
	case SDLK_s: {
		//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
		if (worm->is_stable) *worm = MoveBazookaAim(*map, render, *worm, 1, wormx);
		break;
	}
	case SDLK_x: {
		if (!worm->missile.fired)
			*worm = PrepareFire(map, render, *worm, wormx);
		break;
	}
	}
	return mode;
}

/*!	\brief Function used to determine which button has been released by player2
*	\param sdl keysim
*	\param render
*	\param worm
*	\param map
*	\param wormx
*/
void HandleReleasedKey2(SDL_Keysym *keysym, Renderer render, struct Worm *worm, struct Map *map, struct Worm *wormx) {
	switch ((keysym->sym)) {
	case SDLK_a: {
		worm->is_stable = 1;
		//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
		*worm = DrawBazooka(*map, render, *worm, 0);
		//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
		break;
	}
	case SDLK_d: {
		worm->is_stable = 1;
		//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
		*worm = DrawBazooka(*map, render, *worm, 0);
		//printf("Aim pos : %d %d\n", worm->aim_rect.x, worm->aim_rect.y);
		break;
	}
	case SDLK_x: {
		if (!worm->missile.fired) {
			*worm = Firee(map, render, *worm, wormx);
			SDL_Delay(500);
			worm->missile.fired = 1;
			SDL_RenderCopy(render, map->sky_tex, NULL, &worm->start_power_bar_rect);
			int i;
			for (i = worm->start_power_bar_rect.x; i < worm->start_power_bar_rect.x + worm->start_power_bar_rect.w; i++) {
				map->pos[i].x = i;
				SDL_RenderCopy(render, map->texture, NULL, &map->pos[i]);
			}
			SDL_RenderPresent(render);
		}
		//if (worm1.is_stable) worm1.bazooka_state = Firee(render, worm1, -1);
		//Jump(&worm1, map, render, dT);
		break;
	}
					 /*case SDLK_DOWN: {
					 if (worm1.is_stable) worm1.bazooka_state = MoveBazookaAim(render, worm1, 1);
					 }*/
	}

}


#include "gameMode.h"
#include <SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include "map.h"
#include "game.h"
#include "initCreate.h"
#include "makingMenu.h"
#include "AI.h"
#include "continue.h"
#include <string.h>
#include "highScores.h"
/*!	\file gameMode.c
*	\brief Contains game loops for every game mode existing in game
*/
struct Button save_game_butt;
struct Button exit_pause_butt;
Texture pause_menu;
struct Button resume_butt;
struct Button back_butt;

/*!	\brief Handle Multyplayer mode of the game, with game loop when in multiplayer
*	\param first worm
*	\param second worm
*	\param map
*	\param render
*	\param window
*/
int MultiplayerMode(struct Worm *worm_1, struct Worm *worm_2, struct Map map, Renderer render, Window window) {
	Event ev;
	int mode = 0;
	int round = 0;
	worm_1->coeff = 100;
	worm_2->coeff = 100;
	worm_1->score = 0;
	worm_2->score = 0;
	Texture texture1 = NULL, texture2 = NULL;
	texture1 = InitCreateTexture(texture1, 0, "Resources/Worm/PowerBar.png", render, NULL, window);
	texture2 = InitCreateTexture(texture2, 0, "Resources/Worm/StartPowerBar.png", render, NULL, window);
	int x1, x2, y1, y2;
	x1 = 40;
	x2 = Width - 140;
	y1 = y2 = 50;
	map = CreateMap(render, window);
	int is_running_mode = 1, move = 1, name = 0;
	*worm_1 = CreateWorm(render, window, 1, 500, map.pos[527].y - 64, 64, 64);
	*worm_2 = CreateWorm(render, window, 0, 800, map.pos[828].y - 64, 64, 64);
	//printf("Position of worm1: %d %d %d %d\n", worm_1->pos.x, worm_1->pos.y, worm_1->pos.w, worm_1->pos.h);
	//printf("Position of worm2: %d %d %d %d\n", worm_2->pos.x, worm_2->pos.y, worm_2->pos.w, worm_2->pos.h);
	*worm_1 = DrawBazooka(map, render, *worm_1, 0);
	*worm_2 = DrawBazooka(map, render, *worm_2, 0);
	//DrawHealthBar(texture1, texture2, x1, y1, worm_1->health, render);
	//DrawHealthBar(texture1, texture2, x2, y2, worm_2->health, render);
	DrawHealthBar(texture1, texture2, x1, y1, worm_1->health, render);
	DrawHealthBar(texture1, texture2, x2, y2, worm_2->health, render);
	//DrawMarker(render, worm_2, map);
	while (is_running_mode) {
		while (SDL_PollEvent(&ev) != 0 ) {
			
			if (ev.type == SDL_QUIT) {
				is_running_mode = 0;
			}
			if (ev.type == SDL_KEYDOWN && mode == 0) {
				if (move == 0)
					mode = HandlePressedKey2(&ev.key.keysym, render, worm_1, &map, worm_2);
				else
					mode = HandlePressedKey1(&ev.key.keysym, render, worm_2, &map, worm_1);
			}

			if (ev.type == SDL_KEYUP && mode == 0) {
				if (move == 0)
					HandleReleasedKey2(&ev.key.keysym, render, worm_1, &map, worm_2);
				else
					HandleReleasedKey1(&ev.key.keysym, render, worm_2, &map, worm_1);
			}
			if (mode == 1) mode = PausedMenu2(render, exit_pause_butt, pause_menu, resume_butt);
			else if (mode == 10) {
				Resume(worm_1, worm_2, &map, render);
				mode = 0;
			}
			if (worm_1->missile.fired && move == 0) {
				move = 1;
				worm_1->missile.fired = 0;
				*worm_1 = DrawBazooka(map, render, *worm_1, 0);
				*worm_2 = DrawBazooka(map, render, *worm_2, 0);
				worm_1->power = 0;
				DrawHealthBar(texture1, texture2, x1, y1, worm_1->health, render);
				DrawHealthBar(texture1, texture2, x2, y2, worm_2->health, render);
				DrawMarker(render, worm_2, map);
			}
			else if (worm_2->missile.fired && move == 1) {
				move = 0;
				worm_2->missile.fired = 0;
				*worm_2 = DrawBazooka(map, render, *worm_2, 0);
				*worm_1 = DrawBazooka(map, render, *worm_1, 0);
				worm_2->power = 0;
				worm_1->coeff = (double)worm_1->coeff / 1.2;
				worm_2->coeff = (double)worm_2->coeff / 1.2;
				DrawHealthBar(texture1, texture2, x1, y1, worm_1->health, render);
				DrawHealthBar(texture1, texture2, x2, y2, worm_2->health, render);
				DrawMarker(render, worm_1, map);
				//DrawSignForPlay()
			}
			if (worm_1->health <= 0 || worm_2->health <= 0 || mode == 2) return 1;
		//	printf("Position of worm1: %d %d %d %d\n", worm_1->pos.x, worm_1->pos.y, worm_1->pos.w, worm_1->pos.h);
		//	printf("Position of worm2: %d %d %d %d\n", worm_2->pos.x, worm_2->pos.y, worm_2->pos.w, worm_2->pos.h);			
			//printf("Is stable\n");
		}
	}

	return 1;
	/*SDL_Rect text_rect;
	int w = 0, h = 0;
	text_rect.h = 0;
	text_rect.w = 0;
	char *text1 = (char *)malloc(30*sizeof(char)), *text2 = (char *)malloc(30 * sizeof(char));
	TTF_Init();
	strcpy(text1, "Player 1 name:");
	strcpy(text2, "Player 2 name:");
	SDL_Color text_color = { 255, 255, 255, 255 };
	TTF_Font *font = TTF_OpenFont("Oswald-Regular.ttf", 20);
	TTF_CloseFont(font);
	
	text_rect.x = 200;
	text_rect.y = 260;
	Surface text_surf = TTF_RenderText_Solid(font, "Caaaaaao", text_color);
	Texture text_tex = SDL_CreateTextureFromSurface(render, text_surf);
	SDL_RenderCopy(render, text_tex, NULL, NULL);
	SDL_RenderPresent(render); */

	/*SDL_QueryTexture(text_tex, NULL, NULL, &text_rect.w, &text_rect.h);
	SDL_Rect new_rect;
	new_rect = text_rect;
	SDL_RenderCopy(render, text_tex, NULL, &new_rect);
	SDL_FreeSurface(text_surf);
	text_surf = NULL;

	text_rect.x = 200;
	text_rect.y = 300;
	text_surf = TTF_RenderText_Solid(font, text2, text_color);
	text_tex = SDL_CreateTextureFromSurface(render, text_surf);
	SDL_QueryTexture(text_tex, NULL, NULL, &text_rect.w, &text_rect.h);
	SDL_RenderCopy(render, text_tex, NULL, &text_rect);
	SDL_FreeSurface(text_surf);
	text_surf = NULL;
	SDL_RenderPresent(render);
	if (name < 2) SDL_StartTextInput();
	while (is_running_mode) {

		while (SDL_PollEvent(&ev) != 0) {
			if (name < 2) {
				if (SDL_TEXTINPUT || SDL_KEYDOWN) {
					if (strlen(text1) > 0) printf("%s", text1);
					if (name == 0) {
						if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_BACKSPACE && strlen(worm_1->name) > 0) {
							printf("1\n");
							worm_1->name[strlen(worm_1->name) - 1] = '\0';
						}
						else if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_RETURN) {
							printf("2\n");
							name++;
							text_rect.x = 200;
							text_rect.y = 250;
							text_surf = TTF_RenderText_Solid(font, text1, text_color);
							text_tex = SDL_CreateTextureFromSurface(render, text_surf);
							SDL_QueryTexture(text_tex, NULL, NULL, &text_rect.w, &text_rect.h);
							SDL_RenderCopy(render, text_tex, NULL, &text_rect);
							SDL_FreeSurface(text_surf);
							text_surf = NULL;
							
							text_rect.x = 260;
							text_rect.y = 250;
							text_surf = TTF_RenderText_Solid(font, worm_1->name, text_color);
							text_tex = SDL_CreateTextureFromSurface(render, text_surf);
							SDL_QueryTexture(text_tex, NULL, NULL, &text_rect.w, &text_rect.h);
							SDL_RenderCopy(render, text_tex, NULL, &text_rect);
							SDL_FreeSurface(text_surf);
							text_surf = NULL;
							SDL_RenderPresent(render);
						}
						else if (ev.type == SDL_TEXTINPUT){
							printf("3\n");
							strcat(worm_1->name, ev.text.text);
						}
					}
					else if (name == 1) {
						if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_BACKSPACE && strlen(worm_1->name) > 0) {
							printf("4\n");
							worm_2->name[strlen(worm_2->name) - 1] = '\0';
						}
						else if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_RETURN) {
							printf("5\n");
							name++;
							text_rect.x = 200;
							text_rect.y = 300;
							text_surf = TTF_RenderText_Solid(font, text2, text_color);
							text_tex = SDL_CreateTextureFromSurface(render, text_surf);
							SDL_QueryTexture(text_tex, NULL, NULL, &text_rect.w, &text_rect.h);
							SDL_RenderCopy(render, text_tex, NULL, &text_rect);
							SDL_FreeSurface(text_surf);
							text_surf = NULL;

							text_rect.x = 260;
							text_rect.y = 300;
							text_surf = TTF_RenderText_Solid(font, worm_2->name, text_color);
							text_tex = SDL_CreateTextureFromSurface(render, text_surf);
							SDL_QueryTexture(text_tex, NULL, NULL, &text_rect.w, &text_rect.h);
							SDL_RenderCopy(render, text_tex, NULL, &text_rect);
							SDL_FreeSurface(text_surf);
							text_surf = NULL;
							SDL_RenderPresent(render);
							SDL_StopTextInput();
						}
						
						else if (ev.type == SDL_TEXTINPUT) {
							printf("6\n");
							strcat(worm_2->name, ev.text.text);
						}
					}
				}
			}
		}
	}*/
}


/*!	\brief Handle Demo mode of the game, with game loop when in demo mode
*	\param first worm
*	\param second worm
*	\param map
*	\param render
*	\param window
*/
int DemoMode(struct Worm *worm_1, struct Worm *worm_2, struct Map map, Renderer render, Window window) {
	Event ev;
	int mode = 0;
	int round = 0;
	worm_2->coeff = 100;
	worm_2->score = 0;
	Texture texture1 = NULL, texture2 = NULL;
	texture1 = InitCreateTexture(texture1, 0, "Resources/Worm/PowerBar.png", render, NULL, NULL);
	texture2 = InitCreateTexture(texture2, 0, "Resources/Worm/StartPowerBar.png", render, NULL, NULL);
	int x1, x2, y1, y2;
	x1 = 40;
	x2 = Width - 140;
	y1 = y2 = 50;
	map = CreateMap(render, NULL);
	int is_running_mode = 1, move = 1, name = 0;
	int rand1 = ((double)rand() / (double)RAND_MAX) * (FIRST_MAX - FIRST_MIN) + FIRST_MIN;
	int rand2 = ((double)rand() / (double)RAND_MAX) * (SECOND_MAX - SECOND_MIN) + SECOND_MIN;
	*worm_1 = CreateWorm(render, NULL, 1, rand1, map.pos[rand1 + 27].y - 64, 64, 64);
	*worm_2 = CreateWorm(render, NULL, 0, rand2, map.pos[rand2 + 28].y - 64, 64, 64);
	*worm_1 = DrawBazooka(map, render, *worm_1, 0);
	*worm_2 = DrawBazooka(map, render, *worm_2, 0);
	DrawHealthBar(texture1, texture2, x1, y1, worm_1->health, render);
	DrawHealthBar(texture1, texture2, x2, y2, worm_2->health, render);
	DrawHealthBar(texture1, texture2, x1, y1, worm_1->health, render);
	DrawHealthBar(texture1, texture2, x2, y2, worm_2->health, render);
	while (is_running_mode) {
		while (SDL_PollEvent(&ev) != 0) {

			if (ev.type == SDL_QUIT) {
				is_running_mode = 0;
			}
			if (ev.type == SDL_KEYDOWN && mode == 0) {
				//if (move == 0)
				//mode = HandlePressedKey2(&ev.key.keysym, render, worm_1, &map, worm_2);
				//else
				mode = HandlePressedKey1(&ev.key.keysym, render, worm_2, &map, worm_1);
			}
		}
		if (mode == 1) mode = PausedMenu2(render, exit_pause_butt, pause_menu, resume_butt);
		else if (mode == 10) {
			Resume(worm_1, worm_2, &map, render);
			mode = 0;
		}
		if (move == 1 && mode == 0) {
			SDL_Delay(1500);
			worm_2 = AIDecision(worm_2, *worm_1, map, render, 0);
			*worm_2 = AIFiree(&map, render, *worm_2, worm_1);
			worm_2->missile.fired = 1;
		}
		else if (move == 0 && mode == 0) {
			SDL_Delay(1500);
			worm_1 = AIDecision(worm_1, *worm_2, map, render, 0);
			*worm_1 = AIFiree(&map, render, *worm_1, worm_2);
			worm_1->missile.fired = 1;
		}
		if (worm_1->missile.fired && move == 0) {
			move = 1;
			worm_1->missile.fired = 0;
			*worm_1 = DrawBazooka(map, render, *worm_1, 0);
			*worm_2 = DrawBazooka(map, render, *worm_2, 0);
			worm_1->power = 0;
			DrawHealthBar(texture1, texture2, x1, y1, worm_1->health, render);
			DrawHealthBar(texture1, texture2, x2, y2, worm_2->health, render);
			DrawMarker(render, worm_2, map);
		}
		else if (worm_2->missile.fired && move == 1) {
			move = 0;
			worm_2->missile.fired = 0;
			*worm_2 = DrawBazooka(map, render, *worm_2, 0);
			*worm_1 = DrawBazooka(map, render, *worm_1, 0);
			worm_2->power = 0;
			//worm_1->coeff = (double)worm_1->coeff / 1.2;
			//worm_2->coeff = (double)worm_2->coeff / 1.2;
			DrawHealthBar(texture1, texture2, x1, y1, worm_1->health, render);
			DrawHealthBar(texture1, texture2, x2, y2, worm_2->health, render);
			DrawMarker(render, worm_1, map);
			//DrawSignForPlay()
		}
		if (worm_1->health <= 0 || worm_2->health <= 0 || mode == 2) return 1;
	}
	return 1;
}


/*!	\brief Handle Singleplayer mode of the game, with game loop when in singleplayer
*	\param first worm
*	\param second worm
*	\param map
*	\param render
*	\param window
*	\param game mode
*/
int SingleplayerMode(struct Worm *worm_1, struct Worm *worm_2, struct Map map, Renderer render, Window window, int game_mode) {
	Event ev;
	char text_score1[10], text_score[20] ;
	int mode = 0;
	int round = 0;
	worm_2->coeff = 100;
	worm_2->score = 0;
	Texture texture1 = NULL, texture2 = NULL;
	texture1 = InitCreateTexture(texture1, 0, "Resources/Worm/PowerBar.png", render, NULL, NULL);
	texture2 = InitCreateTexture(texture2, 0, "Resources/Worm/StartPowerBar.png", render, NULL, NULL);
	int x1, x2, y1, y2;
	x1 = 40;
	x2 = Width - 140;
	y1 = y2 = 50;
	map = CreateMap(render, NULL);
	int is_running_mode = 1, move = 1, name = 0;
	int rand1 = ((double)rand() / (double)RAND_MAX) * (FIRST_MAX - FIRST_MIN) + FIRST_MIN;
	int rand2 = ((double)rand() / (double)RAND_MAX) * (SECOND_MAX - SECOND_MIN) + SECOND_MIN;
	*worm_1 = CreateWorm(render, NULL, 1, rand1, map.pos[rand1 + 27].y - 64, 64, 64);
	*worm_2 = CreateWorm(render, NULL, 0, rand2, map.pos[rand2 + 28].y - 64, 64, 64);
	*worm_1 = DrawBazooka(map, render, *worm_1, 0);
	*worm_2 = DrawBazooka(map, render, *worm_2, 0);
	DrawHealthBar(texture1, texture2, x1, y1, worm_1->health, render);
	DrawHealthBar(texture1, texture2, x2, y2, worm_2->health, render);
	DrawHealthBar(texture1, texture2, x1, y1, worm_1->health, render);
	DrawHealthBar(texture1, texture2, x2, y2, worm_2->health, render);
	if (game_mode == 0) worm_2->coeff = 50;
	else if (game_mode == 1) worm_2->coeff = 75;
	else if (game_mode == 2) worm_2->coeff = 100;


	SDL_Color text_color = { 0,0,0 };
	TTF_Font* font = TTF_OpenFont("Resources/Font/BROADW.ttf", 30);
	Texture font_texture = NULL;
	_itoa(worm_2->score, text_score1, 10);
	strcpy(text_score, "SCORE: ");
	strcat(text_score, text_score1);
	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text_score, text_color);
	font_texture = SDL_CreateTextureFromSurface(render, text_surface);
	SDL_Rect dst = { 1000, 80, text_surface->w, text_surface->h };
	SDL_RenderCopy(render, map.sky_tex, NULL, &dst);
	SDL_RenderCopy(render, font_texture, NULL, &dst);
	SDL_RenderPresent(render);
	//char score
	SDL_Delay(750);
	int option = 0;
	//return Highscores(*worm_1, render);
	while (is_running_mode) {
		while (SDL_PollEvent(&ev) != 0) {

			if (ev.type == SDL_QUIT) {
				is_running_mode = 0;
			}
			if (ev.type == SDL_KEYDOWN && mode == 0 && move == 1) {
				//if (move == 0)
					//mode = HandlePressedKey2(&ev.key.keysym, render, worm_1, &map, worm_2);
				//else
				mode = HandlePressedKey1(&ev.key.keysym, render, worm_2, &map, worm_1);
			}

			if (ev.type == SDL_KEYUP && move == 1) {
				//if (move == 0)
					//HandleReleasedKey2(&ev.key.keysym, render, worm_1, &map, worm_2);
				//else
				HandleReleasedKey1(&ev.key.keysym, render, worm_2, &map, worm_1);
			}
		}
			if (mode == 1) mode = PausedMenu1(render, exit_pause_butt, save_game_butt, pause_menu, resume_butt);
			else if (mode == 10) {
				Resume(worm_1, worm_2, &map, render);
				mode = 0;
			}
			else if (mode == 3) {
				SaveGame(worm_1, worm_2, &map);
				mode = 2;
			}
			if (move == 0 && mode == 0) {
				SDL_Delay(1500);
				worm_1 = AIDecision(worm_1, *worm_2, map, render, 0);
				*worm_1 = AIFiree(&map, render, *worm_1, worm_2);
				worm_1->missile.fired = 1;
			}
			if (worm_1->missile.fired && move == 0 && mode == 0) {
				move = 1;
				worm_1->missile.fired = 0;
				*worm_1 = DrawBazooka(map, render, *worm_1, 0);
				*worm_2 = DrawBazooka(map, render, *worm_2, 0);
				worm_1->power = 0;
				DrawHealthBar(texture1, texture2, x1, y1, worm_1->health, render);
				DrawHealthBar(texture1, texture2, x2, y2, worm_2->health, render);
				DrawMarker(render, worm_2, map);

				_itoa(worm_2->score, text_score1, 10);
				strcpy(text_score, "SCORE: ");
				strcat(text_score, text_score1);
				SDL_Surface* text_surface = TTF_RenderText_Solid(font, text_score, text_color);
				font_texture = SDL_CreateTextureFromSurface(render, text_surface);
				SDL_Rect dst = { 1000, 80, text_surface->w, text_surface->h };
				SDL_RenderCopy(render, map.sky_tex, NULL, &dst);
				SDL_RenderCopy(render, font_texture, NULL, &dst);
				SDL_RenderPresent(render);

			}
			else if (worm_2->missile.fired && move == 1 && mode == 0) {
				move = 0;
				worm_2->missile.fired = 0;
				*worm_2 = DrawBazooka(map, render, *worm_2, 0);
				*worm_1 = DrawBazooka(map, render, *worm_1, 0);
				worm_2->power = 0;
				//worm_1->coeff = (double)worm_1->coeff / 1.2;
				worm_2->coeff = (double)worm_2->coeff / 1.2;
				DrawHealthBar(texture1, texture2, x1, y1, worm_1->health, render);
				DrawHealthBar(texture1, texture2, x2, y2, worm_2->health, render);
				DrawMarker(render, worm_1, map);

				_itoa(worm_2->score, text_score1, 10);
				strcpy(text_score, "SCORE: ");
				strcat(text_score, text_score1);
				SDL_Surface* text_surface = TTF_RenderText_Solid(font,text_score, text_color);
				font_texture = SDL_CreateTextureFromSurface(render, text_surface);
				SDL_Rect dst = { 1000, 80, text_surface->w, text_surface->h };
				SDL_RenderCopy(render, map.sky_tex, NULL, &dst);
				SDL_RenderCopy(render, font_texture, NULL, &dst);
				SDL_RenderPresent(render);

				//DrawSignForPlay()
			}
			if (mode == 2 || worm_2->health <= 0) return 1;
			if (worm_1->health <= 0) {
				option = 0;
				return Highscores(*worm_2, render, &option);
			}
		
	}
	return 1;
}


/*!	\brief Handle ContinueGame, reading saved state of game from file and drawing it on screen
*	\param first worm
*	\param second worm
*	\param map
*	\param render
*	\param window
*/
int ContinueGame1(struct Worm *worm1, struct Worm *worm2, struct Map *map, Renderer render, Window window) {
	int flag = ContinueGame(&worm1, &worm2, &map);
	if (!flag) return 0;
	char text_score1[10], text_score[20];
	Event ev;
	int mode = 0;
	int round = 0;
	Texture texture1 = NULL, texture2 = NULL;
	texture1 = InitCreateTexture(texture1, 0, "Resources/Worm/PowerBar.png", render, NULL, NULL);
	texture2 = InitCreateTexture(texture2, 0, "Resources/Worm/StartPowerBar.png", render, NULL, NULL);
	int x1, x2, y1, y2;
	x1 = 40;
	x2 = Width - 140;
	y1 = y2 = 50;
	int i;
	map->texture = NULL;
	map->sky_tex = NULL;
	map->texture = InitCreateTexture(map->texture, 0, "Resources/AssetsForMap/Grass2.png", render, NULL, window);
	map->sky_tex = InitCreateTexture(map->sky_tex, 0, "Resources/AssetsForMap/Sky.png", render, NULL, window);
	SDL_RenderCopy(render, map->sky_tex, NULL, NULL);
	for (i = 0; i < Width; i++) {
		map->pos[i].w = 1;
		map->pos[i].y = 680 - map->height[i];
		map->pos[i].h = map->height[i];
		map->pos[i].x = i;
		SDL_RenderCopy(render, map->texture, NULL, &map->pos[i]);
	}
	SDL_RenderPresent(render);


	int is_running_mode = 1, move = 1, name = 0;
	//int rand1 = ((double)rand() / (double)RAND_MAX) * (FIRST_MAX - FIRST_MIN) + FIRST_MIN;
	//int rand2 = ((double)rand() / (double)RAND_MAX) * (SECOND_MAX - SECOND_MIN) + SECOND_MIN;
	worm1->bazooka_tex[0] = InitCreateTexture(worm1->bazooka_tex[0], 0, "Resources/Worm/Bazooka.png", render, NULL, window);
	worm1->bazooka_tex[1] = InitCreateTexture(worm1->bazooka_tex[1], 0, "Resources/Worm/BazookaFlip.png", render, NULL, window);
	worm1->texture[0] = InitCreateTexture(worm1->texture[0], 0, "Resources/Worm/WormWalk1.png", render, NULL, window);
	worm1->texture[1] = InitCreateTexture(worm1->texture[1], 0, "Resources/Worm/WormWalk1Flip.png", render, NULL, window);
	worm1->aim_tex = InitCreateTexture(worm1->aim_tex, 0, "Resources/Worm/Aim.png", render, NULL, window);
	worm1->missile.texture[0] = InitCreateTexture(worm1->missile.texture[0], 0, "Resources/Worm/Missile.png", render, NULL, window);
	worm1->missile.texture[1] = InitCreateTexture(worm1->missile.texture[1], 0, "Resources/Worm/MissileFlip.png", render, NULL, window);
	worm1->power_bar_tex = InitCreateTexture(worm1->power_bar_tex, 0, "Resources/Worm/PowerBar.png", render, NULL, window);
	worm1->start_power_bar_tex = InitCreateTexture(worm1->start_power_bar_tex, 0, "Resources/Worm/StartPowerBar.png", render, NULL, window);
	worm1->marker = InitCreateTexture(worm1->marker, 0, "Resources/Worm/Marker.png", render, NULL, window);

	worm2->bazooka_tex[0] = InitCreateTexture(worm2->bazooka_tex[0], 0, "Resources/Worm/Bazooka.png", render, NULL, window);
	worm2->bazooka_tex[1] = InitCreateTexture(worm2->bazooka_tex[1], 0, "Resources/Worm/BazookaFlip.png", render, NULL, window);
	worm2->texture[0] = InitCreateTexture(worm2->texture[0], 0, "Resources/Worm/WormWalk1.png", render, NULL, window);
	worm2->texture[1] = InitCreateTexture(worm2->texture[1], 0, "Resources/Worm/WormWalk1Flip.png", render, NULL, window);
	worm2->aim_tex = InitCreateTexture(worm2->aim_tex, 0, "Resources/Worm/Aim.png", render, NULL, window);
	worm2->missile.texture[0] = InitCreateTexture(worm2->missile.texture[0], 0, "Resources/Worm/Missile.png", render, NULL, window);
	worm2->missile.texture[1] = InitCreateTexture(worm2->missile.texture[1], 0, "Resources/Worm/MissileFlip.png", render, NULL, window);
	worm2->power_bar_tex = InitCreateTexture(worm2->power_bar_tex, 0, "Resources/Worm/PowerBar.png", render, NULL, window);
	worm2->start_power_bar_tex = InitCreateTexture(worm2->start_power_bar_tex, 0, "Resources/Worm/StartPowerBar.png", render, NULL, window);
	worm2->marker = InitCreateTexture(worm2->marker, 0, "Resources/Worm/Marker.png", render, NULL, window);

	SDL_Rect worm_rect;
	worm_rect.x = 0;
	worm_rect.y = 0;
	worm_rect.w = 60;
	worm_rect.h = 43;
	worm1->pos.y = (*map).pos[worm1->pos.x + 27].y - 64;
	worm1->pos.w = 64;
	worm1->pos.h = 64;

	worm2->pos.y = (*map).pos[worm2->pos.x + 28].y - 64;
	worm2->pos.w = 64;
	worm2->pos.h = 64;

	SDL_RenderCopy(render, worm1->texture[worm1->rotate], &worm_rect, &worm1->pos);

	SDL_RenderCopy(render, worm2->texture[worm2->rotate], &worm_rect, &worm2->pos);

	SDL_RenderPresent(render);

	//*worm1 = CreateWorm(render, NULL, 1, worm1->pos.x, (*map).pos[worm1->pos.x + 27].y - 64, 64, 64);
	//*worm2 = CreateWorm(render, NULL, 0, worm2->pos.x, (*map).pos[worm2->pos.x + 28].y - 64, 64, 64);
	*worm1 = DrawBazooka(*map, render, *worm1, 0);
	*worm2 = DrawBazooka(*map, render, *worm2, 0);
	DrawHealthBar(texture1, texture2, x1, y1, worm1->health, render);
	DrawHealthBar(texture1, texture2, x2, y2, worm2->health, render);
	DrawHealthBar(texture1, texture2, x1, y1, worm1->health, render);
	DrawHealthBar(texture1, texture2, x2, y2, worm2->health, render);

	SDL_Color text_color = { 0,0,0 };
	TTF_Font* font = TTF_OpenFont("Resources/Font/BROADW.ttf", 30);
	Texture font_texture = NULL;
	_itoa(worm2->score, text_score1, 10);
	strcpy(text_score, "SCORE: ");
	strcat(text_score, text_score1);
	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text_score, text_color);
	font_texture = SDL_CreateTextureFromSurface(render, text_surface);
	SDL_Rect dst = { 1000, 80, text_surface->w, text_surface->h };
	SDL_RenderCopy(render, map->sky_tex, NULL, &dst);
	SDL_RenderCopy(render, font_texture, NULL, &dst);
	SDL_RenderPresent(render);
	int option = 0;

	while (is_running_mode) {
		while (SDL_PollEvent(&ev) != 0) {

			if (ev.type == SDL_QUIT) {
				is_running_mode = 0;
			}
			if (ev.type == SDL_KEYDOWN && mode == 0 && move == 1) {
				//if (move == 0)
				//mode = HandlePressedKey2(&ev.key.keysym, render, worm_1, &map, worm_2);
				//else
				mode = HandlePressedKey1(&ev.key.keysym, render, worm2, map, worm1);
			}

			if (ev.type == SDL_KEYUP && move == 1) {
				//if (move == 0)
				//HandleReleasedKey2(&ev.key.keysym, render, worm_1, &map, worm_2);
				//else
				HandleReleasedKey1(&ev.key.keysym, render, worm2, map, worm1);
			}
		}
		if (mode == 1) mode = PausedMenu1(render, exit_pause_butt, save_game_butt, pause_menu, resume_butt);
		else if (mode == 10) {
			Resume(worm1, worm2, map, render);
			mode = 0;
		}
		else if (mode == 3) {
			SaveGame(worm1, worm2, map);
			mode = 2;
		}
		if (move == 0 && mode == 0) {
			SDL_Delay(1500);
			worm1 = AIDecision(worm1, *worm2, *map, render, 0);
			*worm1 = AIFiree(map, render, *worm1, worm2);
			worm1->missile.fired = 1;
		}
		if (worm1->missile.fired && move == 0 && mode == 0) {
			move = 1;
			worm1->missile.fired = 0;
			*worm1 = DrawBazooka(*map, render, *worm1, 0);
			*worm2 = DrawBazooka(*map, render, *worm2, 0);
			worm1->power = 0;
			DrawHealthBar(texture1, texture2, x1, y1, worm1->health, render);
			DrawHealthBar(texture1, texture2, x2, y2, worm2->health, render);
			DrawMarker(render, worm2, *map);

			_itoa(worm2->score, text_score1, 10);
			strcpy(text_score, "SCORE: ");
			strcat(text_score, text_score1);
			SDL_Surface* text_surface = TTF_RenderText_Solid(font, text_score, text_color);
			font_texture = SDL_CreateTextureFromSurface(render, text_surface);
			SDL_Rect dst = { 1000, 80, text_surface->w, text_surface->h };
			SDL_RenderCopy(render, map->sky_tex, NULL, &dst);
			SDL_RenderCopy(render, font_texture, NULL, &dst);
			SDL_RenderPresent(render);

		}
		else if (worm2->missile.fired && move == 1 && mode == 0) {
			move = 0;
			worm2->missile.fired = 0;
			*worm2 = DrawBazooka(*map, render, *worm2, 0);
			*worm1 = DrawBazooka(*map, render, *worm1, 0);
			worm2->power = 0;
			//worm_1->coeff = (double)worm_1->coeff / 1.2;
			worm2->coeff = (double)worm2->coeff / 1.2;
			DrawHealthBar(texture1, texture2, x1, y1, worm1->health, render);
			DrawHealthBar(texture1, texture2, x2, y2, worm2->health, render);
			DrawMarker(render, worm1, *map);

			_itoa(worm2->score, text_score1, 10);
			strcpy(text_score, "SCORE: ");
			strcat(text_score, text_score1);
			SDL_Surface* text_surface = TTF_RenderText_Solid(font, text_score, text_color);
			font_texture = SDL_CreateTextureFromSurface(render, text_surface);
			SDL_Rect dst = { 1000, 80, text_surface->w, text_surface->h };
			SDL_RenderCopy(render, map->sky_tex, NULL, &dst);
			SDL_RenderCopy(render, font_texture, NULL, &dst);
			SDL_RenderPresent(render);

			//DrawSignForPlay()
		}
		if (worm2->health <= 0 || mode == 2) return 1;
		if (worm1->health <= 0) {
			option = 0;
			return Highscores(*worm2, render, &option);
		}
	}


	return 1;
}


/*!	\brief Function used for drawing health bar
*	\param texture
*	\param abs texture
*	\param x position of bar
*	\param y position of bar
*	\param health	
*	\param render
*/
void DrawHealthBar(Texture texture, Texture abs_texture, int x_pos, int y_pos, int health, Renderer render) {
	SDL_Rect abs_health_bar, health_bar;
	health_bar.x = x_pos;
	health_bar.y = y_pos;
	health_bar.w = 100 - health;
	health_bar.h = 30;
	abs_health_bar.x = x_pos;
	abs_health_bar.y = y_pos;
	abs_health_bar.w = 100;
	abs_health_bar.h = 30;
	SDL_RenderCopy(render, abs_texture, NULL, &abs_health_bar);
	SDL_RenderCopy(render, texture, NULL, &health_bar);
	SDL_RenderPresent(render);
}

/*!	\brief Function used for drawing marker which points which player's turn it is
*	\param render
*	\param worm
*	\param map
*/
void DrawMarker(Renderer render, struct Worm *worm, struct Map map) {
	worm->marker_rect.x = worm->pos.x + 20;
	worm->marker_rect.y = worm->pos.y;
	worm->marker_rect.w = 16;
	worm->marker_rect.h = 20;
	SDL_RenderCopy(render, worm->marker, NULL, &worm->marker_rect);
	SDL_RenderPresent(render);
	SDL_Delay(800);
    SDL_RenderCopy(render, map.sky_tex, NULL, &worm->marker_rect);
	SDL_RenderPresent(render);
		
	
}

/*!	\brief Function used for continuing game after pause (drawing last state on screen)
*	\param worm1
*	\param worm2
*	\param map
*	\param render
*/
void Resume(struct Worm *worm1, struct Worm *worm2, struct Map *map, Renderer render){
	int i;
	SDL_Rect worm_rect;
	worm_rect.x = 0;
	worm_rect.y = 0;
	worm_rect.w = 60;
	worm_rect.h = 43;
	SDL_RenderCopy(render, map->sky_tex, NULL, NULL);
	for (i = 0; i < Width; i++) {
		map->pos[i].x = i;
		SDL_RenderCopy(render, map->texture, NULL, &map->pos[i]);
	}
	Texture texture1 = NULL, texture2 = NULL;
	texture1 = InitCreateTexture(texture1, 0, "Resources/Worm/PowerBar.png", render, NULL, NULL);
	texture2 = InitCreateTexture(texture2, 0, "Resources/Worm/StartPowerBar.png", render, NULL, NULL);
	int x1, x2, y1, y2;
	x1 = 40;
	x2 = Width - 140;
	y1 = y2 = 50;

	char text_score1[100], text_score[100];
	SDL_Color text_color = { 0,0,0 };
	TTF_Font* font = TTF_OpenFont("Resources/Font/BROADW.ttf", 30);
	Texture font_texture = NULL;
	_itoa(worm2->score, text_score1, 10);
	strcpy(text_score, "SCORE: ");
	strcat(text_score, text_score1);
	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text_score, text_color);
	font_texture = SDL_CreateTextureFromSurface(render, text_surface);
	SDL_Rect dst = { 1000, 80, text_surface->w, text_surface->h };
	SDL_RenderCopy(render, map->sky_tex, NULL, &dst);
	SDL_RenderCopy(render, font_texture, NULL, &dst);
	SDL_RenderPresent(render);

	DrawHealthBar(texture1, texture2, x1, y1, worm1->health, render);
	DrawHealthBar(texture1, texture2, x2, y2, worm2->health, render);
	SDL_RenderPresent(render);
	if (!worm1->rotate) 
		SDL_RenderCopy(render, worm1->texture[0], &worm_rect, &worm1->pos);

	else 
		SDL_RenderCopy(render, worm1->texture[1], &worm_rect, &worm1->pos);
	
	if (!worm2->rotate)
		SDL_RenderCopy(render, worm2->texture[0], &worm_rect, &worm2->pos);

	else
		SDL_RenderCopy(render, worm2->texture[1], &worm_rect, &worm2->pos);
	*worm1 = DrawBazooka(*map, render, *worm1, worm1->bazooka_state);
	*worm2 = DrawBazooka(*map, render, *worm2, worm2->bazooka_state);
	SDL_RenderPresent(render);
}

/*!	\brief Function used for writing your name into highscores and printing highscores on screen
*	\param worm
*	\param render
*	\param option
*/
int Highscores(struct Worm worm, Renderer render, int *option ) {
	//HighScoreList lista;
	/*char ime[30];
	int score = 1000;
		strcpy(ime, "Marko Misic");
		UpdateHighScores(ime, score);
	lista = ReadHighScores();
	int i;
	for (i = 0; i < 5; i++) {
		printf("%s %d\n", lista.list[i].name, lista.list[i].score);
	}*/
	SDL_Color text_color = { 0,0,0 };
	TTF_Font* font = TTF_OpenFont("Resources/Font/BROADW.ttf", 30);
	Texture font_texture = NULL;
	Texture font1_texture = NULL;
	Texture font2_texture = NULL;
	//_itoa(worm2->score, text_score1, 10);
	//strcpy(text_score, "SCORE: ");
	//strcat(text_score, text_score1);
	//SDL_Surface* text_surface = TTF_RenderText_Solid(font, text_score, text_color);
	//font_texture = SDL_CreateTextureFromSurface(render, text_surface);
	//SDL_Rect dst = { 1000, 80, text_surface->w, text_surface->h };
	//SDL_RenderCopy(render, map->sky_tex, NULL, &dst);
	//SDL_RenderCopy(render, font_texture, NULL, &dst);
	//SDL_RenderPresent(render);
	Texture texture = NULL;
	texture = InitCreateTexture(texture, 0, "Resources/MenuImage/worms_menu.png", render, NULL, NULL);
	SDL_RenderCopy(render, texture, NULL, NULL);
	
	char text[35], text1[30];
	
	
	strcpy(text1, "CONGRATS, YOU WON");
	SDL_Surface* text2_surface = TTF_RenderText_Solid(font, text1, text_color);
	font2_texture = SDL_CreateTextureFromSurface(render, text2_surface);
	SDL_Rect dst2 = { 370, 200, text2_surface->w, text2_surface->h };
	SDL_RenderCopy(render, texture, NULL, NULL);
	SDL_RenderCopy(render, font2_texture, NULL, &dst2);


	strcpy(text, "ENTER YOUR NAME FOR HIGHSCORES: ");
	SDL_Surface* text1_surface = TTF_RenderText_Solid(font, text, text_color);
	font1_texture = SDL_CreateTextureFromSurface(render, text1_surface);
	SDL_Rect dst1 = { 250, 200 + text2_surface->h, text1_surface->w, text1_surface->h };
	SDL_RenderCopy(render, font1_texture, NULL, &dst1);
	SDL_RenderPresent(render);


	char name[1000];
	strcpy(name, " ");
	name[0] = '\0';
	int quit = 0;
	Event ev;
	SDL_StartTextInput();
	int i;
	while (!quit) {
		int render_text = 0;
		while (SDL_PollEvent(&ev) != 0) {

			if (ev.type == SDL_KEYDOWN) {

				if (ev.key.keysym.sym == SDLK_RETURN && strlen(name) > 0) {
					quit = 1;
					SDL_Delay(50);
				}

				else if (ev.key.keysym.sym == SDLK_BACKSPACE && strlen(name) > 0) {
					for (i = 0; name[i] != '\0'; i++);
					name[i - 1] = '\0';
					if (strlen(name) == 0)
						render_text = 2;
					else render_text = 1;
					
				}

				else if (ev.key.keysym.sym == SDLK_SPACE && strlen(name) < 30) {
					strcat(name, " ");
					render_text = 1;
				}
			}
			else if (ev.type == SDL_TEXTINPUT && strlen(name) < 30) {
				strcat(name, ev.text.text);
				render_text = 1;
			}
			else render_text = 0;
		}
		if (render_text == 2) {
			SDL_RenderCopy(render, texture, NULL, NULL);
			SDL_RenderCopy(render, font2_texture, NULL, &dst2);
			SDL_RenderCopy(render, font1_texture, NULL, &dst1);
			SDL_RenderPresent(render);
		}
		if (render_text == 1) {
			printf("%s \n", name);
			SDL_Surface* text_surface = TTF_RenderText_Solid(font, name, text_color);
			font_texture = SDL_CreateTextureFromSurface(render, text_surface);
			SDL_Rect dst = { 370, 200 + text2_surface->h + text1_surface->h, text_surface->w, text_surface->h };
			SDL_RenderCopy(render, texture, NULL, NULL);
			SDL_RenderCopy(render, font2_texture, NULL, &dst2);
			SDL_RenderCopy(render, font1_texture, NULL, &dst1);
			SDL_RenderCopy(render, font_texture, NULL, &dst);
			SDL_RenderPresent(render);
			font_texture = NULL;
		}

	}
	SDL_StopTextInput();
	UpdateHighScores(name, worm.score);
	HighScoreList lista = ReadHighScores();
	for (i = 0; i < 5; i++) {
		printf("%s %d\n", lista.list[i].name, lista.list[i].score);
	}

	return MakeHighscores(render, NULL, back_butt, option);


}

/*void WriteScore(Texture texture, Texture abs_texture, int x_pos, int y_pos, int score, Renderer render) {
	SDL_Rect abs_score_bar, score_bar;
	score_bar.x = x_pos;
	score_bar.y = y_pos;
	score_bar.w = score;
	score_bar.h = 30;
	abs_health_bar
}*/

struct Worm Reset(struct Worm worm) {

}


//void SaveGame()


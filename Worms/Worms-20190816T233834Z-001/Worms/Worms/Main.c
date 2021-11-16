#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include "gameMode.h"
#include "initCreate.h"
#include "typesShorter.h"
#include "makingMenu.h"
#include "map.h"
#include "Worm.h"
#include "game.h"
//extern struct Worm worm1;
//extern struct Worm worm2;
//extern struct Map map;
 struct Button save_game_butt;
 struct Button exit_pause_butt;
 Texture pause_menu;
 struct Button resume_butt;
 struct Button back_butt;

int main(int argc, char* argv[]) {
	 struct Worm worm1;
	 struct Worm worm2;
	 struct Map map;
	Window window = NULL;
	Surface window_surface = NULL;
	int state = 0;
	TTF_Init();
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Error initialising video.%s\n", SDL_GetError());
		return 1;
	}

	window = InitCreateWindow(window, "Worms", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, 0);
	if (window == NULL) return 1;

	int isRunning = 1;
	Event ev;
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	Renderer render = NULL; 
	render = InitCreateRenderer(render, window, -1, render_flags);
	if (render == NULL) 
		return 1;

	window_surface = InitCreateSurface(window_surface, "Resources/MenuImage/worms_menu.png", window, render);

	if (window_surface == NULL)
		return 1;

	Texture texture = NULL;
	texture = InitCreateTexture(texture, 1, "1", render, window_surface, window);

	if (texture == NULL)
		return 1;

	SDL_RenderCopy(render, texture, NULL, NULL);
	SDL_RenderPresent(render);
	SDL_RenderClear(render);
	struct Button easy_butt;
	struct Button medium_butt;
	struct Button hard_butt;
	struct Button continue_butt;
	struct Button new_game_butt;
	struct Button highscore_butt;
	struct Button credits_butt;
	struct Button exit_butt;
	struct Button single_player_butt;
	struct Button multi_player_butt;
	struct Button back_butt;
	struct Button demo_butt;
	pause_menu = InitCreateTexture(pause_menu, 0, "Resources/Butts/PauseMenu.png", render, NULL, window);
	SDL_Rect credits_rect;
	Texture credits = NULL;
	credits = InitCreateTexture(credits, 0, "Resources/CreditsMenu/Credits.jpg", render, NULL, NULL);
	InitEverything(render, &continue_butt, &new_game_butt, &highscore_butt, &credits_butt, &exit_butt, &single_player_butt, &multi_player_butt, &back_butt, &credits_rect, credits, &exit_pause_butt, &save_game_butt, pause_menu, &demo_butt, &easy_butt, &medium_butt, &hard_butt, &resume_butt);
	int i;
	for (i = 0; i < 1200; i++) {
		map.height[i] = 0;
		map.pos[i].h = 0;
		map.pos[i].w = 0;
		map.pos[i].x = i;
		map.pos[i].y = 0;
	}
	map.created = 0;
	map.texture = NULL;
	worm1.rotate = 0;
	worm1.texture[worm1.rotate] = NULL;
	int high = 0;
	int option = 0;
	while (isRunning) {
		
		while (SDL_PollEvent(&ev) != 0) {
			if (ev.type == SDL_QUIT)
				isRunning = 0;
			/*if (ev.type == SDL_KEYDOWN && state == 7) {
				HandlePressedKey(&ev.key.keysym, render, 0);
			}
			if (ev.type == SDL_KEYUP && state == 7) {
				HandleReleasedKey(&ev.key.keysym, render);
			}*/
	
			//printf("Is stable\n");
		}

		if (state!= 7) SDL_RenderCopy(render, texture, NULL, NULL);
		switch (state) {
		case 0:	state = MakeMain(render, window, continue_butt, new_game_butt, highscore_butt, credits_butt, exit_butt, demo_butt); break;
		case 1: state = MakeNewGame1(render, window, single_player_butt, multi_player_butt, back_butt); break;
		case 2: state = ContinueGame1(&worm1, &worm2, &map, render, window); break;//nesto sa continue-om 
		case 3:
			state = MakeHighscores(render, window, back_butt, &option); 
			 break;//ispise se highscore tabela
		case 4: state = MakeInstructions(render, window, back_butt); break;//ispis instrukcija
		case 5:	state = MakeCredits(render, window, back_butt, credits); break;//credits se ispisu
		case 6: isRunning = 0; break;
		case 7: {
			/*if (!map.created) {
				map = CreateMap(render, window);
				worm1 = CreateWorm(render, window, 0, 600, 616 - map.height[627], 64, 64);
				worm1 = DrawBazooka(map,render, worm1, 0);
				map.created = 1;
				for (i = 0; i < 1200; i++) {
					map.pos[i].x = i;
					SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
				}
			}*/
			state = MakeNewGame(render, back_butt, easy_butt, medium_butt, hard_butt, texture);
		}break;//izabran single player
		case 8: {

			SDL_RenderCopy(render, texture, NULL, NULL);
			SDL_RenderPresent(render);
			state = MultiplayerMode(&worm1, &worm2, map, render, window);
			break; }//izabran multiplayer 

		case 9: {
			SDL_RenderCopy(render, texture, NULL, NULL);
			SDL_RenderPresent(render);
			state = DemoMode(&worm1, &worm2, map, render, window);
			break;
		}
		case 10: {
			SDL_RenderCopy(render, texture, NULL, NULL);
			SDL_RenderPresent(render);
			state = SingleplayerMode(&worm1, &worm2, map, render, window, 0);
			break;
		}
		case 11: {
			SDL_RenderCopy(render, texture, NULL, NULL);
			SDL_RenderPresent(render);
			state = SingleplayerMode(&worm1, &worm2, map, render, window, 1);
			break;
		}
		case 12: {
			SDL_RenderCopy(render, texture, NULL, NULL);
			SDL_RenderPresent(render);
			state = SingleplayerMode(&worm1, &worm2, map, render, window, 2);
			break;
		}
		}

		//printf("%llf %lld %lld %lld\n", dT, curr_time, last_time, frequency);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
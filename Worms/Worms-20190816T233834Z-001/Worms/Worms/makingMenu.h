#ifndef _makingMenu_h_
#define _makingMenu_h_
#define MAIN_MENU_EL 5
#include <SDL.h>
#include "typesShorter.h"
#include "initCreate.h"

/*!    \file makingMenu.h
*	\brief Contains declarations of functions used to make menus
*/


void InitEverything(Renderer butt_render, struct Button *continue_butt, struct Button * new_game_butt, struct Button *highscore_butt, struct Button *credits_butt, struct Button *exit_butt, struct Button *single_player_butt, struct Button *multi_player_butt, struct Button *back_butt, SDL_Rect *credits_rect, Texture credits, struct Button *exit_pause_butt, struct Button *save_game_butt, Texture pause_menu, struct Button *demo_butt, struct Button *easy_butt, struct Button *medium_butt, struct Button *hard_butt, struct Button *resume_butt);

int MakeMain(Renderer butt_render, Window window, struct Button continue_butt, struct Button new_game_butt, struct Button highscore_butt, struct Button credits_butt, struct Button exit_butt);

int MakeNewGame1(Renderer butt_render, Window window, struct Button single_player_butt, struct Button multi_player_butt, struct Button back_butt);

int MakeNewGame2(Renderer butt_render, Window window, struct Button back_butt);

int MakeHighscores(Renderer butt_render, Window window, struct Button back_butt, int *option);

int MakeInstructions(Renderer butt_render, Window window, struct Button back_butt);

int MakeCredits(Renderer butt_render, Window window, struct Button back_butt, Texture credits);

int PausedMenu1(Renderer render, struct Button exit_butt, struct Button save_game_butt, Texture pause_menu, struct Button resume_butt);

int PausedMenu2(Renderer render, struct Button exit_butt, Texture pause_menu, struct Button resume_butt);

int MakeNewGame(Renderer butt_render, struct Button back_butt, struct Button easy_butt, struct Button medium_butt, struct Button hard_butt, Texture texture);

int CheckIfHover(SDL_Rect position);


#endif

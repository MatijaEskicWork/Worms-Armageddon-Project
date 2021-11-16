#include <SDL.h>
#include <SDL_image.h>
#include "makingMenu.h"
#include "typesShorter.h"
#include "initCreate.h"
#include <stdlib.h>
#include "highScores.h"
#include <string.h>
#include <SDL_ttf.h>
/*!    \file makingMenu.c
*      \brief Contains making menus for game and function definitions	
*/

/*!	\brief Checks if mouse has hovered button
*	\param postion of button
*/
int CheckIfHover(SDL_Rect position) {
	int mouse_x = 0;
	int mouse_y = 0;
	SDL_GetMouseState(&mouse_x, &mouse_y);
	if (position.x <= mouse_x && position.x + position.w >= mouse_x && position.y <= mouse_y && position.y + position.h >= mouse_y) return 1;
	return 0;
}


/*!	\brief Function used for initializing every used button
*	\param all buttons
*/
void InitEverything(Renderer butt_render, struct Button *continue_butt, struct Button * new_game_butt, struct Button *highscore_butt, struct Button *credits_butt, struct Button *exit_butt, struct Button *single_player_butt, struct Button *multi_player_butt, struct Button *back_butt, SDL_Rect *credits_rect, Texture credits, struct Button *exit_pause_butt, struct Button *save_game_butt, Texture pause_menu, struct Button *demo_butt, struct Button *easy_butt, struct Button *medium_butt, struct Button *hard_butt, struct Button *resume_butt) {


	*new_game_butt = InitButton(0, 450, 50, 287, 51);
	new_game_butt->texture = InitCreateTexture(new_game_butt->texture, 0, "Resources/Butts/OrangePlay.png", butt_render, NULL, NULL);
	new_game_butt->hov_tex = InitCreateTexture(new_game_butt->hov_tex, 0, "Resources/Butts/BluePlay.png", butt_render, NULL, NULL);
	
	*continue_butt = InitButton(0, 450, 120, 287, 51);
	continue_butt->texture = InitCreateTexture(continue_butt->texture, 0, "Resources/Butts/OrangeContinue.png", butt_render, NULL, NULL);
	continue_butt->hov_tex = InitCreateTexture(continue_butt->hov_tex, 0, "Resources/Butts/BlueContinue.png", butt_render, NULL, NULL);

	*highscore_butt = InitButton(0, 450, 190, 281, 51);
	highscore_butt->texture = InitCreateTexture(highscore_butt->texture, 0, "Resources/Butts/OrangeHighscores.png", butt_render, NULL, NULL);
	highscore_butt->hov_tex = InitCreateTexture(highscore_butt->hov_tex, 0, "Resources/Butts/BlueHighscores.png", butt_render, NULL, NULL);

	*demo_butt = InitButton(0, 450, 260, 287, 51);
	demo_butt->texture = InitCreateTexture(demo_butt->texture, 0, "Resources/Butts/OrangeDemo.png", butt_render, NULL, NULL);
	demo_butt->hov_tex = InitCreateTexture(demo_butt->hov_tex, 0, "Resources/Butts/BlueDemo.png", butt_render, NULL, NULL);

	*credits_butt = InitButton(0, 450, 330, 287, 51);
	credits_butt->texture = InitCreateTexture(credits_butt->texture, 0, "Resources/Butts/OrangeCredits.png", butt_render, NULL, NULL);
	credits_butt->hov_tex = InitCreateTexture(credits_butt->hov_tex, 0, "Resources/Butts/BlueCredits.png", butt_render, NULL, NULL);

	*exit_butt = InitButton(0, 450, 400, 287, 51);
	exit_butt->texture = InitCreateTexture(exit_butt->texture, 0, "Resources/Butts/OrangeExit.png", butt_render, NULL, NULL);
	exit_butt->hov_tex = InitCreateTexture(exit_butt->hov_tex, 0, "Resources/Butts/BlueExit.png", butt_render, NULL, NULL);

	*single_player_butt = InitButton(0, 263, 280, 287, 51);
	single_player_butt->texture = InitCreateTexture(single_player_butt->texture, 0, "Resources/Butts/OrangeSingleplayer.png", butt_render, NULL, NULL);
	single_player_butt->hov_tex = InitCreateTexture(single_player_butt->hov_tex, 0, "Resources/Butts/BlueSingleplayer.png", butt_render, NULL, NULL);

	*multi_player_butt = InitButton(0, 550, 280, 287, 51);
	multi_player_butt->texture = InitCreateTexture(multi_player_butt->texture, 0, "Resources/Butts/OrangeMultiplayer.png", butt_render, NULL, NULL);
	multi_player_butt->hov_tex = InitCreateTexture(multi_player_butt->hov_tex, 0, "Resources/Butts/BlueMultiplayer.png", butt_render, NULL, NULL);

	*back_butt = InitButton(0, 60, 550, 50, 50);
	back_butt->texture = InitCreateTexture(back_butt->texture, 0, "Resources/BackButt/Back.png", butt_render, NULL, NULL);
	back_butt->hov_tex = NULL;

	*exit_pause_butt = InitButton(0, 400, 380, 287, 51);
	exit_pause_butt->texture = InitCreateTexture(exit_pause_butt->texture, 0, "Resources/Butts/OrangeExit.png", butt_render, NULL, NULL);
	exit_pause_butt->hov_tex = InitCreateTexture(exit_pause_butt->hov_tex, 0, "Resources/Butts/BlueExit.png", butt_render, NULL, NULL);

	*save_game_butt = InitButton(0, 400, 310, 287, 51);
	save_game_butt->texture = InitCreateTexture(exit_pause_butt->texture, 0, "Resources/Butts/OrangeSaveGame.png", butt_render, NULL, NULL);
	save_game_butt->hov_tex = InitCreateTexture(exit_pause_butt->hov_tex, 0, "Resources/Butts/BlueSaveGame.png", butt_render, NULL, NULL);

	pause_menu = InitCreateTexture(pause_menu, 0, "Resources/Butts/PauseMenu.png", butt_render, NULL, NULL);

	*easy_butt = InitButton(0, 450, 200, 287, 51);
	easy_butt->texture = InitCreateTexture(easy_butt->texture, 0, "Resources/Butts/OrangeEasy.png", butt_render, NULL, NULL);
	easy_butt->hov_tex = InitCreateTexture(easy_butt->hov_tex, 0, "Resources/Butts/BlueEasy.png", butt_render, NULL, NULL);
	
	*medium_butt = InitButton(0, 450, 330, 287, 51);
	medium_butt->texture = InitCreateTexture(medium_butt->texture, 0, "Resources/Butts/OrangeMedium.png", butt_render, NULL, NULL);
	medium_butt->hov_tex = InitCreateTexture(medium_butt->hov_tex, 0, "Resources/Butts/BlueMedium.png", butt_render, NULL, NULL);
	
	*hard_butt = InitButton(0, 450, 460, 287, 51);
	hard_butt->texture = InitCreateTexture(hard_butt->texture, 0, "Resources/Butts/OrangeHard.png", butt_render, NULL, NULL);
	hard_butt->hov_tex = InitCreateTexture(hard_butt->hov_tex, 0, "Resources/Butts/BlueHard.png", butt_render, NULL, NULL);

	*resume_butt = InitButton(0, 400, 240, 287, 51);
	resume_butt->texture = InitCreateTexture(resume_butt->texture, 0, "Resources/Butts/OrangeResume.png", butt_render, NULL, NULL);
	resume_butt->hov_tex = InitCreateTexture(resume_butt->hov_tex, 0, "Resources/Butts/BlueResume.png", butt_render, NULL, NULL);

}

/*!	\brief Function used for creating and drawing main menu on screen
*	\param buttons used in main menu
*/
int MakeMain(Renderer butt_render, Window window, struct Button continue_butt, struct Button new_game_butt, struct Button highscore_butt, struct Button credits_butt, struct Button exit_butt, struct Button demo_butt) { //1
	
	new_game_butt.hovered = CheckIfHover(new_game_butt.pos);
	SDL_RenderCopy(butt_render, new_game_butt.texture, NULL, &new_game_butt.pos);
	if (new_game_butt.hovered) {
		SDL_RenderCopy(butt_render, new_game_butt.hov_tex, NULL, &new_game_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
			return 1;
		}
	}

	continue_butt.hovered = CheckIfHover(continue_butt.pos);
	SDL_RenderCopy(butt_render, continue_butt.texture, NULL, &continue_butt.pos);
	if (continue_butt.hovered) {
		SDL_RenderCopy(butt_render, continue_butt.hov_tex, NULL, &continue_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			return 2;
		}
	}

	highscore_butt.hovered = CheckIfHover(highscore_butt.pos);
	SDL_RenderCopy(butt_render, highscore_butt.texture, NULL, &highscore_butt.pos);
	if (highscore_butt.hovered) {
		SDL_RenderCopy(butt_render, highscore_butt.hov_tex, NULL, &highscore_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			return 3;
		}
	}
	
	credits_butt.hovered = CheckIfHover(credits_butt.pos);
	SDL_RenderCopy(butt_render, credits_butt.texture, NULL, &credits_butt.pos);
	if (credits_butt.hovered) {
		SDL_RenderCopy(butt_render, credits_butt.hov_tex, NULL, &credits_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			return 5;
		}
	}
	
	exit_butt.hovered = CheckIfHover(exit_butt.pos);
	SDL_RenderCopy(butt_render, exit_butt.texture, NULL, &exit_butt.pos);
	if (exit_butt.hovered) {
		SDL_RenderCopy(butt_render, exit_butt.hov_tex, NULL, &exit_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			return 6;
		}
	}

	demo_butt.hovered = CheckIfHover(demo_butt.pos);
	SDL_RenderCopy(butt_render, demo_butt.texture, NULL, &demo_butt.pos);
	if (demo_butt.hovered) {
		SDL_RenderCopy(butt_render, demo_butt.hov_tex, NULL, &demo_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			return 9;
		}
	}

	SDL_RenderPresent(butt_render);
	return 0;
}

/*!	\brief Function used for checking which button is hovered in play menu
*	\param render
*	\param widnow
*	\param buttons used in play menu
*/
int MakeNewGame1(Renderer butt_render, Window window, struct Button single_player_butt, struct Button multi_player_butt, struct Button back_butt) { //2 
	int ret_value = 1;
	single_player_butt.hovered = CheckIfHover(single_player_butt.pos);
	SDL_RenderCopy(butt_render, single_player_butt.texture, NULL, &single_player_butt.pos);
	if (single_player_butt.hovered) {
		SDL_RenderCopy(butt_render, single_player_butt.hov_tex, NULL, &single_player_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			ret_value = 7;
		}
	}

	multi_player_butt.hovered = CheckIfHover(multi_player_butt.pos);
	SDL_RenderCopy(butt_render, multi_player_butt.texture, NULL, &multi_player_butt.pos);
	if (multi_player_butt.hovered) {
		SDL_RenderCopy(butt_render, multi_player_butt.hov_tex, NULL, &multi_player_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			ret_value = 8;
		}
	}

	back_butt.hovered = CheckIfHover(back_butt.pos);
	SDL_RenderCopy(butt_render, back_butt.texture, NULL, &back_butt.pos);
	if (back_butt.hovered) {
		SDL_RenderCopy(butt_render, back_butt.hov_tex, NULL, &back_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			ret_value = 0;
		}
	}
	SDL_RenderPresent(butt_render);
	return ret_value;
}

/*!	\brief Cheking if going back to previous menu
*	\param render
*	\param window	
*	\param back_button
*/
int MakeNewGame2(Renderer butt_render, Window window, struct Button back_butt){ //3
	back_butt.hovered = CheckIfHover(back_butt.pos);
	SDL_RenderCopy(butt_render, back_butt.texture, NULL, &back_butt.pos);
	if (back_butt.hovered) {
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			return 0;
		}
	}
	SDL_RenderPresent(butt_render);
	return 7;
}

/*!	\brief Function used for reading higschores and creating HighScores window
*	\param render
*	\param window
*	\param back button
*	\param option
*/
int MakeHighscores(Renderer butt_render, Window window, struct Button back_butt, int *option) {

	if ( *option == 0) {
	HighScoreList lista = ReadHighScores();

	char score1[35], score2[35], score3[35], score4[35], score5[35];

	_itoa(lista.list[0].score, score1, 10);
	_itoa(lista.list[1].score, score2, 10);
	_itoa(lista.list[2].score, score3, 10);
	_itoa(lista.list[3].score, score4, 10);
	_itoa(lista.list[4].score, score5, 10);

	Texture font1_texture = NULL;
	Texture font2_texture = NULL;
	Texture font3_texture = NULL;
	Texture font4_texture = NULL;
	Texture font5_texture = NULL;
	Texture font6_texture = NULL;
	Texture font7_texture = NULL;
	Texture font8_texture = NULL;
	Texture font9_texture = NULL;
	Texture font10_texture = NULL;
	Texture font11_texture = NULL;
	Texture font12_texture = NULL;
	Texture font13_texture = NULL;
	Texture font14_texture = NULL;
	Texture font15_texture = NULL;

	SDL_Color text_color = { 0,0,0 };
	TTF_Font* font = TTF_OpenFont("Resources/Font/BROADW.ttf", 40);
	char num1[3], num2[3], num3[3], num4[3], num5[3];

	strcpy(num1, "1.");
	strcpy(num2, "2.");
	strcpy(num3, "3.");
	strcpy(num4, "4.");
	strcpy(num5, "5.");


	SDL_Surface* surf1 = TTF_RenderText_Solid(font, num1, text_color);
	font10_texture = SDL_CreateTextureFromSurface(butt_render, surf1);
	SDL_Rect dest1 = { 300, 200, surf1->w, surf1->h };
	SDL_RenderCopy(butt_render, font10_texture, NULL, &dest1);

	SDL_Surface* surf2 = TTF_RenderText_Solid(font, num2, text_color);
	font11_texture = SDL_CreateTextureFromSurface(butt_render, surf2);
	SDL_Rect dest2 = { 300, 250, surf2->w, surf2->h };
	SDL_RenderCopy(butt_render, font11_texture, NULL, &dest2);

	SDL_Surface* surf3 = TTF_RenderText_Solid(font, num3, text_color);
	font12_texture = SDL_CreateTextureFromSurface(butt_render, surf3);
	SDL_Rect dest3 = { 300, 300, surf3->w, surf3->h };
	SDL_RenderCopy(butt_render, font12_texture, NULL, &dest3);

	SDL_Surface* surf4 = TTF_RenderText_Solid(font, num4, text_color);
	font13_texture = SDL_CreateTextureFromSurface(butt_render, surf4);
	SDL_Rect dest4 = { 300, 350, surf4->w, surf4->h };
	SDL_RenderCopy(butt_render, font13_texture, NULL, &dest4);

	SDL_Surface* surf5 = TTF_RenderText_Solid(font, num5, text_color);
	font14_texture = SDL_CreateTextureFromSurface(butt_render, surf5);
	SDL_Rect dest5 = { 300, 400, surf5->w, surf5->h };
	SDL_RenderCopy(butt_render, font14_texture, NULL, &dest5);

	SDL_Surface* text1_surface = TTF_RenderText_Solid(font, lista.list[0].name, text_color);
	font1_texture = SDL_CreateTextureFromSurface(butt_render, text1_surface);
	SDL_Rect dst1 = { 350, 200, text1_surface->w, text1_surface->h };
	SDL_RenderCopy(butt_render, font1_texture, NULL, &dst1);

	SDL_Surface* text2_surface = TTF_RenderText_Solid(font, score1, text_color);
	font2_texture = SDL_CreateTextureFromSurface(butt_render, text2_surface);
	SDL_Rect dst2 = { 1050, 200, text2_surface->w, text2_surface->h };
	SDL_RenderCopy(butt_render, font2_texture, NULL, &dst2);

	SDL_Surface* text3_surface = TTF_RenderText_Solid(font, lista.list[1].name, text_color);
	font3_texture = SDL_CreateTextureFromSurface(butt_render, text3_surface);
	SDL_Rect dst3 = { 350, 250 , text3_surface->w, text3_surface->h };
	SDL_RenderCopy(butt_render, font3_texture, NULL, &dst3);

	SDL_Surface* text4_surface = TTF_RenderText_Solid(font, score2, text_color);
	font4_texture = SDL_CreateTextureFromSurface(butt_render, text4_surface);
	SDL_Rect dst4 = { 1050, 250, text4_surface->w, text4_surface->h };
	SDL_RenderCopy(butt_render, font4_texture, NULL, &dst4);

	SDL_Surface* text5_surface = TTF_RenderText_Solid(font, lista.list[2].name, text_color);
	font5_texture = SDL_CreateTextureFromSurface(butt_render, text5_surface);
	SDL_Rect dst5 = { 350, 300, text5_surface->w, text5_surface->h };
	SDL_RenderCopy(butt_render, font5_texture, NULL, &dst5);

	SDL_Surface* text6_surface = TTF_RenderText_Solid(font, score3, text_color);
	font6_texture = SDL_CreateTextureFromSurface(butt_render, text6_surface);
	SDL_Rect dst6 = { 1050, 300, text6_surface->w, text6_surface->h };
	SDL_RenderCopy(butt_render, font6_texture, NULL, &dst6);

	SDL_Surface* text7_surface = TTF_RenderText_Solid(font, lista.list[3].name, text_color);
	font7_texture = SDL_CreateTextureFromSurface(butt_render, text7_surface);
	SDL_Rect dst7 = { 350, 350, text7_surface->w, text7_surface->h };
	SDL_RenderCopy(butt_render, font7_texture, NULL, &dst7);

	SDL_Surface* text8_surface = TTF_RenderText_Solid(font, score4, text_color);
	font8_texture = SDL_CreateTextureFromSurface(butt_render, text8_surface);
	SDL_Rect dst8 = { 1050, 350, text8_surface->w, text8_surface->h };
	SDL_RenderCopy(butt_render, font8_texture, NULL, &dst8);

	SDL_Surface* text9_surface = TTF_RenderText_Solid(font, lista.list[4].name, text_color);
	font9_texture = SDL_CreateTextureFromSurface(butt_render, text9_surface);
	SDL_Rect dst9 = { 350, 400, text9_surface->w, text9_surface->h };
	SDL_RenderCopy(butt_render, font9_texture, NULL, &dst9);

	SDL_Surface* text10_surface = TTF_RenderText_Solid(font, score5, text_color);
	font10_texture = SDL_CreateTextureFromSurface(butt_render, text10_surface);
	SDL_Rect dst10 = { 1050, 400, text10_surface->w, text10_surface->h };
	SDL_RenderCopy(butt_render, font10_texture, NULL, &dst10);
	option = 1;
	}
	if (option) {
		back_butt.hovered = CheckIfHover(back_butt.pos);
		SDL_RenderCopy(butt_render, back_butt.texture, NULL, &back_butt.pos);
		if (back_butt.hovered) {
			if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
				return 0;
			}
		}
	}
	SDL_RenderPresent(butt_render);
	return 3;
}

/*!	\brief Used for making instructiong menu
*	\param render
*	\param window
*	\param back button
*/
int MakeInstructions(Renderer butt_render, Window window , struct Button back_butt) { //4
	back_butt.hovered = CheckIfHover(back_butt.pos);
	SDL_RenderCopy(butt_render, back_butt.texture, NULL, &back_butt.pos);
	if (back_butt.hovered) {
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			return 0;
		}
	}
	SDL_RenderPresent(butt_render);
	return 4;
}

/*!	\brief used for making credits 
*	\param render
*	\param window
*	\param back button	
*	\param credits texture
*/
int MakeCredits(Renderer butt_render, Window window, struct Button back_butt, Texture credits) { //5

	SDL_RenderCopy(butt_render, credits, NULL, NULL);
	
	back_butt.hovered = CheckIfHover(back_butt.pos);
	SDL_RenderCopy(butt_render, back_butt.texture, NULL, &back_butt.pos);
	if (back_butt.hovered) {
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			return 0;
		}
	}
	SDL_RenderPresent(butt_render);
	return 5;
}

/*!	\brief Function used for creaing pause menu for singleplayer
*	\param render
*	\param exit button
*	\param save game button
*	\param texture
*	\param resume button
*/
int PausedMenu1(Renderer render, struct Button exit_butt, struct Button save_game_butt, Texture pause_menu, struct Button resume_butt) {
	SDL_Rect pause_rect; 
	pause_rect.x = 350;
	pause_rect.y = 200;
	pause_rect.w = 400;
	pause_rect.h = 300;
	int ret_val = 1;

	/*exit_butt = InitButton(0, 400, 380, 287, 51);
	exit_butt.texture = InitCreateTexture(exit_pause_butt.texture, 0, "Resources/Butts/OrangeExit.png", render, NULL, NULL);
	exit_butt.hov_tex = InitCreateTexture(exit_pause_butt.hov_tex, 0, "Resources/Butts/BlueExit.png", render, NULL, NULL);

	save_game_butt = InitButton(0, 400, 310, 287, 51);
	save_game_butt.texture = InitCreateTexture(exit_pause_butt.texture, 0, "Resources/Butts/OrangeSaveGame.png", render, NULL, NULL);
	save_game_butt.hov_tex = InitCreateTexture(exit_pause_butt.hov_tex, 0, "Resources/Butts/BlueSaveGame.png", render, NULL, NULL);

	pause_menu = InitCreateTexture(pause_menu, 0, "Resources/Butts/PauseMenu.png", render, NULL, NULL);*/


	SDL_RenderCopy(render, pause_menu, NULL, &pause_rect);


	exit_butt.hovered = CheckIfHover(exit_butt.pos);
	SDL_RenderCopy(render, exit_butt.texture, NULL, &exit_butt.pos);
	if (exit_butt.hovered) {
		SDL_RenderCopy(render, exit_butt.hov_tex, NULL, &exit_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			ret_val = 2;
			SDL_Delay(50);
		}
	}

	save_game_butt.hovered = CheckIfHover(save_game_butt.pos);
	SDL_RenderCopy(render, save_game_butt.texture, NULL, &save_game_butt.pos);
	if (save_game_butt.hovered) {
		SDL_RenderCopy(render, save_game_butt.hov_tex, NULL, &save_game_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			ret_val = 3;
			SDL_Delay(50);
		}
	}

	resume_butt.hovered = CheckIfHover(resume_butt.pos);
	SDL_RenderCopy(render, resume_butt.texture, NULL, &resume_butt.pos);
	if (resume_butt.hovered) {
		SDL_RenderCopy(render, resume_butt.hov_tex, NULL, &resume_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			ret_val = 10;
			SDL_Delay(50);
		}
	}

	SDL_RenderPresent(render);
	return ret_val;
	
}

/*!	\brief Function used for creaing pause menu for demo
*	\param render
*	\param exit button
*	\param texture
*	\param resume button
*/
int PausedMenu2(Renderer render, struct Button exit_butt, Texture pause_menu, struct Button resume_butt) {
	SDL_Rect pause_rect;
	pause_rect.x = 350;
	pause_rect.y = 200;
	pause_rect.w = 400;
	pause_rect.h = 300;
	int ret_val = 1;

	/*exit_butt = InitButton(0, 400, 380, 287, 51);
	exit_butt.texture = InitCreateTexture(exit_pause_butt.texture, 0, "Resources/Butts/OrangeExit.png", render, NULL, NULL);
	exit_butt.hov_tex = InitCreateTexture(exit_pause_butt.hov_tex, 0, "Resources/Butts/BlueExit.png", render, NULL, NULL);

	save_game_butt = InitButton(0, 400, 310, 287, 51);
	save_game_butt.texture = InitCreateTexture(exit_pause_butt.texture, 0, "Resources/Butts/OrangeSaveGame.png", render, NULL, NULL);
	save_game_butt.hov_tex = InitCreateTexture(exit_pause_butt.hov_tex, 0, "Resources/Butts/BlueSaveGame.png", render, NULL, NULL);

	pause_menu = InitCreateTexture(pause_menu, 0, "Resources/Butts/PauseMenu.png", render, NULL, NULL);*/


	SDL_RenderCopy(render, pause_menu, NULL, &pause_rect);

	exit_butt.pos.y = 350;
	exit_butt.hovered = CheckIfHover(exit_butt.pos);
	SDL_RenderCopy(render, exit_butt.texture, NULL, &exit_butt.pos);
	if (exit_butt.hovered) {
		SDL_RenderCopy(render, exit_butt.hov_tex, NULL, &exit_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			ret_val = 2;
			SDL_Delay(50);
		}
	}

	resume_butt.pos.y = 270;

	resume_butt.hovered = CheckIfHover(resume_butt.pos);
	SDL_RenderCopy(render, resume_butt.texture, NULL, &resume_butt.pos);
	if (resume_butt.hovered) {
		SDL_RenderCopy(render, resume_butt.hov_tex, NULL, &resume_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			ret_val = 10;
			SDL_Delay(50);
		}
	}

	SDL_RenderPresent(render);
	return ret_val;


}

/*!	\brief Function used for creaing new game menu
*	\param render
*	\param back button
*	\param easy button
*	\param medium button
*	\param hard button
*	\param texture
*/
int MakeNewGame(Renderer butt_render, struct Button back_butt, struct Button easy_butt, struct Button medium_butt, struct Button hard_butt, Texture texture) {
	int ret_val = 7;

	SDL_RenderCopy(butt_render, texture, NULL, NULL);

	back_butt.hovered = CheckIfHover(back_butt.pos);
	SDL_RenderCopy(butt_render, back_butt.texture, NULL, &back_butt.pos);
	if (back_butt.hovered) {
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			SDL_Delay(85);
			ret_val = 1;
		}
	}

	easy_butt.hovered = CheckIfHover(easy_butt.pos);
	SDL_RenderCopy(butt_render, easy_butt.texture, NULL, &easy_butt.pos);
	if (easy_butt.hovered) {
		SDL_RenderCopy(butt_render, easy_butt.hov_tex, NULL, &easy_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			ret_val = 10;
		}
	}

	medium_butt.hovered = CheckIfHover(medium_butt.pos);
	SDL_RenderCopy(butt_render, medium_butt.texture, NULL, &medium_butt.pos);
	if (medium_butt.hovered) {
		SDL_RenderCopy(butt_render, medium_butt.hov_tex, NULL, &medium_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			ret_val = 11;
		}
	}

	hard_butt.hovered = CheckIfHover(hard_butt.pos);
	SDL_RenderCopy(butt_render, hard_butt.texture, NULL, &hard_butt.pos);
	if (hard_butt.hovered) {
		SDL_RenderCopy(butt_render, hard_butt.hov_tex, NULL, &hard_butt.pos);
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
			ret_val = 12;
		}
	}



	SDL_RenderPresent(butt_render);
	return ret_val;
}




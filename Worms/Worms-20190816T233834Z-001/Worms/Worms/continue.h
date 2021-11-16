#ifndef _continueGame_h_
#define _continueGame_h_
#include "Worm.h"
#include "map.h"
#include "game.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include "gameMode.h"
#include "initCreate.h"
#include "typesShorter.h"
#include "makingMenu.h"
/*!	\file continue.h
*	\brief Contains structures and function definitions needed for continuing ganme
*/

/*!	\brief structure containing all information which have to be saved in file for missile
*	\param pos
*	\param angle for shooting
*	\param vx and vy velocity
*	\param bool if fired
*/
typedef struct
{
	SDL_Rect pos;
	double angle;
	double vx, vy;
	int fired;
} SavedMissile;

/*!	\brief Structure used to store all information which had to be saved in file in order to continue game and draw worm in continued game
*/
typedef struct
{
	int health;
	SDL_Rect bazooka_flip_rect;
	SDL_Rect pos;
	SDL_Rect bazooka_rect;
	SDL_Rect aim_rect;
	SDL_Rect power_bar_rect;
	SDL_Rect start_power_bar_rect;
	SDL_Rect marker_rect;
	long double vx;
	long double vy;
	int is_stable;
	int rotate;
	int bazooka_state;
	int power;
	int score;
	int coeff;
	double dt;
	SavedMissile missile;
}SavedWorm;

/*!	\brief Structure containing saved map and worms
*/
typedef struct {
	int height[1200]; // Map height
	//
	SavedWorm worm1, worm2;
}SavedGame; 



void SaveGame(struct Worm *worm1, struct Worm *worm2, struct Map *map);

int ContinueGame(struct Worm **worm1, struct  Worm **worm2, struct Map **map);



#endif

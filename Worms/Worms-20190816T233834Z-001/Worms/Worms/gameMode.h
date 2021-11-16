#ifndef _gameMode_h_
#define _gameMode_h_
#include "typesShorter.h"
#include "Worm.h"
#include "map.h"
/*	\file gameMode.h
*	\brief Contains definitions of functions used in ganmeMode.c
*/

int MultiplayerMode(struct Worm *worm_1, struct Worm *worm_2, struct Map map, Renderer render, Window window);

void DrawHealthBar(Texture texture, Texture abs_texture, int x_pos, int y_pos, int health, Renderer render);

void DrawMarker(Renderer render, struct Worm *worm, struct Map map);

int SingleplayerMode(struct Worm *worm_1, struct Worm *worm_2, struct Map map, Renderer render, Window window, int game_mode);

int DemoMode(struct Worm *worm_1, struct Worm *worm_2, struct Map map, Renderer render, Window window);

int ContinueGame1(struct Worm *worm1, struct Worm *worm2, struct Map *map, Renderer render, Window window);

//void DrawScoreBar(Texture texture, Texture abs_texture, int x_pos, int y_pos, int health, Renderer render);

struct Worm Reset(struct Worm worm);

int Highscores(struct Worm worm, Renderer render, int *option);

void Resume(struct Worm *worm1, struct Worm *worm2, struct Map *map, Renderer render);


#endif

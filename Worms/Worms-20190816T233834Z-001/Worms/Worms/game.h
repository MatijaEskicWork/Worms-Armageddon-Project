#ifndef _game_h_
#define _game_h_
#include "map.h"
#include "initCreate.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Worm.h"
#include "typesShorter.h"

#define g 10
#define alfa 0.71
/*!	\file game.h 
*	\brief Contains definitions of all functions written and used in game.c
*/



void MoveLeft(struct Worm *worm, struct Map map, Renderer render, long double dT, struct Worm *wormx);

void MoveRight(struct Worm *worm, struct Map map, Renderer render, long double dT, struct Worm *wormx);

int HandlePressedKey1(SDL_Keysym *keysym, Renderer render, struct Worm *worm, struct Map *map, struct Worm *wormx);

int HandlePressedKey2(SDL_Keysym *keysym, Renderer render, struct Worm *worm, struct Map *map, struct Worm *wormx);

//void Jump(struct Worm* worm, struct Map map, Renderer render);

struct Worm UpdateWormMove(struct Map map, struct Worm worm, Renderer render, SDL_Rect curr_pos, struct Worm *wormx);

struct Worm MoveBazookaAim(struct Map map, Renderer worm_render, struct Worm worm, int add_sub, struct Worm *wormx);

struct Worm MissileFlight(struct Map *map, Renderer render, struct Worm worm, int rot_speed, struct Worm *wormx);

int MapMissileCollision(SDL_Rect missile_pos, struct Map map, struct Worm *wormx);

struct Worm PrepareFire(struct Map *map, Renderer worm_render, struct Worm worm, struct Worm *wormx);

struct Map DestructiveMap(struct Map map, SDL_Rect center, Renderer render, struct Worm *worm, struct Worm *wormx);

int MissileWormCollision(struct Worm worm, struct Worm wormx);

int CheckBounds(SDL_Rect position, int x_coord, int choice);

struct Worm Firee(struct Map *map, Renderer render, struct Worm worm, struct Worm *wormx);

void HandleReleasedKey1(SDL_Keysym *keysym, Renderer render, struct Worm *worm, struct Map *map, struct Worm *wormx);

void HandleReleasedKey2(SDL_Keysym *keysym, Renderer render, struct Worm *worm, struct Map *map, struct Worm *wormx);

struct Worm AIFiree(struct Map *map, Renderer render, struct Worm worm, struct Worm *wormx);

void Resume(struct Worm *worm1, struct Worm *worm2, struct Map *map, Renderer render);

//void DrawCredits()

#endif
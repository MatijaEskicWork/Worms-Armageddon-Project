#ifndef _Worm_h_
#define _Worm_h_
#include <SDL.h>
#include "typesShorter.h"
#include "SDL_ttf.h"
#define FIRST_MAX 500
#define SECOND_MAX 700
#define FIRST_MIN 70
#define SECOND_MIN 1100
/*! \file Worm.h
*	\brief Containts declarations of Worm and Missile structure as well as funcions used for them
*/

/*!
*	\brief Structure used for missile
*	\param pos has position of rectangle used for representig missile
*	\param angle is angle for firing
*	\param velocity on x axis
*	\param velocity on y axis
*	\param texture
*	\param bool, 1 if missile is fired, 0 otherwise
*/
struct Missile {
	SDL_Rect pos;
	double angle;
	double vx, vy;
	Texture texture[2];
	int fired;
};

/*!
*	\brief Structure used for worm, contains it's name and health, velocity on x and y axis, bool if it's stable(1 if not moving, 0 otherwise), bool rotate (1 if rotated right, 0 otherwise
*	\state of bazooka, power for firing missile, score, current coeffitient for score, time dt, missile structure and all rects and textures needed for worm
*/
struct Worm {
	TTF_Font *font;
	char name[20];
	int health;
	SDL_Rect bazooka_flip_rect;
	SDL_Rect pos;
	SDL_Rect bazooka_rect;
	SDL_Rect aim_rect;
	SDL_Rect power_bar_rect;
	SDL_Rect start_power_bar_rect;
	SDL_Rect marker_rect;
	SDL_Texture *texture[2];
	SDL_Texture *bazooka_tex[2];
	SDL_Texture *aim_tex;
	SDL_Texture *power_bar_tex;
	SDL_Texture *start_power_bar_tex;
	SDL_Texture *marker;
	struct Missile missile;
	long double vx;
	long double vy;
	int is_stable;
	int rotate;
	int bazooka_state;
	int power;
	int score;
	int coeff;
	double dt;

};

extern struct Worm worm1;
extern struct Worm worm2;

struct Worm InitWorm(int health, int x, int y, int h, int w, char img_directory[], long double vx, long double vy, int);

int WormCollision(struct Worm worm1, struct Worm worm2);

int	RangeIntersect(int minA, int maxA, int minB, int maxB);

int WormMapCollision(struct Worm worm, int posX, int posY);

int max1(int a, int b);

int min1(int a, int b);

struct Worm DrawBazooka(struct Map map, Renderer worm_render, struct Worm worm, int state);

struct Worm CreateWorm(Renderer worm_render, Window window, int rotate, int x, int y, int h, int w);

#endif
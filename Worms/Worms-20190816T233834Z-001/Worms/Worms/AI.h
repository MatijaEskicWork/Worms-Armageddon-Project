#ifndef _AI_h_
#define _AI_h_
#include "typesShorter.h"
#include <SDL.h>
#include "Worm.h"
#include "game.h"
#include "map.h"
#include <time.h>
#define MAX_POWER 50
#define MAX_POWER_AI 35
#define G 10
#define EASY_DISTANCE 100
#define MED_DISTANCE 50
#define HARD_DISTANCE 20
/*!	\file AI.h
*	\brief Contains definitions of functions used in ai.c
*/

int Worm1Right(struct Worm *worm1, struct Worm worm2);

int InRange(struct Worm *worm1, struct Worm worm2);

float FindAngle(int worm1x, int worm1y, int worm2x, int worm2y, int option);

struct Worm* AIDecision(struct Worm *worm1, struct Worm worm2, struct Map map, Renderer render, int mode);

int InSafeZone(struct Worm *worm1, struct Worm worm2, int mode);


#endif // !_AI_h_


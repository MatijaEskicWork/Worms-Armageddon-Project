#include "AI.h"
#include "Worm.h"
#include "game.h"
#include "map.h"
#include <math.h>
#include <time.h>

/*!    \file AI.c
*      \brief Contains functions used for simulating worm ai
*/

/*!
*   \brief Checking if worm1 is positioned right to worm2 on map
*   \param First worm
*   \param Second worm
*/
int Worm1Right(struct Worm *worm1, struct Worm worm2)
{
	if (worm1->pos.x < worm2.pos.x)
		return 0;
	else 
		return 1;
}

/*!
*     \brief Checking if worm2 is in range of worm1's fire
*     \param First worm
*     \param Second worm
*/

int InRange(struct Worm *worm1, struct Worm worm2)
{
	worm1->power = MAX_POWER_AI;
	worm1->dt = 0.15;
	float v = 0.0,sqroot;
	int x, y;
	v = 2 * MAX_POWER_AI;
	x = abs(worm2.pos.x - worm1->pos.x);
	y = abs(worm2.pos.y - worm1->pos.y);
	sqroot = pow(v, 4) - G * (G*x*x + 2 * y*v*v);
	if (sqroot < 0)
		return 0;
	else
		return 1;
}
/*!
*     \brief Used for finding the right angle for worm1 to shoot worm2
*	  \param Worm1's x coordinate
*	  \param Worm1's y coordinate
*     \param Worm2's x coordinate
*     \param Worm2's y coordinate
*     \param Game mode (easy, medium, hard)
*/
float FindAngle(int worm1x, int worm1y, int worm2x, int worm2y, int option)
{
	float angle, v;
	int x, y;
	v = 2 * MAX_POWER_AI;
	x = abs(worm2x - worm1x);
	y = abs(worm2y - worm1y);
	float sqroot = pow(v, 4) - G * (G*x*x + 2 * y*v*v);
	printf("sqroot : %f\n", sqroot);
	sqroot = sqrt(abs(sqroot));
	printf("sqroot posle korenovanja : %f\n", sqroot);
	if (option)   //+
		angle = v * v + sqroot;
	else  //-
		angle = v * v - sqroot;
	angle = angle / (G * x);
	printf("Pre atan: %f\n", angle);
	angle = atan(angle);
	printf("Ugao: %f \n", angle);
		return angle;
} 

/*!
*	\brief Checking if worm1 can hurt himself because it's too close to worm2
*   \param First worm
*	\param Second worm
*	\param Game mode (easy, medium, hard)
*/
int InSafeZone(struct Worm *worm1, struct Worm worm2, int mode)
{
	switch (mode)
	{
	case 0:
	{
		if (abs(worm1->pos.x - worm2.pos.x) > EASY_DISTANCE)
			return 1;
	}
	break;
	case 1:
	{
		if (abs(worm1->pos.x - worm2.pos.x) > MED_DISTANCE)
			return 1;
	}
	break;
	case 2:
	{
		if (abs(worm1->pos.x - worm2.pos.x) > HARD_DISTANCE)
			return 1;
	}
	break;
	}
	return 0;
}

/*!
*	\brief Main AI function used for making decision what to do
*	\param First worm
*	\param Second worm
*	\param Map
*	\param Render, used for updating state on screen
*	\param Game mode (easy, medium, hard)
*/
struct Worm* AIDecision(struct Worm *worm1, struct Worm worm2, struct Map map, Renderer render, int mode)
{
	int distance, xwormAI, ywormAI, start_pos_x = worm1->pos.x, obstacle = 0, left;
	float anglemin, anglemax, temp;
	int rand_for_angle;

	while (!InRange(worm1, worm2) && obstacle == 0)
	{
		xwormAI = worm1->pos.x;
		if (Worm1Right(worm1, worm2)) {
			MoveLeft(worm1, map, render, 0, &worm2);
		}
		else MoveRight(worm1, map, render, 0, &worm2);
		if (worm1->pos.x == xwormAI)
		{
			obstacle = 1;
			ywormAI = worm1->pos.y - worm1->pos.h;
			while (worm1->pos.x != start_pos_x)
				if (start_pos_x < worm1->pos.x)
				{
					MoveLeft(worm1, map, render, 0, &worm2);
					left = 1;
				}
				else
				{
					MoveRight(worm1, map, render, 0, &worm2);
					left = 0;
				}
			if (left = 1)
			{
				MoveRight(worm1, map, render, 0, &worm2);
				MoveRight(worm1, map, render, 0, &worm2);
			}
			else
			{
				MoveLeft(worm1, map, render, 0, &worm2);
				MoveLeft(worm1, map, render, 0, &worm2);
			}
			anglemin = (float)(70 * 3.14159)/180;
		}
		else
			xwormAI = worm1->pos.x;
	}
	
	if (InRange(worm1, worm2)&& obstacle == 0)
	{
		srand(time(NULL));
		rand_for_angle = rand() % 2;
		//angle = FindAngle(worm1->pos.x, worm1->pos.y, worm2.pos.x, worm2.pos.y, rand_for_angle);
		switch (mode)
		{
		case 0:
		{
			anglemin = FindAngle(worm1->pos.x, worm1->pos.y, worm2.pos.x + worm2.pos.w / 2 - EASY_DISTANCE, worm2.pos.y, rand_for_angle);
			//anglemax = FindAngle(worm1->pos.x, worm1->pos.y, worm2.pos.x + worm2.pos.w/2 + EASY_DISTANCE, worm2.pos.y, rand_for_angle);
		}
			break;
		case 1:
		{
			anglemin = FindAngle(worm1->pos.x, worm1->pos.y, worm2.pos.x + worm2.pos.w / 2 - MED_DISTANCE, worm2.pos.y, rand_for_angle);
			//anglemax = FindAngle(worm1->pos.x, worm1->pos.y, worm2.pos.x + worm2.pos.w / 2 + MED_DISTANCE, worm2.pos.y, rand_for_angle);
		}
			break;
		case 2:
		{
			anglemin = FindAngle(worm1->pos.x, worm1->pos.y, worm2.pos.x + worm2.pos.w / 2 - HARD_DISTANCE, worm2.pos.y, rand_for_angle);
			//anglemax = FindAngle(worm1->pos.x, worm1->pos.y, worm2.pos.x + worm2.pos.w / 2 + HARD_DISTANCE, worm2.pos.y, rand_for_angle);
		}
			break;
		}
		/*if (anglemin > anglemax)
		{
			temp = anglemin;
			anglemin = anglemax;
			anglemax = anglemin;
		}*/
	 worm1->missile.angle = anglemin;
		
	}
	return worm1;
}
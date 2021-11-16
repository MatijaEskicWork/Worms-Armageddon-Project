#ifndef _map_h_
#define _map_h_
#include <stdlib.h>
#include "typesShorter.h"
#define MAX_HEIGHT 450
#define MIN_HEIGHT 10
/*! \file map.h
*	\brief Contains structure used for map and definition of CreateMap and UpdateMap functions
*/

/*!	\brief structure used for representing map
*	\param array of heights
*	\param map texture
*	\param sky texture
*	\param missile texture
*	\param array of positions
*	\param bool if map is created
*/
struct Map{
	int height[1200];
	Texture texture;
	Texture sky_tex;
	Texture bomb_tex;
	SDL_Rect pos[1200];
	int created;
};

//extern struct Map map;
struct Map CreateMap(Renderer render, Window window);

void UpdateMap(Renderer render);

#endif
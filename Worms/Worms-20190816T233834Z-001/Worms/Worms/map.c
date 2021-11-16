#include "map.h"
#include "typesShorter.h"
#include "SDL_image.h"
#include <time.h>
#include "initCreate.h"
/*!	\file map.c
*	\brief  contains all of the functions used for creating and updating map
*/

struct Map map;

/*!	\brief Function used for creating map and drawing it on secren
*	\param render
*	\param window
*/
struct Map CreateMap( Renderer render, Window window) {
	struct Map map;
	map.texture = NULL;
	map.bomb_tex = NULL;
	map.sky_tex = NULL;
	map.texture = InitCreateTexture(map.texture, 0, "Resources/AssetsForMap/Grass2.png", render, NULL, window);
	map.sky_tex = InitCreateTexture(map.sky_tex, 0, "Resources/AssetsForMap/Sky.png", render, NULL, window);
	map.bomb_tex = InitCreateTexture(map.bomb_tex, 0, "Resources/AssetsForMap/Bomb.png", render, NULL, window);
	SDL_RenderCopy(render, map.sky_tex, NULL, NULL);
	map.height[0] = 400;
	int low = 0;
	int high = 3;
	srand(time(NULL));
	int i, option;
	for (i = 1; i < 61; i++) {
		option = ((double) rand() / (RAND_MAX - 1)) * (high - low) + low;
		switch (option) {
		case 0: map.height[(i - 1) * 20 + 1] = map.height[(i - 1) * 20]; break;
		case 1: map.height[(i - 1) * 20 + 1] = map.height[(i - 1) * 20] + 1; break;
		case 2:	map.height[(i - 1) * 20 + 1] = map.height[(i - 1) * 20] - 1; option = -1; break;
		}
		int j;
		map.pos[(i - 1) * 20 + 1].x = (i - 1)*20 + 1;
		map.pos[(i - 1) * 20 + 1].y = 680 - map.height[(i - 1) * 20 + 1];
		map.pos[(i - 1) * 20 + 1].w = 1;
		map.pos[(i - 1) * 20 + 1].h = map.height[(i - 1) * 20 + 1];
		SDL_RenderCopy(render, map.texture, NULL, &map.pos[(i - 1) * 20 + 1]);
		for (j = 1; j < 21; j++) {
			if ((i - 1) * 20 + j + 1== 1200) break;
			if (map.height[(i - 1) * 20 + j] >= MAX_HEIGHT) option = -1;
			if (map.height[(i - 1) * 20 + j] <= MIN_HEIGHT) option = 1;
			map.height[(i - 1) * 20 + 1 + j] = map.height[(i - 1) * 20 + j] + option;
			
			map.pos[(i - 1) * 20 + 1 + j].x = (i - 1) * 20 + j;
			map.pos[(i - 1) * 20 + 1 + j].y = 680 - map.height[(i - 1) * 20 + 1 + j];
			map.pos[(i - 1) * 20 + 1 + j].w = 1;
			map.pos[(i - 1) * 20 + 1 + j].h = map.height[(i - 1) * 20 + 1 + j];
			SDL_RenderCopy(render, map.texture, NULL, &map.pos[(i - 1) * 20 + 1 + j]);
		}
	}

	map.pos[0].x = 0;
	map.pos[0].y = 680;
	map.pos[0].w = 1;
	map.pos[0].h = map.height[0];
	SDL_RenderCopy(render, map.texture, NULL, &map.pos[0]);
	SDL_RenderPresent(render);
	map.created = 1;
	return map;
}

/*!	\brief function used for updating map
*	\param render
*/
void UpdateMap(Renderer render) {
	/*extern struct Map map;
	int i;
	for (i = 0; i < 1200; i++) {
		map.pos[i].x = i;
		SDL_RenderCopy(render, map.texture, NULL, &map.pos[i]);
	}
	SDL_RenderPresent(render); */
}
#include "Worm.h"
#include "map.h"
#include "gameMode.h"
#include "continue.h"
#include <stdio.h>
#include <stdlib.h>
/*!	\file continue.c
*	\brief Contains all functions used to continue saved game
*/

const char *saved_file_name = "game.save";

/*!	\brief Function used to save current singleplayer game by storing all of the needed information into file
*	\param worm1
*	\param worm2
*	\param map
*/
void SaveGame(struct Worm *worm1, struct Worm *worm2, struct Map *map) {
	FILE *savedgame = fopen(saved_file_name, "wb");
	SavedGame game;
	for (int i = 0; i < Width; i++)
		game.height[i] = map->height[i];
	game.worm1.aim_rect = worm1->aim_rect;
	game.worm1.bazooka_flip_rect = worm1->bazooka_flip_rect;
	game.worm1.bazooka_rect = worm1->bazooka_rect;
	game.worm1.bazooka_state = worm1->bazooka_state;
	game.worm1.coeff = worm1->coeff;
	game.worm1.dt = worm1->dt;
	game.worm1.health = worm1->health;
	game.worm1.is_stable = worm1->is_stable;
	game.worm1.marker_rect = worm1->marker_rect;
	game.worm1.missile.angle = worm1->missile.angle;
	game.worm1.missile.fired = worm1->missile.fired;
	game.worm1.missile.pos = worm1->missile.pos;
	game.worm1.missile.vx = worm1->missile.vx;
	game.worm1.missile.vy = worm1->missile.vy;
	game.worm1.pos = worm1->pos;
	game.worm1.power = worm1->power;
	game.worm1.power_bar_rect = worm1->power_bar_rect;
	game.worm1.rotate = worm1->rotate;
	game.worm1.score = worm1->score;
	game.worm1.start_power_bar_rect = worm1->start_power_bar_rect;
	game.worm1.vx = worm1->vx;
	game.worm1.vy = worm1->vy;

	game.worm2.aim_rect = worm2->aim_rect;
	game.worm2.bazooka_flip_rect = worm2->bazooka_flip_rect;
	game.worm2.bazooka_rect = worm2->bazooka_rect;
	game.worm2.bazooka_state = worm2->bazooka_state;
	game.worm2.coeff = worm2->coeff;
	game.worm2.dt = worm2->dt;
	game.worm2.health = worm2->health;
	game.worm2.is_stable = worm2->is_stable;
	game.worm2.marker_rect = worm2->marker_rect;
	game.worm2.missile.angle = worm2->missile.angle;
	game.worm2.missile.fired = worm2->missile.fired;
	game.worm2.missile.pos = worm2->missile.pos;
	game.worm2.missile.vx = worm2->missile.vx;
	game.worm2.missile.vy = worm2->missile.vy;
	game.worm2.pos = worm2->pos;
	game.worm2.power = worm2->power;
	game.worm2.power_bar_rect = worm2->power_bar_rect;
	game.worm2.rotate = worm2->rotate;
	game.worm2.score = worm2->score;
	game.worm2.start_power_bar_rect = worm2->start_power_bar_rect;
	game.worm2.vx = worm2->vx;
	game.worm2.vy = worm2->vy;

	fwrite(&game, sizeof(SavedGame), 1, savedgame);
	fclose(savedgame);
}

/*!	\brief Function used to read all of the information needed to continue previously saved game from file
*	\param worm1
*	\param worm2
*	\param map
*/
int ContinueGame(struct Worm **worm1, struct Worm **worm2, struct Map **map) {
	FILE *continuegame = fopen(saved_file_name, "rb");
	SavedGame game;
	if (continuegame == NULL)
		return 0;
	fread(&game, sizeof(SavedGame), 1, continuegame);

	for (int i = 0; i < Width; i++)
		(*map)->height[i] = game.height[i];

	 (*worm1)->aim_rect = game.worm1.aim_rect ;
	 (*worm1)->bazooka_flip_rect = game.worm1.bazooka_flip_rect;
	 (*worm1)->bazooka_rect = game.worm1.bazooka_rect;
	 (*worm1)->bazooka_state = game.worm1.bazooka_state;
	 (*worm1)->coeff = game.worm1.coeff;
	 (*worm1)->dt = game.worm1.dt;
	 (*worm1)->health = game.worm1.health;
	 (*worm1)->is_stable = game.worm1.is_stable;
	 (*worm1)->marker_rect = game.worm1.marker_rect;
	 (*worm1)->missile.angle = game.worm1.missile.angle;
	 (*worm1)->missile.fired = game.worm1.missile.fired;
	 (*worm1)->missile.pos = game.worm1.missile.pos;
	 (*worm1)->missile.vx = game.worm1.missile.vx;
	 (*worm1)->missile.vy = game.worm1.missile.vy;
	 (*worm1)->pos = game.worm1.pos;
	 (*worm1)->power = game.worm1.power;
	 (*worm1)->power_bar_rect = game.worm1.power_bar_rect;
	 (*worm1)->rotate = game.worm1.rotate;
	 (*worm1)->score = game.worm1.score;
	 (*worm1)->start_power_bar_rect = game.worm1.start_power_bar_rect;
	 (*worm1)->vx = game.worm1.vx;
	 (*worm1)->vy = game.worm1.vy;

	 (*worm2)->aim_rect = game.worm2.aim_rect;
	 (*worm2)->bazooka_flip_rect = game.worm2.bazooka_flip_rect;
	 (*worm2)->bazooka_rect = game.worm2.bazooka_rect;
	 (*worm2)->bazooka_state = game.worm2.bazooka_state;
	 (*worm2)->coeff = game.worm2.coeff;
	 (*worm2)->dt = game.worm2.dt;
	 (*worm2)->health = game.worm2.health;
	 (*worm2)->is_stable = game.worm2.is_stable;
	 (*worm2)->marker_rect = game.worm2.marker_rect;
	 (*worm2)->missile.angle = game.worm2.missile.angle;
	 (*worm2)->missile.fired = game.worm2.missile.fired;
	 (*worm2)->missile.pos = game.worm2.missile.pos;
	 (*worm2)->missile.vx = game.worm2.missile.vx;
	 (*worm2)->missile.vy = game.worm2.missile.vy;
	 (*worm2)->pos = game.worm2.pos;
	 (*worm2)->power = game.worm2.power;
	 (*worm2)->power_bar_rect = game.worm2.power_bar_rect;
	 (*worm2)->rotate = game.worm2.rotate;
	 (*worm2)->score = game.worm2.score;
	 (*worm2)->start_power_bar_rect = game.worm2.start_power_bar_rect;
	 (*worm2)->vx = game.worm2.vx;
	 (*worm2)->vy = game.worm2.vy;
	
	fclose(continuegame);
	return 1;
}

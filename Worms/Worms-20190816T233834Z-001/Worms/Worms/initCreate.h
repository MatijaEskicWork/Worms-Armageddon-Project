#ifndef _initCreate_h_
#define _initCreate_h_
#include <SDL.h>
#include "typesShorter.h" 

#define Height 680
#define Width 1200

/*!	   \file initCreate.h
*	   \brief Contains declarations of functions for initialization and creation of SDL objects
*/

/*!
*	\brief Struct for Button that contains his position, image for texture and bool type variable it is hovered with mouse
*/
struct Button {
	SDL_Rect pos;
	Texture texture;
	Texture hov_tex;
	int hovered;
};

extern struct Button save_game_butt;
extern struct Button exit_pause_butt;
extern Texture pause_menu;

Window InitCreateWindow(Window window, const char* name, int xcord, int ycord, int width, int height, int flag);

Renderer InitCreateRenderer(Renderer render, Window window, int index, Uint32 render_flags);

Surface InitCreateSurface(Surface surface, const char* file_directory, Window window, Renderer render);

Texture InitCreateTexture(Texture texture, int choice, const char* file_directory, Renderer render, Surface surface, Window window);

struct Button InitButton(int is_hover, int pos_x, int pos_y, int width, int height);
#endif

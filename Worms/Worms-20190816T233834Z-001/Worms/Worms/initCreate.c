#include "initCreate.h"
#include <SDL_image.h>
#include <stdio.h>
/*!	   \ file InitCreate.c
*	   \ brief Contains definition of functions for initialization and creation of SDL objects
*/

/*!
*	\brief Creating and initializing window. 1 if isnt succesfull, 0 otherwise
*	\param window is object Window in SDL
*	\param name is title of window
*	\param xcord is x coordinate of window
*	\param ycord is y coordinate of window
*	\param width is width of window
*	\param height is height of window
*	\param flag is usually 0, doesnt have some great purpose
*/
Window InitCreateWindow(Window window, const char* name, int xcord, int ycord, int width, int height, int flag) {
	window = NULL;
	window = SDL_CreateWindow(name, xcord, ycord, width, height, flag);
	if (!window) {
		printf("Error creating window.%s\n", SDL_GetError());
		SDL_Quit();
		return NULL;
	}
	return window;
}

/*!
*	\brief Creating and initalizing renderer. 1 if isnt succesfull, 0 otherwise
*	\param render is object Renderer in SDL
*	\param window is object Window in SDL
*	\param index is number usually -1, doesnt have some great purpose
*	\param render_flags is Uint32 type and it is type of renderer, there are several types of those
*/
Renderer InitCreateRenderer(Renderer render, Window window, int index, Uint32 render_flags) {
	render = SDL_CreateRenderer(window, index, render_flags);
	if (!render) {
		printf("Error creating renderer.%s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return NULL;
	}
	return render;
}

/*!
*	\brief Creating and initializing surface. 1 if isnt succesfull, 0 otherwise
*	\param surface is object Surface in SDL
*	\param file_directory is string which is path of some image or something like that
*	\param window is object Window in SDL
*	\param render is object Renderer in SDL
*/
Surface InitCreateSurface(Surface surface, const char* file_directory, Window window, Renderer render) {
	surface = NULL;
	surface = IMG_Load(file_directory);
	if (!surface) {
		printf("Error loading image for surface.%s\n", IMG_GetError());
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return NULL;
	}
	return surface;
}

/*!
*	\brief Creating and initializing of texture. 1 if isnt succesfull, 0 otherwise
*	\param texture is object Texture in SDL
*	\param choice is number - 0 or 1 - which allows us to choose one of two types creating texture
*	\param file_directory is string which is path of some image or something like that
*	\param render is object Renderer in SDL
*	\param surface is object Surface in SDL
*	\param window is object Window in SDL
*/
Texture InitCreateTexture(Texture texture, int choice, const char* file_directory, Renderer render, Surface surface, Window window) {
	texture = NULL;
	if (!choice) texture = IMG_LoadTexture(render, file_directory);
	else {
		texture = SDL_CreateTextureFromSurface(render, surface);
		SDL_FreeSurface(surface);
	}
	if (!texture) {
		printf("Error loading textures ");
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return NULL;
	}
	return texture;
}

/*!	\brief function used for initializing button structure
*/
struct Button InitButton(int is_hover, int pos_x, int pos_y, int width, int height) {
	struct Button button;
	button.texture = NULL;
	button.hovered = is_hover;
	button.pos.x = pos_x;
	button.pos.y = pos_y;
	button.pos.w = width;
	button.pos.h = height;
	return button;
}





/*
 * CSurface.h
 *
 *  Created on: Sep 16, 2020
 *      Author: Admin
 */

#ifndef GRAPHICS_CSURFACE_H_
#define GRAPHICS_CSURFACE_H_

#include "SDL2/SDL.h"


class CSurface
{
public:
	CSurface();
	static SDL_Surface* OnLoad(SDL_Window* window, const char* File);

	static bool OnDraw(SDL_Surface* dest, SDL_Surface* src, int X, int Y);
	static bool OnDraw(SDL_Surface* dest, SDL_Surface* src, int X, int Y, int X2, int Y2, int W, int H);

	static bool Transparent(SDL_Surface* Surf_dest, int R, int G, int B);
private:
};

#endif /* GRAPHICS_CSURFACE_H_ */

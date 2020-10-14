/*
 * CSurface.cpp
 *
 *  Created on: Sep 16, 2020
 *      Author: Admin
 */

#include "CSurface.h"
#include <SDL2/SDL_image.h>
#include <iostream>

CSurface::CSurface()
{

}
SDL_Surface* CSurface::OnLoad(SDL_Window* window, const char* File)
{
	SDL_Surface* temp = NULL;
	SDL_Surface* optr = NULL;


	if((temp = IMG_Load(File)) == NULL)
	{
		std::cout << "IMAGE LOAD NULL" << std::endl;
		return NULL;
	}
	 optr = SDL_ConvertSurfaceFormat(temp, SDL_GetWindowPixelFormat(window), 0);
	 SDL_FreeSurface(temp);

	 return optr;
}
bool CSurface::OnDraw(SDL_Surface* dest, SDL_Surface* src, int X, int Y)
{
	if(dest == NULL || src == NULL) return false;
	SDL_Rect DestR;
	DestR.x = X;
	DestR.y = Y;

	SDL_BlitSurface(src, NULL, dest, &DestR);

	return true;

}
bool CSurface::OnDraw(SDL_Surface* dest, SDL_Surface* src, int X, int Y, int X2, int Y2, int W, int H)
{
	if(dest == NULL || src == NULL) return false;

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;

	SDL_Rect SrcR;

	SrcR.x = X2;
	SrcR.y = Y2;
	SrcR.w = W;
	SrcR.h = H;

	SDL_BlitSurface(src, &SrcR, dest, &DestR);
}

bool CSurface::Transparent(SDL_Surface* Surf_dest, int R, int G, int B)
{
	if(Surf_dest == NULL) return false;
	SDL_PixelFormat* format = Surf_dest->format;
	SDL_SetColorKey(Surf_dest, SDL_TRUE | SDL_RLEACCEL, SDL_MapRGB(format, R, G, B));

	return true;
}


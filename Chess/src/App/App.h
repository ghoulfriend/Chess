/*
 * App.h
 *
 *  Created on: Sep 16, 2020
 *      Author: Admin
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include <SDL2/SDL.h>
#include "InputController.h"
#include "CSurface.h"
#include "Board.h"
#include <stdint.h>

class App
{
private:
	bool Running;
	int playerTurn;

	SDL_Surface* Surf_Display;
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Surface* Surf_Grid;
	SDL_Surface* Surf_Pieces;
	SDL_Surface* Surf_isHighLighted;

	Board chessBoard;

	InputController mInputController;

public:

	App();

	int OnExecute();
	bool OnInit();
	void OnEvent(SDL_Event& Event);
	void OnLoop();
	void OnRender();
	void OnCleanup();

	void Reset();
	void SetCell(int id, int grid_type);

};



#endif /* APP_APP_H_ */

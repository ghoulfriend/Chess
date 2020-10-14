/*
 * App.cpp
 *
 *  Created on: Sep 16, 2020
 *      Author: Admin
 */

#include <SDL2/SDL_image.h>

#include <iostream>

#include "App.h"
#include "CSurface.h"
#include "Board.h"
#include "Piece.h"
#include "Square.h"
#include "Vec2D.h"

#include "InputController.h"

App::App()
{
	Surf_Display = NULL;
	Surf_Grid = NULL;
	Surf_Pieces = NULL;
	Surf_isHighLighted = NULL;
	renderer = NULL;
	window = NULL;

	playerTurn = 0;

	Running = true;
}
int App::OnExecute()
{
	if(OnInit() == false)
	{
		std::cout << "INIT FAILURE" << std::endl;
		return -1;
	}

	bool Running = true;
	mInputController.Init( [&Running](){ Running = false; });

	while(Running)
	{
		mInputController.Update(chessBoard); //add dt as parameter

		OnLoop();

		OnRender();
	}
	OnCleanup();

	return 0;
}
bool App::OnInit()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL INIT FAILURE" << std::endl;
		return false;
	}
	//WINDOW LOAD AND CONFIG
	window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0 );

	//RENDERER LOAD AND CONFIG
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	//IMAGES LOAD AND CONFIG
	if((Surf_Grid = CSurface::OnLoad(window, "gfx/Chessboard_black_brown.bmp")) == NULL)
	{
		std::cout << "LOAD CHESSBOARD IMAGE FAILURE" << std::endl;
		return false;
	}
	if((Surf_Pieces = CSurface::OnLoad(window, "gfx/pieces_0_255_0.png")) == NULL)
	{
		std::cout << "LOAD PIECES IMAGE FAILURE" << std::endl;
		return false;
	}
	if((Surf_isHighLighted = CSurface::OnLoad(window, "gfx/isHighLighted.png")) == NULL)
	{
		std::cout << "LOAD isHighLighted.png FAILURE!" << std::endl;
	}

	CSurface::Transparent(Surf_Pieces, 0, 255, 0);

	//Reset();//not implemented / was for tic tac toe


	//INIT CHESSBOARD, SET SQUARE COLORS, SQUARE STARTING PIECES AND SQUARE POS
	chessBoard.Init();

	//INIT PIECES WITH CORRECT STARTING POS AND COLOR (playerOne)
	for(int i = 0; i < 8; ++i)
	{
		for( int j = 0; j < 8; ++j)
		{
			if( chessBoard.squares[j][i].GetOptr() != nullptr )
			{
				if( i < 4 ) chessBoard.squares[j][i].GetOptr()->setPlayerOne(true);
				chessBoard.squares[j][i].GetOptr()->setPosition(Vec2D(j, i));
			}
		}
	}


	return true;
}
void App::OnEvent(SDL_Event& Event)
{
	//CEvent::OnEvent(Event);

	if((Event).type == SDL_QUIT)
	{
		std::cout << "SDL_QUIT TRIGGERED" << std::endl;
		Running = false;
	}
	if((Event).type == SDL_MOUSEBUTTONDOWN)
	{
		std::cout << "Mouse button activated!" << std::endl;
	}
}
void App::OnLoop()
{
}
void App::OnRender()
{
		Surf_Display = SDL_GetWindowSurface( window );

		//DRAW CHESSBOARD
		CSurface::OnDraw(Surf_Display, Surf_Grid, 0, 0);


		//DRAW isHighLighted.png for all highlighted squares



		//DRAW PIECES
		//GO THROUGH EA BOARD SQAURE
		for(int y = 0; y < 8; ++y)
		{
			for(int x = 0; x < 8; ++x)
			{
				//ShowMoves if selected
				if(chessBoard.squares[x][y].getIsHighLighted() == true)
				{
					int xPixel = chessBoard.squares[x][y].getPosition().GetX() * 100;
					int yPixel = 700 - chessBoard.squares[x][y].getPosition().GetY() * 100;
					CSurface::OnDraw(Surf_Display, Surf_isHighLighted, xPixel, yPixel, 0, 0, 100, 100);
				}
			}
		}
		for(int y = 0; y < 8; ++y)
		{
			for(int x = 0; x < 8; ++x)
			{
				//Draw Pieces
				if(chessBoard.squares[x][y].GetOptr() != nullptr)
				{
					chessBoard.squares[x][y].GetOptr()->draw(Surf_Display, Surf_Pieces, chessBoard.squares[x][y].GetOptr()->getPosition());//IDK WHY BUT HAVE TO PASS POS FROM OUTSIDE
				}
			}

		}



		SDL_UpdateWindowSurface(window);

		//SDL_Delay(3000);//otherwise image will stuttekr
}
void App::OnCleanup()
{
	SDL_FreeSurface(Surf_Display);
	SDL_FreeSurface(Surf_Grid);
	SDL_FreeSurface(Surf_Pieces);

	SDL_Quit();
}
int main(int argc, char* argv[])
{
	App theApp;

	return theApp.OnExecute();
}

void App::Reset()
{

}

void App::SetCell(int id, int grid_type)
{
}


#include <SDL2/SDL.h>
#include "InputController.h"
#include <iostream>
#include <functional>
#include "App.h"
#include "Board.h"
#include "Square.h"
#include <stdint.h>


void InputController::Init( std::function<void()> func)
{
	mQuit = func;
}
void InputController::Update(Board& chessBoard)
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			mQuit();
		}
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			//this was in InputAction.h
			//using MouseInputAction = std::function<void(InputState state, const MousePosition& position)>;

			std::cout << "MOUSEBUTTONDOWN activated!"<< std::endl;
			std::cout << "X POS: " << event.button.x << "\nY POS: " << event.button.y << std::endl;
			//if( playerTurn = 0 && square.player == 0 ){

			int xIndex = (event.button.x / 100);
			int yIndex = 7 - event.button.y / 100 ;

			std::cout << "xIndex: " << xIndex <<  ", yIndex: " << yIndex << std::endl;

			//When a square is clicked, set all squares isHighLighted(false) and call showMoves() to highLight new moves
			for(int y = 0; y < 8; ++y)
			{
				for( int x = 0; x < 8; ++x )
				{
					chessBoard.squares[x][y].setIsHighLighted(false);
				}
			}
			//chessBoard.squares[squareIndex].setIsHighLighted(true);
			chessBoard.squares[xIndex][yIndex].GetOptr()->showMoves(chessBoard, xIndex, yIndex);


		}
	}
}

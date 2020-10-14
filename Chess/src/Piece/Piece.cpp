/*
 * Piece.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Admin
 */

#include "Vec2D.h"
#include <iostream>
#include "Piece.h"
#include <cstring>
#include "CSurface.h"
#include "Board.h"

void Piece::setPlayerOne(bool b)
{
	if( b ) playerOne = true;
}
bool Piece::getPlayerOne()
{
	return playerOne;
}
Vec2D Piece::getPosition()
{
	return position;
}
void Piece::setPosition(Vec2D pos)
{
	position = pos;
}
bool Piece::getFirstMove(){
	return firstMove;
}
void Piece::setFirstMove(bool b)
{
	firstMove = b;
}

char Piece::getSymbol()
{
	return symbol;
}

std::ostream& operator<<(std::ostream& consoleOut, Piece& p)
{
	consoleOut << "Piece overloaded!" << std::endl;
	return consoleOut;
};


King::King()
{
	symbol = 'K';
}
void King::draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos)
{
	CSurface::OnDraw(surf_disp, surf_image, (static_cast<int>(pos.GetX() * 100)) + PADDING, (static_cast<int>(pos.GetY() * 100)) + PADDING, 64, (64 * static_cast<int>(playerOne)), 64, 64);
}
void King::showMoves(Board& chessBoard, int x, int y)
{
	chessBoard.squares[x][y].setIsHighLighted(true);

	//Up
	int xSeek = 0;
	int ySeek = 1;
	if(y + ySeek < 8)
	{
		chessBoard.squares[x][y + ySeek].setIsHighLighted(true);
	}

	//Up-Right
	xSeek = 1;
	ySeek = 1;
	if((y + ySeek < 8) && (x + xSeek < 8))
	{
		chessBoard.squares[x + xSeek][y + ySeek].setIsHighLighted(true);
	}

	//Right
	xSeek = 1;
	ySeek = 0;
	if(x + xSeek < 8)
	{
		chessBoard.squares[x + xSeek][y].setIsHighLighted(true);
	}

	//Right-Down
	xSeek = 1;
	ySeek = 1;
	if((x + xSeek < 8) && (y - ySeek >= 0))
	{
		chessBoard.squares[x + xSeek][y - ySeek].setIsHighLighted(true);
	}

	//Down
	xSeek = 0;
	ySeek = 1;
	if(y - ySeek >= 0)
	{
		chessBoard.squares[x][y - ySeek].setIsHighLighted(true);
	}

	//Down-Left
	xSeek = 1;
	ySeek = 1;
	if((x - xSeek >= 0) && (y - ySeek >= 0))
	{
		chessBoard.squares[x - xSeek][y - ySeek].setIsHighLighted(true);
	}

	//Left
	xSeek = 1;
	ySeek = 0;
	if(x - xSeek >= 0)
	{
		chessBoard.squares[x - xSeek][y].setIsHighLighted(true);
	}

	//Left-Up
	xSeek = 1;
	ySeek = 1;
	if(( x - xSeek >= 0) && (y + ySeek < 8))
	{
		chessBoard.squares[x - xSeek][y + ySeek].setIsHighLighted(true);
	}

}


Queen::Queen()
{
	symbol = 'Q';
}
void Queen::draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos)
{

	CSurface::OnDraw(surf_disp, surf_image, (static_cast<int>(pos.GetX() * 100)) + PADDING, (static_cast<int>(pos.GetY() * 100)) + PADDING, 0, (64 * playerOne), 64, 64);
}

void Queen::showMoves(Board& chessBoard, int x, int y)
{

	    for ( int xSeek = -1; xSeek < 2; ++xSeek )
	    {

	        for ( int ySeek = -1; ySeek < 2; ++ySeek )
	        {

	            if ( xSeek == 0 && ySeek == 0 )
	                { continue; }

	            int xPos = (x + xSeek);
	            int yPos = (y + ySeek);

	            while ( (xPos >= 0 && xPos < 8) && (yPos >= 0 && yPos < 8) )
	            {

	                chessBoard.squares[xPos][yPos].setIsHighLighted(true);

	                xPos += xSeek;
	                yPos += ySeek;
	            }
	        }
	    }

}

//inline void Queen::showmoves(int x, int y, int xseek, int yseek) {
//  while(((x += xseek) & 007) != 0 && ((y += yseek) & 007) != 0 && chessBoard[x][y].is_empty( ))
//    chessBoard.squares[x][y].setIsHighLighted(true);
//}
//
//
//
//void Queen::showMoves(Board& chessBoard, int x, int y)
//{
//    chessBoard.squares[x][y].setIsHighLighted(true);
//
//    showmoves(x, y, 0, 1);            //Up
//    showmoves(x, y, 1, 1);            //Up-Right
//    showmoves(x, y, 1, 0);            //Right
//    showmoves(x, y, 1, -1);            //Right-Down
//    showmoves(x, y, 0, -1);            //Down
//    showmoves(x, y, -1, -1);            //Down-Left
//    showmoves(x, y, -1, 0);            //Left
//    showmoves(x, y, -1, 1);            //Left-Up
//}



//void Queen::showMoves(Board& chessBoard, int x, int y)
//{
//    int x0, y0;
//
//    chessBoard.squares[x][y].setIsHighLighted(true);
//
//    //Up
//    y0 = y;
//    while(++y0 < 8)
//        chessBoard.squares[x][y0].setIsHighLighted(true);
//
//
//    //Up-Right
//    x0 = x; y0 = y;
//    while(++y0 < 8 && ++x0 < 8)
//        chessBoard.squares[x0][y0].setIsHighLighted(true);
//
//    //Right
//    x0 = x;
//    while(++x0 < 8)
//        chessBoard.squares[x0][y].setIsHighLighted(true);
//
//    //Right-Down
//    x0 = x; y0 = y;
//    while((++x0 < 8) && (--y0 >= 0))
//        chessBoard.squares[x0][y0].setIsHighLighted(true);
//
//    //Down
//    y0 = y;
//    while(--y0 >= 0)
//        chessBoard.squares[x][y0].setIsHighLighted(true);
//
//    //Down-Left
//    x0 = x; y0 = y;
//    while(--x0 >= 0 && --y0 >= 0)
//        chessBoard.squares[x0][y0].setIsHighLighted(true);
//
//    //Left
//    x0 = x;
//    while(--x0 >= 0)
//        chessBoard.squares[x0][y].setIsHighLighted(true);
//
//    //Left-Up
//    x0 = x; y0 = y;
//    while(--x0 >= 0 && ++y0 < 8))
//        chessBoard.squares[x0][y0].setIsHighLighted(true);
//}

Bishop::Bishop()
{
	symbol = 'B';
}
void Bishop::draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos)
{

	CSurface::OnDraw(surf_disp, surf_image, (static_cast<int>(pos.GetX() * 100)) + PADDING, (static_cast<int>(pos.GetY() * 100)) + PADDING, 256, (64 * playerOne), 64, 64);
}
void Bishop::showMoves(Board& chessBoard, int x, int y)
{
	chessBoard.squares[x][y].setIsHighLighted(true);

	int xSeek = 0;
	int ySeek = 0;

	//Up-Right
	while((y + ySeek < 8) && (x + xSeek < 8))
	{
		chessBoard.squares[x + xSeek][y + ySeek].setIsHighLighted(true);
		xSeek++;
		ySeek++;
	}
	ySeek = 0;
	xSeek = 0;
	//Up-Left
	while((y + ySeek < 8) && (x - xSeek >= 0))
	{
		chessBoard.squares[x - xSeek][y + ySeek].setIsHighLighted(true);
		xSeek++;
		ySeek++;
	}
	xSeek = 0;
	ySeek = 0;
	//Down-Right
	while((y - ySeek >= 0) && (x + xSeek < 8))
	{
		chessBoard.squares[x + xSeek][y - ySeek].setIsHighLighted(true);
		xSeek++;
		ySeek++;
	}
	ySeek = 0;
	xSeek = 0;
	//Down-Left
	while((y - ySeek >= 0) && (x - xSeek >= 0))
	{
		chessBoard.squares[x - xSeek][y - ySeek].setIsHighLighted(true);
		xSeek++;
		ySeek++;
	}

}


Knight::Knight()
{
	symbol = 'N';
}
void Knight::draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos)
{

	CSurface::OnDraw(surf_disp, surf_image, (static_cast<int>(pos.GetX() * 100)) + PADDING, (static_cast<int>(pos.GetY() * 100)) + PADDING, 192, (64 * playerOne), 64, 64);
}
void Knight::showMoves(Board& chessBoard, int x, int y)
{
	chessBoard.squares[x][y].setIsHighLighted(true);

	//Up-Right
	int xSeek = 1;
	int ySeek = 2;
	if((y + ySeek < 8) && (x + xSeek < 8))
	{
		chessBoard.squares[x + xSeek][y + ySeek].setIsHighLighted(true);
	}

	//Up-Left
	xSeek = 1;
	ySeek = 2;
	if((y + ySeek < 8) && (x - xSeek >= 0))
	{
		chessBoard.squares[x - xSeek][y + ySeek].setIsHighLighted(true);
	}

	//Down-Right
	xSeek = 1;
	ySeek = 2;
	if((y - ySeek >= 0) && (x + xSeek < 8))
	{
		chessBoard.squares[x + xSeek][y - ySeek].setIsHighLighted(true);
	}

	//Down-Left
	xSeek = 1;
	ySeek = 2;
	if((y - ySeek >= 0) && (x - xSeek >= 0))
	{
		chessBoard.squares[x - xSeek][y - ySeek].setIsHighLighted(true);
	}

	//Right-Up
	xSeek = 2;
	ySeek = 1;
	if((x + xSeek < 8) && (y + ySeek < 8))
	{
		chessBoard.squares[x + xSeek][y + ySeek].setIsHighLighted(true);
	}

	//Right-Down
	xSeek = 2;
	ySeek = 1;
	if((x + xSeek < 8) && (y - ySeek >= 0))
	{
		chessBoard.squares[x + xSeek][y - ySeek].setIsHighLighted(true);
	}

	//Left-Up
	xSeek = 2;
	ySeek = 1;
	if((x - xSeek >= 0) &&(y + ySeek < 8))
	{
		chessBoard.squares[x - xSeek][y + ySeek].setIsHighLighted(true);
	}

	//Left-Down
	xSeek = 2;
	ySeek = 1;
	if((x - xSeek >= 0) && (y - ySeek >= 0))
	{
		chessBoard.squares[x - xSeek][y - ySeek].setIsHighLighted(true);
	}
}


Rook::Rook()
{
	symbol = 'R';
}
void Rook::draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos)
{

	CSurface::OnDraw(surf_disp, surf_image, (static_cast<int>(pos.GetX() * 100)) + PADDING, (static_cast<int>(pos.GetY() * 100)) + PADDING, 128, (64 * playerOne), 64, 64);

}

void Rook::showMoves(Board& chessBoard, int x, int y)
{
	for ( int xSeek = -1; xSeek < 2; ++xSeek )
	{
		for ( int ySeek = -1; ySeek < 2; ++ySeek)
		{
			if ( (xSeek == 0 && ySeek == 0) || (xSeek == 1 && ySeek == 1)  || (xSeek == -1 && ySeek == -1) || (xSeek == 1 && ySeek == -1) || (xSeek == -1 && ySeek == 1) )
			{
				{ continue; }
			}
			int xPos = (x + xSeek);
			int yPos = (y + ySeek);

			while ( (xPos >= 0 && xPos < 8) && (yPos >= 0 && yPos < 8) )
			{
				chessBoard.squares[xPos][yPos].setIsHighLighted(true);
				xPos += xSeek;
				yPos += ySeek;
			}
		}
	}
}

Pawn::Pawn()
{
	symbol = 'P';
}
void Pawn::draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos)
{
	CSurface::OnDraw(surf_disp, surf_image, (static_cast<int>(pos.GetX() * 100)) + PADDING, (static_cast<int>(pos.GetY() * 100)) + PADDING, 320, (64 * playerOne), 64, 64);
}
void Pawn::showMoves(Board& chessBoard, int x, int y)
{
	chessBoard.squares[x][y].setIsHighLighted(true);

	if( firstMove )
	{
		if( playerOne )
		{
			chessBoard.squares[x][y + 2].setIsHighLighted(true);
			chessBoard.squares[x][y + 1].setIsHighLighted(true);
		}
		else
		{
			chessBoard.squares[x][y - 2].setIsHighLighted(true);
			chessBoard.squares[x][y - 1].setIsHighLighted(true);
		}
	}else{
		if( playerOne )
		{
			chessBoard.squares[x][y + 1].setIsHighLighted(true);
		}
		else
		{
			chessBoard.squares[x][y - 1].setIsHighLighted(true);
		}
	}
}

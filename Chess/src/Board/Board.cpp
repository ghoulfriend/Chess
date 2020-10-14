#include "Board.h"
#include "Piece.h"
#include "Square.h"

Board::Board()
{
	Init();
}

void Board::Init()
{
	for ( int y = 0; y < 8; ++y )
	{
		for ( int x = 0; x < 8; ++x)
		{
			this->squares[x][y].SetColor( x % 2 );//start on black
			this->squares[x][y].setPosition(Vec2D(x, y));
			this->squares[x][y].SetOptr(nullptr);
			this->squares[x][y].setIsHighLighted(false);
		}
	}

	for ( int player = 0; player < 2; ++player )
	{
		//initialize backrow of pieces
		Piece* backRow[8] = { new Rook(), new Knight(), new Bishop(), new King(), new Queen(), new Bishop(), new Knight(), new Rook() };

		int offset = (player * 7);

		//actually assign the pieces
		for ( int i = 0; i < 8; ++i )
		{
			this->squares[i][ offset ].SetOptr( backRow[i] );
		}

		offset = (player * 5);

		for ( int i = 0; i < 8; ++i )
		{
			this->squares[i][ offset + 1 ].SetOptr( new Pawn() );
		}
	}
}

void Board::DrawTextBoard()
{
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			if(squares[i][j].GetOptr())
			{
				std::cout << squares[i][j].GetOptr()->getSymbol() << " ";
			}
		}
	}
}

/*
 * Board.h
 *
 *  Created on: Sep 9, 2020
 *      Author: Admin
 */
#include "Square.h"

#ifndef BOARD_BOARD_H_
#define BOARD_BOARD_H_


class Square;

class Board
{
public:
	Square squares[8][8];

	Board();

	void Init();

	void DrawTextBoard();

private:
};


#endif /* BOARD_BOARD_H_ */

/*
 * Square.h
 *
 *  Created on: Sep 9, 2020
 *      Author: Admin
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include "Piece.h"
#include "Vec2D.h"

class Square
{
public:
	Square();
	Square(bool color, Vec2D pos, Piece* ptrpiece);

	int GetColor();
	void SetColor(int c);
	Vec2D getPosition();
	void setPosition(Vec2D);
	Piece* GetOptr();
	void SetOptr(Piece* optr);
	void setIsHighLighted(bool);
	bool getIsHighLighted();


private:
	int color;
	Vec2D position;
	Piece* optrpiece;
	bool isHighLighted;
};


#endif /* SQUARE_H_ */

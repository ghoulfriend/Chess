/*
 * Square.cpp
 *
 *  Created on: Sep 12, 2020
 *      Author: Admin
 */

#include "Square.h"

Square::Square()
{
	color = 0;
	optrpiece = nullptr;
	position = Vec2D(0,0);
}
Square::Square(bool color, Vec2D pos, Piece* piece = nullptr)
{
	optrpiece = piece;
	this->position = pos;
	this->color = color;
}
int Square::GetColor()
{
	return color;
}
void Square::SetColor(int c)
{
	color = c;
}
Vec2D Square::getPosition()
{
	return position;
}
void Square::setPosition(Vec2D pos)
{
	position = pos;
}

Piece* Square::GetOptr()
{
	return optrpiece;
}
void Square::SetOptr(Piece* optr)
{
	optrpiece = optr;
}
void Square::setIsHighLighted(bool b)
{
	isHighLighted = b;
}
bool Square::getIsHighLighted()
{
	return isHighLighted;
}


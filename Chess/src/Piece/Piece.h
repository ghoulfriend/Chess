/*
 * Piece.h
 *
 *  Created on: Sep 9, 2020
 *      Author: Admin
 */

#ifndef PIECE_PIECE_H_
#define PIECE_PIECE_H_

#include "Vec2D.h"
#include <SDL2/SDL.h>
const int PADDING = 18;

class Board;

class Piece
{
public:
	virtual char getSymbol();
	void setPlayerOne(bool);
	bool getPlayerOne();
	Vec2D getPosition();
	void setPosition(Vec2D pos);
	bool getFirstMove();
	void setFirstMove(bool);

	virtual void draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos) = 0;

	virtual void showMoves(Board&, int x, int y) = 0;

	friend std::ostream& operator<<(std::ostream& consoleOut, Piece& p);

protected:
	bool playerOne;
	Vec2D position;
	bool firstMove;
	char symbol;
};


class King: public Piece
{
public:
	King();
	void draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos);
	void showMoves(Board&, int x, int y);
};


class Queen: public Piece
{
public:
	Queen();
	void draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos);
	void showMoves(Board&, int x, int y);
};


class Bishop: public Piece
{
public:
	Bishop();
	void draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos);
	void showMoves(Board&, int x, int y);
};


class Knight: public Piece
{
public:
	Knight();
	void draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos);
	void showMoves(Board&, int x, int y);
};


class Rook: public Piece
{
public:
	Rook();
	void draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos);
	void showMoves(Board&, int x, int y);
};


class Pawn: public Piece
{
public:
	Pawn();
	void draw(SDL_Surface* surf_disp, SDL_Surface* surf_image, Vec2D pos);
	void showMoves(Board&, int x, int y);
};



#endif /* PIECE_PIECE_H_ */

#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	//Constructor and basic spawn function
	Rook();

	//Spawn function in parent Piece

	//Move execution function. x = true, y = false
	void executeMove(Directions direction, int steps, bool capture);

	//Capture handling done by parent Piece

	//Piece specific functionality
	void executeCastle(bool dir);
};
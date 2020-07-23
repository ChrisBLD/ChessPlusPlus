#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	//Constructor and basic spawn function
	King();

	//Spawn function in parent Piece

	//Move execution function. x = true, y = false
	void executeMove(Directions direction, int steps, bool capture);

	//Capture handling done by parent Piece

	//Piece specific functionality
	void executeCastle(bool dir);


};
#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	//Constructor and basic spawn function
	Queen();

	//Spawn function in parent Piece

	//Move execution function
	void executeMove(Directions direction, int steps, bool capture);

	//Capture handling done by parent Piece
};
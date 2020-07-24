#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	//Constructor and basic spawn function
	Knight();

	//Move execution functions
	void executeMove(Directions direction, int steps, bool captured);

	//Show moves that can be made by this piece at this time
	void showPossibleMoves(Colour** occupiedTiles);

	//Capture handling done by parent Piece
};
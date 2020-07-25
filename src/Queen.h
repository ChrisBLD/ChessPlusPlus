#pragma once
#include "Piece.h"

class Queen : public Piece
{
private:

	

public:
	//Constructor and basic spawn function
	Queen();

	//Spawn function in parent Piece

	//Move execution function
	void executeMove(Directions direction, int steps, bool capture);

	//Show moves that can be made by this piece at this time
	void showPossibleMoves(Colour** occupiedTiles);

	//Capture handling done by parent Piece
};
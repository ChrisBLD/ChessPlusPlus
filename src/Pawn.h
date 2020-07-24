#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	//Constructor and basic spawn function
	Pawn();
	
	//Spawn function in parent Piece

	//Move execution function
	void executeMove(Directions direction, int steps, bool capture);

	//Show moves that can be made by this piece at this time
	void showPossibleMoves(Colour** occupiedTiles);

	//Capture handling done by parent Piece

	//Piece-specific functionality 
	void executeEnPassant(bool dir);
};
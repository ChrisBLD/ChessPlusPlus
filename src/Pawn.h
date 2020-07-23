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

	//Capture handling done by parent Piece

	//Piece-specific functionality 
	void executeEnPassant(bool dir);
};
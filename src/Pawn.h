#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	//Constructor and basic spawn function
	Pawn();
	void virtual spawn(Vector2i startPosition);

	//Move execution functions
	void executeMoveNoCapture(bool dub);
	void executeMoveCapture(bool dir);

	//Capture handling done by parent Piece

	//Piece-specific functionality 
	bool executeDoubleMove();
};
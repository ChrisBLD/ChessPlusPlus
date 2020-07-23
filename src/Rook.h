#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	//Constructor and basic spawn function
	Rook();
	void virtual spawn(Vector2i startPosition);

	//Move execution function. x = true, y = false
	void executeMove(bool dir, int steps);


	//Capture handling done by parent Piece

	//Piece specific functionality
	void executeCastle(Piece& king);
};
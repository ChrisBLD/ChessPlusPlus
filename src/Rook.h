#pragma once
#include "Piece.h"

class Rook : public Piece
{
private:

	Sprite possibleMoves[4];

public:
	//Constructor and basic spawn function
	Rook();

	//Spawn function in parent Piece

	//Move execution function. x = true, y = false
	void executeMove(Directions direction, int steps, bool capture);

	//Show moves that can be made by this piece at this time
	void showPossibleMoves(Colour** occupiedTiles);

	//Get possible moves to display them on screen
	Sprite* getPossibleMoves();

	//Get current piece state
	PieceState getPieceState();

	//Capture handling done by parent Piece

	//Piece specific functionality
	void executeCastle(bool dir);
};
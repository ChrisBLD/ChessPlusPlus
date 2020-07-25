#pragma once
#include "Piece.h"

class Bishop : public Piece
{

private:

	Sprite possibleMoves[13];

public:
	//Constructor and basic spawn function
	Bishop();

	//Spawn function in parent Piece

	//Move execution function
	void executeMove(Directions direction, int steps, bool capture);

	//Show moves that can be made by this piece at this time
	void showPossibleMoves(Colour** occupiedTiles);

	//Get possible moves to display them on screen
	Sprite* getPossibleMoves();

	//Get current piece state
	PieceState getPieceState();

	//Capture handling done by parent Piece
};
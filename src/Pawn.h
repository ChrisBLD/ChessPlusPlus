#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:

	Sprite possibleMoves[4];

public:
	//Constructor and basic spawn function
	Pawn();
	
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

	//Piece-specific functionality 
	void executeEnPassant(bool dir);
};
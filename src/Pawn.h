#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn();
	void virtual spawn(Vector2f startPosition);

	bool canDoubleMove();

	void capture(bool dir);
};
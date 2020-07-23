#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

struct movement {
	//Booleans to check if a piece can move any amount of spaces in a given direction
	bool infiniteX;
	bool infiniteY;
	bool infiniteDiag;

	//If the above are false for any direction, how can the piece move in that direction?
	//For directions which the above are true, these are unused.
	int normalX;
	int normalY;
	int normalDiag;
};

class Piece
{
protected:

	//The piece needs a sprite
	Sprite m_Sprite;

	//The piece needs a tag for when it is in play or captured
	bool m_InPlay;

	//The piece needs a position - this is given as a position on the x-y axis starting at the bottom left of the board
	Vector2i m_Position;

	//We should also track the piece's starting position!
	Vector2i m_StartingPosition;

	//The piece's defined movement permissions
	movement m_Movement;

public:
	//Pure virtual spawn function
	void virtual spawn(Vector2i startPosition) = 0;

	//Capture handler
	void gotCaptured();

	Vector2i getPosition();
	Sprite getSprite();
};
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

	//The piece needs a position
	Vector2f m_Position;

	//The piece's defined movement permissions
	movement m_Movement;

public:
	//Pure virtual spawn function
	void virtual spawn(Vector2f startPosition) = 0;

	Vector2f getPosition();
	Sprite getSprite();
};
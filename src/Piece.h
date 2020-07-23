#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

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

public:
	//Spawn function
	void virtual spawn(Vector2i startPosition) = 0;

	//Capture handler
	void gotCaptured();

	//Change position (castle)
	void setPosition(Vector2i newPos);

	Vector2i getPosition();
	Sprite getSprite();
};
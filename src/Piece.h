#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"

using namespace sf;

class Piece
{
protected:

	//The piece needs a sprite
	Sprite m_Sprite;

	//The piece needs a tag for whether its current state
	PieceState m_State;

	//The piece needs a position - this is given as a position on the x-y axis starting at the bottom left of the board
	Vector2i m_Position;

	//When a piece moves, we want to animate it: so lets set the new move before we execute it
	Vector2i m_NextPosition;

	//We should also track the piece's starting position!
	Vector2i m_StartingPosition;

	//And a float position for smooth animation
	Vector2f m_GlobalPosition;

	//Fixed speed of piece animation
	const float SPEED = 50.0f;

	//Constant resolution
	const Vector2f resolution = Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);

	//Starting position of board
	const Vector2f boardPos = Vector2f(((resolution.x / 4.0f) + resolution.x / 2.0f)-(90*4)-60, (resolution.y / 2.0f) -(90 * 4) - 60);

public:
	//Pure virtual executeMove function
	void virtual executeMove(Directions direction, int steps, bool capture) = 0;

	//Spawn function
	void spawn(Vector2i startPosition);

	//Capture handler
	void gotCaptured();

	//Animate movement of pieces
	void animateMoves(float elapsedTime);

	//Change position (castle)
	void setPosition(Vector2i newPos);

	void isHovered();

	Vector2i getPosition();

	Vector2f getGlobalPosition();

	Sprite getSprite();
};
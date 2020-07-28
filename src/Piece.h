#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "TextureHolder.h"

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

	//Set the colour of this piece
	Colour m_Colour;

	//Fixed speed of piece animation
	const float SPEED = 50.0f;

	//Constant resolution
	const Vector2f resolution = Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);

	//Starting position of board
	const Vector2f boardPos = Vector2f(((resolution.x / 4.0f) + resolution.x / 2.0f)-(90*4)-60, (resolution.y / 2.0f) -(90 * 4) - 60);

	//Constant for tile sizes
	const int TILE_SIZE = 90;

	//Constant for max and min values of x and y
	const int MIN_X = boardPos.x;
	const int MIN_Y = boardPos.y;
	const int MAX_X = boardPos.x + (8 * TILE_SIZE);
	const int MAX_Y = boardPos.y + (8 * TILE_SIZE);


public:
	//Pure virtual executeMove function
	void virtual executeMove(Directions direction, int steps, bool capture) = 0;

	//Pure virtual showPossibleMoves function
	void virtual showPossibleMoves(Colour** m_Occupied) = 0;

	//Spawn function
	void spawn(Vector2i startPosition, bool colour);

	//Capture handler
	void gotCaptured();

	//Animate movement of pieces
	void animateMoves(float elapsedTime);

	//Change position (castle)
	void setPosition(Vector2i newPos);

	//Is the piece being hovered over right now
	bool isHovered();

	//Find the furthest empty tile in a given direction
	int furthestPointInDirection(Directions direction, Colour** occupiedTiles, Colour enemyColour);

	//Build a path of moves in all four diagonal directions
	void buildDiagonalPaths(Colour** occupiedTiles, Colour enemyColour, Sprite* possibleMoves);

	//Build a path of moves in both axis directions
	void buildAxisPaths(Colour** occupiedTiles, Colour enemyColour, Sprite* possibleMoves);

	Colour getEnemyColour();

	Vector2i getPosition();

	Vector2f getGlobalPosition();

	Sprite getSprite();
};
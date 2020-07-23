#include "Piece.h"

void Piece::spawn(Vector2i startPosition)
{
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	m_StartingPosition.x = startPosition.x;
	m_StartingPosition.y = startPosition.y;

	m_State = PieceState::STATIONARY;
}

void Piece::gotCaptured()
{
	m_State = PieceState::CAPTURED;

	//Any piece at position (9,9) is considered captured
	m_Position.x = 9;
	m_Position.y = 9;
}

void Piece::animateMoves()
{
	//In here we need to animate our movement. It should end with updating new positions
	//We can call this function with a state check, something like:
	//if (m_State == PieceState::MOVED) -> animateMoves()

	m_Position.x = m_NextPosition.x;
	m_Position.y = m_NextPosition.y;
	m_NextPosition = Vector2i(0, 0);

	m_State = PieceState::STATIONARY;
}

void Piece::setPosition(Vector2i newPos)
{
	m_Position.x = newPos.x;
	m_Position.y = newPos.y;
}


Vector2i Piece::getPosition()
{
	return m_Position;
}

Sprite Piece::getSprite()
{
	return m_Sprite;
}
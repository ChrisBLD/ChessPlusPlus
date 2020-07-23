#include "Piece.h"

void Piece::gotCaptured()
{
	m_InPlay = false;

	//Any piece at position (9,9) is considered captured
	m_Position.x = 9;
	m_Position.y = 9;
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
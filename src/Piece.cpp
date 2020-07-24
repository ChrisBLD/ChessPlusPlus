#include "Piece.h"
#include <iostream>

void Piece::spawn(Vector2i startPosition)
{
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	m_StartingPosition.x = startPosition.x;
	m_StartingPosition.y = startPosition.y;

	m_State = PieceState::STATIONARY;

	m_GlobalPosition.x = boardPos.x + 60 + ((m_Position.x-1) * 90);
	m_GlobalPosition.y = boardPos.y + 60 + ((8 - m_Position.y) * 90);
	m_Sprite.setPosition(m_GlobalPosition);
}

void Piece::gotCaptured()
{
	m_State = PieceState::CAPTURED;

	//Any piece at position (9,9) is considered captured
	m_Position.x = 9;
	m_Position.y = 9;
}

void Piece::animateMoves(float elapsedTime)
{
	//In here we need to animate our movement. It should end with updating new positions
	//We can call this function with a state check, something like:
	//if (m_State == PieceState::MOVED) -> animateMoves()

	m_GlobalPosition = m_Sprite.getPosition();

	int toMoveX = m_NextPosition.x - m_Position.x;
	int toMoveY = m_NextPosition.y - m_Position.y;


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

void Piece::isHovered()
{
	Vector2f mousePos = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);

	FloatRect pieceRect = FloatRect(m_GlobalPosition.x, m_GlobalPosition.y, 90, 90);

	if (pieceRect.contains(mousePos)) {
		std::cout << "PIECE BEING HOVERED OVER AT: (" << m_Position.x << ", " << m_Position.y << ")" << std::endl;
	}
}


Vector2i Piece::getPosition()
{
	return m_Position;
}

Vector2f Piece::getGlobalPosition()
{
	return m_GlobalPosition;
}

Sprite Piece::getSprite()
{
	return m_Sprite;
}
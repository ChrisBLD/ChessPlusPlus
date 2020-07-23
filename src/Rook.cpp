#include "Rook.h"
#include "TextureHolder.h"

Rook::Rook()
{
	m_Sprite.setTexture(TextureHolder::GetTexture("assets/rook.png"));

	m_InPlay = false;
}

void Rook::spawn(Vector2i startPosition)
{
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	m_StartingPosition.x = startPosition.x;
	m_StartingPosition.y = startPosition.y;

	m_InPlay = true;
}

void Rook::executeMove(bool dir, int steps)
{
	if (dir)
	{
		//Move in x direction
		m_Position.x += steps;
	}
	else
	{
		//Move in y direction
		m_Position.y += steps;
	}
}

void Rook::executeCastle(Piece& king)
{
	Vector2i temp = king.getPosition();
	king.setPosition(m_Position);
	m_Position = temp;

}
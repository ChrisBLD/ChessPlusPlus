#include "King.h"
#include "TextureHolder.h"

King::King()
{
	m_Sprite.setTexture(TextureHolder::GetTexture("assets/rook.png"));
	m_State = PieceState::NOTSPAWNED;
}

void King::executeMove(Directions direction, int steps, bool capture)
{
	switch (direction)
	{
	case Directions::NORTH:
		m_NextPosition.y = m_Position.y + 1;
		break;
	case Directions::NEAST:
		m_NextPosition.x = m_Position.x + 1;
		m_NextPosition.y = m_Position.y + 1;
		break;
	case Directions::EAST:
		m_NextPosition.x = m_Position.x + 1;
		break;
	case Directions::SEAST:
		m_NextPosition.x = m_Position.x + 1;
		m_NextPosition.y = m_Position.y - 1;
		break;
	case Directions::SOUTH:
		m_NextPosition.y = m_Position.y - 1;
		break;
	case Directions::SWEST:
		m_NextPosition.x = m_Position.x - 1;
		m_NextPosition.y = m_Position.y - 1;
		break;
	case Directions::WEST:
		m_NextPosition.x = m_Position.x - 1;
		break;
	case Directions::NWEST:
		m_NextPosition.x = m_Position.x - 1;
		m_NextPosition.y = m_Position.y + 1;
		break;
	}
}
#include "Knight.h"
#include "TextureHolder.h"

Knight::Knight()
{
	m_Sprite.setTexture(TextureHolder::GetTexture("assets/knight.png"));
	m_State = PieceState::NOTSPAWNED;
}

void Knight::executeMove(Directions direction, int steps, bool capture)
{
	/*
	NWEST |__.
						   
	NORTH |       
	      |_.           

	NEAST   |
	      ._|

	EAST .__|
	*/

	switch (direction)
	{
	case Directions::NWEST:
		m_NextPosition.x = m_Position.x - 2;
		m_NextPosition.y = m_Position.y + 1;
		break;
	case Directions::NORTH:
		m_NextPosition.x = m_Position.x - 1;
		m_NextPosition.y = m_Position.y + 2;
		break;
	case Directions::NEAST:
		m_NextPosition.x = m_Position.x + 1;
		m_NextPosition.y = m_Position.y + 2;
		break;
	case Directions::EAST:
		m_NextPosition.x = m_Position.x + 2;
		m_NextPosition.y = m_Position.y + 1;
		break;
	case Directions::SEAST:
		m_NextPosition.x = m_Position.x + 2;
		m_NextPosition.y = m_Position.y - 1;
		break;
	case Directions::SOUTH:
		m_NextPosition.x = m_Position.x + 1;
		m_NextPosition.y = m_Position.y - 2;
		break;
	case Directions::SWEST:
		m_NextPosition.x = m_Position.x - 1;
		m_NextPosition.y = m_Position.y - 2;
		break;
	case Directions::WEST:
		m_NextPosition.x = m_Position.x - 2;
		m_NextPosition.y = m_Position.y - 1;
		break;
	}

	m_State = PieceState::MOVED;
}

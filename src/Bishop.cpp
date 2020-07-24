#include "Bishop.h"
#include "TextureHolder.h"

Bishop::Bishop()
{
	m_Sprite.setTexture(TextureHolder::GetTexture("assets/bishop.png"));
	m_State = PieceState::NOTSPAWNED;
}

void Bishop::executeMove(Directions direction, int steps, bool capture)
{
	switch (direction)
	{
	case Directions::NEAST:
		m_NextPosition.y = m_Position.y + steps;
		m_NextPosition.x = m_Position.x + steps;
		break;
	case Directions::SEAST:
		m_NextPosition.y = m_Position.y - steps;
		m_NextPosition.x = m_Position.x + steps;
		break;
	case Directions::SWEST:
		m_NextPosition.y = m_Position.y - steps;
		m_NextPosition.x = m_Position.x - steps;
		break;
	case Directions::NWEST:
		m_NextPosition.y = m_Position.y + steps;
		m_NextPosition.x = m_Position.x - steps;
		break;
	}

	m_State = PieceState::MOVED;
}

void Bishop::showPossibleMoves(Colour** occupiedTiles)
{
}
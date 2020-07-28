#include "Queen.h"
#include "TextureHolder.h"

Queen::Queen()
{
	m_Sprite.setTexture(TextureHolder::GetTexture("assets/queen.png"));
	m_State = PieceState::NOTSPAWNED;
}

void Queen::executeMove(Directions direction, int steps, bool capture)
{
	switch (direction)
	{
	case Directions::NORTH:
		m_NextPosition.y = m_Position.y + steps;
		break;
	case Directions::NEAST:
		m_NextPosition.x = m_Position.x + steps;
		m_NextPosition.y = m_Position.y + steps;
		break;
	case Directions::EAST:
		m_NextPosition.x = m_Position.x + steps;
		break;
	case Directions::SEAST:
		m_NextPosition.x = m_Position.x + steps;
		m_NextPosition.y = m_Position.y - steps;
		break;
	case Directions::SOUTH:
		m_NextPosition.y = m_Position.y - steps;
		break;
	case Directions::SWEST:
		m_NextPosition.x = m_Position.x - steps;
		m_NextPosition.y = m_Position.y - steps;
		break;
	case Directions::WEST:
		m_NextPosition.x = m_Position.x - steps;
		break;
	case Directions::NWEST:
		m_NextPosition.x = m_Position.x - steps;
		m_NextPosition.y = m_Position.y + steps;
		break;
	}

	m_State = PieceState::MOVED;
}


void Queen::showPossibleMoves(Colour** occupiedTiles)
{
	Colour enemyColour = getEnemyColour();

	buildDiagonalPaths(occupiedTiles, enemyColour, possibleMovesDiag);
	buildAxisPaths(occupiedTiles, enemyColour, possibleMovesAxis);

	for (int i = 0; i < 13; i++)
	{
		possibleMoves[i] = possibleMovesDiag[i];
	}

	possibleMoves[13] = possibleMovesAxis[0];
	possibleMoves[14] = possibleMovesAxis[1];
	possibleMoves[15] = possibleMovesAxis[2];
	possibleMoves[16] = possibleMovesAxis[3];

}

Sprite* Queen::getPossibleMoves()
{
	return possibleMoves;
}

PieceState Queen::getPieceState()
{
	return m_State;
}
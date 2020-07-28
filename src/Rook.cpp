#include "Rook.h"
#include "TextureHolder.h"
#include <iostream>

Rook::Rook()
{
	m_Sprite.setTexture(TextureHolder::GetTexture("assets/rook.png"));
	m_State = PieceState::NOTSPAWNED;
}


void Rook::executeMove(Directions direction, int steps, bool capture)
{
	switch (direction)
	{
	case Directions::NORTH:
		m_NextPosition.y = m_Position.y + steps;
		break;
	case Directions::EAST:
		m_NextPosition.x = m_Position.x + steps;
		break;
	case Directions::SOUTH:
		m_NextPosition.y = m_Position.y - steps;
		break;
	case Directions::WEST:
		m_NextPosition.x = m_Position.x - steps;
	}

	m_State = PieceState::MOVED;
}

//Move the rook to the correct position in a castle move
void Rook::executeCastle(bool dir)
{
	if (dir)
	{
		//Queen side castle: move 3 to the right
		m_NextPosition.x = m_Position.x + 3;
	}
	else
	{
		//King side castle: move 2 to the left
		m_NextPosition.x = m_Position.x - 2;
	}

	m_State = PieceState::MOVED;
}

void Rook::showPossibleMoves(Colour** occupiedTiles)
{
	Colour enemyColour = getEnemyColour();

	buildAxisPaths(occupiedTiles, enemyColour, possibleMoves);
}

Sprite* Rook::getPossibleMoves()
{
	return possibleMoves;
}

PieceState Rook::getPieceState()
{
	return m_State;
}
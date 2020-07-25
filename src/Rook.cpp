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

	//For axis moves, we will use a single position object and stretch it as required.
	int furthestXLeft = furthestPointInDirection(Directions::WEST, occupiedTiles, enemyColour);
	int furthestXRight = furthestPointInDirection(Directions::EAST, occupiedTiles, enemyColour);
	int furthestYUp = furthestPointInDirection(Directions::NORTH, occupiedTiles, enemyColour);
	int furthestYDown = furthestPointInDirection(Directions::SOUTH, occupiedTiles, enemyColour);

	std::cout << furthestXLeft << " " << furthestXRight << " " << furthestYUp << " " << furthestYDown << endl;

	if (furthestXLeft != m_Position.x)
	{
		int diff = m_Position.x - furthestXLeft;
		possibleMoves[0].setPosition(m_GlobalPosition.x - (TILE_SIZE * diff), m_GlobalPosition.y);
		possibleMoves[0].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
		possibleMoves[0].setScale(diff, 1.0f);
	}

	if (furthestXRight != m_Position.x)
	{
		int diff = furthestXRight - m_Position.x;
		possibleMoves[1].setPosition(m_GlobalPosition.x + TILE_SIZE, m_GlobalPosition.y);
		possibleMoves[1].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
		possibleMoves[1].setScale(diff, 1.0f);
	}

	if (furthestYUp != m_Position.y)
	{
		int diff = furthestYUp - m_Position.y;
		possibleMoves[2].setPosition(m_GlobalPosition.x, m_GlobalPosition.y - (TILE_SIZE * diff));
		possibleMoves[2].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
		possibleMoves[2].setScale(1.0f, diff);
	}

	if (furthestYDown != m_Position.y)
	{
		int diff = m_Position.y - furthestYDown;
		possibleMoves[3].setPosition(m_GlobalPosition.x, m_GlobalPosition.y + TILE_SIZE);
		possibleMoves[3].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
		possibleMoves[3].setScale(1.0f, diff);
	}
}

Sprite* Rook::getPossibleMoves()
{
	return possibleMoves;
}

PieceState Rook::getPieceState()
{
	return m_State;
}
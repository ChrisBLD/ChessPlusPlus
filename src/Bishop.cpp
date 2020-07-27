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
	Colour enemyColour = getEnemyColour();

	//For a diagonal move, we will have to use individual sprites
	int furthestNE = furthestPointInDirection(Directions::NEAST, occupiedTiles, enemyColour);
	int furthestNW = furthestPointInDirection(Directions::NWEST, occupiedTiles, enemyColour);
	int furthestSW = furthestPointInDirection(Directions::SWEST, occupiedTiles, enemyColour);
	int furthestSE = furthestPointInDirection(Directions::SEAST, occupiedTiles, enemyColour);

	int currentElement = furthestNW - m_Position.y;

	for (int i = 0; i < currentElement; i++)
	{
		int localX = m_GlobalPosition.x - (TILE_SIZE * (i+1));
		int localY = m_GlobalPosition.y - (TILE_SIZE * (i+1));

		if (!(localX > MAX_X) && !(localX < MIN_X) && !(localY > MAX_Y) && !(localY < MIN_Y) && m_Position.y)
		{
			possibleMoves[i].setPosition(localX, localY);
			possibleMoves[i].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
		}
	}


	for (int i = currentElement; i < (currentElement + furthestNE - m_Position.y); i++)
	{
		int localX = m_GlobalPosition.x + (TILE_SIZE * (i - currentElement + 1));
		int localY = m_GlobalPosition.y - (TILE_SIZE * (i - currentElement + 1));

		if (!(localX > MAX_X) && !(localX < MIN_X) && !(localY > MAX_Y) && !(localY < MIN_Y) && m_Position.y)
		{
			possibleMoves[i].setPosition(localX, localY);
			possibleMoves[i].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
		}
	}

	currentElement += furthestNE - m_Position.y;

	for (int i = currentElement; i < (currentElement + m_Position.y - furthestSE); i++)
	{
		int localX = m_GlobalPosition.x + (TILE_SIZE * (i - currentElement + 1));
		int localY = m_GlobalPosition.y + (TILE_SIZE * (i - currentElement + 1));

		if (!(localX > MAX_X) && !(localX < MIN_X) && !(localY > MAX_Y) && !(localY < MIN_Y) && m_Position.y)
		{
			possibleMoves[i].setPosition(localX, localY);
			possibleMoves[i].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
		}
	}
}


Sprite* Bishop::getPossibleMoves()
{
	return possibleMoves;
}

PieceState Bishop::getPieceState()
{
	return m_State;
}
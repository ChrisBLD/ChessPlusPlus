#include "King.h"
#include "TextureHolder.h"
#include <iostream>

King::King()
{
	m_Sprite.setTexture(TextureHolder::GetTexture("assets/king.png"));
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

void King::showPossibleMoves(Colour** occupiedTiles)
{

	//Place possible moves surrounding the king in a square
	possibleMoves[0].setPosition(m_GlobalPosition.x - TILE_SIZE, m_GlobalPosition.y + TILE_SIZE); //SWEST (3,3)
	possibleMoves[1].setPosition(m_GlobalPosition.x - TILE_SIZE, m_GlobalPosition.y);             //WEST  (3,4)
	possibleMoves[2].setPosition(m_GlobalPosition.x - TILE_SIZE, m_GlobalPosition.y - TILE_SIZE); //NWEST (3,5)
	possibleMoves[3].setPosition(m_GlobalPosition.x, m_GlobalPosition.y - TILE_SIZE);             //NORTH (4,5)
	possibleMoves[4].setPosition(m_GlobalPosition.x + TILE_SIZE, m_GlobalPosition.y - TILE_SIZE); //NEAST (5,5)
	possibleMoves[5].setPosition(m_GlobalPosition.x + TILE_SIZE, m_GlobalPosition.y);             //EAST  (5,4)
	possibleMoves[6].setPosition(m_GlobalPosition.x + TILE_SIZE, m_GlobalPosition.y + TILE_SIZE); //SEAST (5,3)
	possibleMoves[7].setPosition(m_GlobalPosition.x, m_GlobalPosition.y + TILE_SIZE);             //SOUTH (4,3)

	//std::map<int, int> valMap = { {720, 2}, {630, 3}, {540, 4}, {450, 5}, {360, 0}};

	for (int i = 0; i < 8; i++)
	{

		if (!(possibleMoves[i].getPosition().x > MAX_X) && !(possibleMoves[i].getPosition().x < MIN_X)
			&& !(possibleMoves[i].getPosition().y > MAX_Y) && !(possibleMoves[i].getPosition().y < MIN_Y))
		{
			int localX = (possibleMoves[i].getPosition().x - boardPos.x + TILE_SIZE) / 90;
			int localY = (((int)possibleMoves[i].getPosition().y % 100) / 10);
		
			//Position inside game board, so we can give it a sprite if there's no friendly there.
			if (occupiedTiles[localX][localY] != m_Colour)
			{
				possibleMoves[i].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
			}
		}
	}

	//TODO: King can't move into positions that put it in check(mate).
}

Sprite* King::getPossibleMoves()
{
	return possibleMoves;
}

PieceState King::getPieceState()
{
	return m_State;
}
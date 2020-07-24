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
	bool spritesToShow[8];
	for (int i = 0; i < 7; i++)
	{
		spritesToShow[i] = false;
	}

	//Place possible moves surrounding the king in a square
	possibleMoves[0].setPosition(m_GlobalPosition.x - TILE_SIZE, m_GlobalPosition.y - TILE_SIZE);
	possibleMoves[1].setPosition(m_GlobalPosition.x, m_GlobalPosition.y - TILE_SIZE);
	possibleMoves[2].setPosition(m_GlobalPosition.x + TILE_SIZE, m_GlobalPosition.y - TILE_SIZE);
	possibleMoves[3].setPosition(m_GlobalPosition.x + TILE_SIZE, m_GlobalPosition.y);
	possibleMoves[4].setPosition(m_GlobalPosition.x + TILE_SIZE, m_GlobalPosition.y + TILE_SIZE);
	possibleMoves[5].setPosition(m_GlobalPosition.x, m_GlobalPosition.y + TILE_SIZE);
	possibleMoves[6].setPosition(m_GlobalPosition.x - TILE_SIZE, m_GlobalPosition.y + TILE_SIZE);
	possibleMoves[7].setPosition(m_GlobalPosition.x - TILE_SIZE, m_GlobalPosition.y);

	for (int i = 0; i < 8; i++)
	{
		if (!(possibleMoves[i].getPosition().x > MAX_X) && !(possibleMoves[i].getPosition().x < MIN_X)
			&& !(possibleMoves[i].getPosition().y > MAX_Y) && !(possibleMoves[i].getPosition().y < MIN_Y))
		{
			int localX = (possibleMoves[i].getPosition().x - boardPos.x + 90) / 90;
			int localY = (possibleMoves[i].getPosition().y - boardPos.y + 90) / 90;

			//Position inside game board, so we can give it a sprite if there's no friendly there.
			if (occupiedTiles[localX][localY] != m_Colour)
			{
				possibleMoves[i].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
			}
		}
	}

}

Sprite* King::getPossibleMoves()
{
	return possibleMoves;
}

PieceState King::getPieceState()
{
	return m_State;
}
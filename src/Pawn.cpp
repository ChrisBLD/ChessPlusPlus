#include "Pawn.h"
#include "TextureHolder.h"

Pawn::Pawn()
{
	m_Sprite.setTexture(TextureHolder::GetTexture("assets/pawn.png"));
	m_State = PieceState::NOTSPAWNED;
}


void Pawn::executeMove(Directions direction, int steps, bool capture)
{
	//Capture: Move (+1,+1) in direction
	if (capture)
	{
		switch (direction)
		{
		case Directions::NEAST:
			m_NextPosition.y = m_Position.y + 1;
			m_NextPosition.x = m_Position.x + 1;
			break;
		case Directions::NWEST:
			m_NextPosition.y = m_Position.y + 1;
			m_NextPosition.x = m_Position.x - 1;
			break;
		}
	}
	//No capture: Either move +2 from start or +1 normal
	else {
		if (steps == 2)
		{
			m_NextPosition.y = m_Position.y + 2;
		}
		else
		{
			m_NextPosition.y = m_Position.y + 1;
		}
	}

	m_State = PieceState::MOVED;
}


void Pawn::executeEnPassant(bool dir)
{
	if (dir)
	{
		executeMove(Directions::NWEST, 1, true);
	}
	else
	{
		executeMove(Directions::NEAST, 1, true);
	}
	
}

void Pawn::showPossibleMoves(Colour** occupiedTiles)
{
	Colour enemyColour;

	if (m_Colour == Colour::WHITE)
	{
		enemyColour = Colour::BLACK;
	} 
	else
	{
		enemyColour = Colour::WHITE;
	}

	//Place the possible move tiles in an arrow ahead of the pawn
	possibleMoves[0].setPosition(m_GlobalPosition.x, m_GlobalPosition.y - TILE_SIZE);
	possibleMoves[1].setPosition(m_GlobalPosition.x, m_GlobalPosition.y - (TILE_SIZE * 2));
	possibleMoves[2].setPosition(m_GlobalPosition.x - TILE_SIZE, m_GlobalPosition.y - TILE_SIZE);
	possibleMoves[3].setPosition(m_GlobalPosition.x + TILE_SIZE, m_GlobalPosition.y - TILE_SIZE);

	for (int i = 0; i < 4; i++)
	{

		if (!(possibleMoves[i].getPosition().x > MAX_X) && !(possibleMoves[i].getPosition().x < MIN_X)
			&& !(possibleMoves[i].getPosition().y > MAX_Y) && !(possibleMoves[i].getPosition().y < MIN_Y))
		{
			int localX = (possibleMoves[i].getPosition().x - boardPos.x + TILE_SIZE) / 90;
			int localY = (((int)possibleMoves[i].getPosition().y % 100) / 10);

			//Position inside game board, so we can give it a sprite if there's no friendly there.
			if (occupiedTiles[localX][localY] != m_Colour)
			{
				if (i == 1)
				{
					//If the pawn isn't on the starting square, it can't do a double move.
					if (m_Position.y == m_StartingPosition.y)
					{
						possibleMoves[i].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
					}
				}
				else if (i == 2 || i == 3)
				{
					if (occupiedTiles[localX][localY] == enemyColour)
					{
						possibleMoves[i].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
					}
				}
				else
				{
					possibleMoves[i].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
				}
			}
		}
	}

}

Sprite* Pawn::getPossibleMoves()
{
	return possibleMoves;
}

PieceState Pawn::getPieceState()
{
	return m_State;
}
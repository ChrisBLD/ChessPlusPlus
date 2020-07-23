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
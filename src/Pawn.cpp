#include "Pawn.h"
#include "TextureHolder.h"

Pawn::Pawn()
{
	m_Sprite.setTexture(TextureHolder::GetTexture("assets/pawn.png"));

	m_InPlay = false;

	m_Movement.infiniteX = false;
	m_Movement.infiniteY = false;
	m_Movement.infiniteDiag = false;

	m_Movement.normalX = 0;
	m_Movement.normalY = 1;
	m_Movement.normalDiag = 0;
}

void Pawn::spawn(Vector2i startPosition)
{
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	m_StartingPosition.x = startPosition.x;
	m_StartingPosition.y = startPosition.y;
}

void Pawn::executeMoveNoCapture(bool dub)
{
	if (dub)
	{
		m_Position.y += 2;
	}
	else
	{
		m_Position.y++;
	}
}

void Pawn::executeMoveCapture(bool dir)
{
	if (dir)
	{
		//Capture left
		m_Position.x--;
		m_Position.y++;
	}
}

bool Pawn::canDoubleMove()
{
	if (m_StartingPosition.y == m_Position.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

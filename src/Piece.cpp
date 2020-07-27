#include "Piece.h"
#include <iostream>

void Piece::spawn(Vector2i startPosition, bool colour)
{
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	m_StartingPosition.x = startPosition.x;
	m_StartingPosition.y = startPosition.y;

	m_State = PieceState::STATIONARY;

	m_GlobalPosition.x = boardPos.x + 60 + ((m_Position.x-1) * 90);
	m_GlobalPosition.y = boardPos.y + 60 + ((8 - m_Position.y) * 90);
	m_Sprite.setPosition(m_GlobalPosition);

	m_Colour = (colour) ? Colour::WHITE : Colour::BLACK;
}

void Piece::gotCaptured()
{
	m_State = PieceState::CAPTURED;

	//Any piece at position (9,9) is considered captured
	m_Position.x = 9;
	m_Position.y = 9;
}

void Piece::animateMoves(float elapsedTime)
{
	//In here we need to animate our movement. It should end with updating new positions
	//We can call this function with a state check, something like:
	//if (m_State == PieceState::MOVED) -> animateMoves()

	m_GlobalPosition = m_Sprite.getPosition();

	int toMoveX = m_NextPosition.x - m_Position.x;
	int toMoveY = m_NextPosition.y - m_Position.y;


	m_Position.x = m_NextPosition.x;
	m_Position.y = m_NextPosition.y;
	m_NextPosition = Vector2i(0, 0);

	m_State = PieceState::STATIONARY;
}

void Piece::setPosition(Vector2i newPos)
{
	m_Position.x = newPos.x;
	m_Position.y = newPos.y;
}

bool Piece::isHovered()
{
	if (m_State != PieceState::CAPTURED && m_State != PieceState::NOTMOVABLE && m_State != PieceState::NOTSPAWNED) {
		Vector2f mousePos = Vector2f(Mouse::getPosition().x, Mouse::getPosition().y);

		FloatRect pieceRect = FloatRect(m_GlobalPosition.x, m_GlobalPosition.y, 90, 90);

		if (pieceRect.contains(mousePos) && m_State != PieceState::HOVERED) {
			std::cout << "PIECE HOVERED: (" << m_Position.x << ", " << m_Position.y << ")" << std::endl;
			m_State = PieceState::HOVERED;
		}
		else if (!pieceRect.contains(mousePos) && m_State == PieceState::HOVERED) {
			std::cout << "PIECE UN-HOVERED: (" << m_Position.x << ", " << m_Position.y << ")" << std::endl;
			m_State = PieceState::STATIONARY;
		}
		//std::cout << "PIECE AT: (" << m_Position.x << ", " << m_Position.y << ")" << std::endl;
	}

	if (m_State == PieceState::HOVERED)
	{
		return true;
	}

	return false;
}

int Piece::furthestPointInDirection(Directions direction, Colour** occupiedTiles, Colour enemyColour)
{
	int x = m_Position.x;
	int y = m_Position.y;

	switch (direction)
	{
	case Directions::NORTH:
		if (y == 8)
		{
			return y;
		}
		y++;
		while (occupiedTiles[x][y] == Colour::NONE)
		{
			y++;
			if (y == 9)
			{
				return 8;
			}
		}
		if (occupiedTiles[x][y] == enemyColour)
		{
			return y;
		}
		return y - 1;
	case Directions::EAST:
		if (x == 8)
		{
			return x;
		}
		x++;
		while (occupiedTiles[x][y] == Colour::NONE)
		{
			x++;
			if (x == 9)
			{
				return 8;
			}
		}
		if (occupiedTiles[x][y] == enemyColour)
		{
			return x;
		}
		return x - 1;
	case Directions::SOUTH:
		if (y == 1)
		{
			return y;
		}
		y--;
		while (occupiedTiles[x][y] == Colour::NONE)
		{
			y--;
			if (y == 0)
			{
				return 1;
			}
		}
		if (occupiedTiles[x][y] == enemyColour)
		{
			return y;
		}
		return y + 1;
	case Directions::WEST:
		if (x == 1)
		{
			return x;
		}
		x--;
		while (occupiedTiles[x][y] == Colour::NONE)
		{
			x--;
			if (x == 0)
			{
				return 1;
			}
		}
		if (occupiedTiles[x][y] == enemyColour)
		{
			return x;
		}
		return x + 1;


	case Directions::NWEST:
		if (y == 8 || x == 1)
		{
			return y;
		}
		x--;
		y++;
		while (occupiedTiles[x][y] == Colour::NONE)
		{
			x--;
			y++;
			if (y == 9 || x == 0)
			{
				return y-1;
			}
		}
		if (occupiedTiles[x][y] == enemyColour)
		{
			return y;
		}
		return y--;
	case Directions::NEAST:
		if (y == 8 || x == 8)
		{
			return y;
		}
		x++;
		y++;
		while (occupiedTiles[x][y] == Colour::NONE)
		{
			x++;
			y++;
			if (y == 9 || x == 9)
			{
				return y-1;
			}
		}
		if (occupiedTiles[x][y] == enemyColour)
		{
			return y;
		}
		return y--;
	case Directions::SEAST:
		if (y == 0 || x == 8)
		{
			return y;
		}
		x++;
		y--;
		while (occupiedTiles[x][y] == Colour::NONE)
		{
			x++;
			y--;
			if (y == 0 || x == 9)
			{
				return y;
			}
		}
		if (occupiedTiles[x][y] == enemyColour)
		{
			return y;
		}
		return y++;
	}
}

Colour Piece::getEnemyColour()
{
	if (m_Colour == Colour::WHITE)
	{
		return Colour::BLACK;
	}
	else
	{
		return Colour::WHITE;
	}
}

Vector2i Piece::getPosition()
{
	return m_Position;
}

Vector2f Piece::getGlobalPosition()
{
	return m_GlobalPosition;
}

Sprite Piece::getSprite()
{
	return m_Sprite;
}
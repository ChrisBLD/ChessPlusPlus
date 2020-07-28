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
		return y + 1;
	case Directions::SWEST:
		if (y == 0 || x == 0)
		{
			return 1;
		}
		x--;
		y--;
		while (occupiedTiles[x][y] == Colour::NONE)
		{
			x--;
			y--;
			if (y == 0 || x == 0)
			{
				return 1;
			}
		}
		if (occupiedTiles[x][y] == enemyColour)
		{
			return y;
		}
		return y + 1;
	}

}

void Piece::buildDiagonalPaths(Colour** occupiedTiles, Colour enemyColour, Sprite* possibleMoves)
{
	//For a diagonal move, we will have to use individual sprites
	int furthestNE = furthestPointInDirection(Directions::NEAST, occupiedTiles, enemyColour);
	int furthestNW = furthestPointInDirection(Directions::NWEST, occupiedTiles, enemyColour);
	int furthestSW = furthestPointInDirection(Directions::SWEST, occupiedTiles, enemyColour);
	int furthestSE = furthestPointInDirection(Directions::SEAST, occupiedTiles, enemyColour);

	int currentElement = furthestNW - m_Position.y;

	for (int i = 0; i < currentElement; i++)
	{
		int localX = m_GlobalPosition.x - (TILE_SIZE * (i + 1));
		int localY = m_GlobalPosition.y - (TILE_SIZE * (i + 1));

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

	currentElement += furthestSE + m_Position.y;

	for (int i = currentElement; i < (currentElement + m_Position.y - furthestSW); i++)
	{
		int localX = m_GlobalPosition.x - (TILE_SIZE * (i - currentElement + 1));
		int localY = m_GlobalPosition.y + (TILE_SIZE * (i - currentElement + 1));

		if (!(localX > MAX_X) && !(localX < MIN_X) && !(localY > MAX_Y) && !(localY < MIN_Y) && m_Position.y)
		{
			possibleMoves[i].setPosition(localX, localY);
			possibleMoves[i].setTexture(TextureHolder::GetTexture("assets/validmove.png"));
		}
	}
}

void Piece::buildAxisPaths(Colour** occupiedTiles, Colour enemyColour, Sprite* possibleMoves)
{
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
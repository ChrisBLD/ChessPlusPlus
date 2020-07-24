#include "GameLogic.h"

GameLogic::GameLogic()
{

}

void GameLogic::startGame()
{
	//We begin the game here
	m_GameState = InGameState::WHITE_TURN;

	//Initialise occupied tracking array with all false values
	for (int x = 1; x < 9; x++)
	{
		m_Occupied[x] = new bool[9];
	}

	for (int x = 1; x < 9; x++)
	{
		for (int y = 1; y < 9; y++)
		{
			m_Occupied[x][y] = false;
		}
	}

	for (int i = 1; i < 9; i++)
	{
		whitePawn[i].spawn(Vector2i(i,2));
		blackPawn[i].spawn(Vector2i(i, 7));
		m_Occupied[i][2] = true;
		m_Occupied[i][7] = true;
	}

	whiteRook[0].spawn(Vector2i(1, 1));
	blackRook[0].spawn(Vector2i(1, 8));
	m_Occupied[1][1] = true;
	m_Occupied[1][8] = true;

	whiteRook[1].spawn(Vector2i(8, 1));
	blackRook[1].spawn(Vector2i(8, 8));
	m_Occupied[8][1] = true;
	m_Occupied[8][8] = true;

	whiteKnight[0].spawn(Vector2i(2, 1));
	blackKnight[0].spawn(Vector2i(2, 8));
	m_Occupied[2][1] = true;
	m_Occupied[2][8] = true;

	whiteKnight[1].spawn(Vector2i(7, 1));
	blackKnight[1].spawn(Vector2i(7, 8));
	m_Occupied[7][1] = true;
	m_Occupied[7][8] = true;

	whiteBishop[0].spawn(Vector2i(3, 1));
	blackBishop[0].spawn(Vector2i(3, 8));
	m_Occupied[3][1] = true;
	m_Occupied[3][8] = true;

	whiteBishop[1].spawn(Vector2i(6, 1));
	blackBishop[1].spawn(Vector2i(6, 8));
	m_Occupied[6][1] = true;
	m_Occupied[6][8] = true;

	whiteKing.spawn(Vector2i(5, 1));
	blackKing.spawn(Vector2i(5, 8));
	m_Occupied[5][1] = true;
	m_Occupied[5][8] = true;

	whiteQueen[0].spawn(Vector2i(4, 1));
	blackQueen[0].spawn(Vector2i(4, 8));
	m_Occupied[4][1] = true;
	m_Occupied[4][8] = true;
	
}

void GameLogic::checkHovered()
{
	for (int i = 1; i < 9; i++)
	{
		whitePawn[i].isHovered();
		blackPawn[i].isHovered();
	}

	whiteRook[0].isHovered();
	blackRook[0].isHovered();

	whiteRook[1].isHovered();
	blackRook[1].isHovered();

	whiteKnight[0].isHovered();
	blackKnight[0].isHovered();

	whiteKnight[1].isHovered();
	blackKnight[1].isHovered();

	whiteBishop[0].isHovered();
	blackBishop[0].isHovered();

	whiteBishop[1].isHovered();
	blackBishop[1].isHovered();

	whiteKing.isHovered();
	blackKing.isHovered();

	whiteQueen[0].isHovered();
	blackQueen[0].isHovered();
	
}
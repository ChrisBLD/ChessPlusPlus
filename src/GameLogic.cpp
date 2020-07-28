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
		m_Occupied[x] = new Colour[9];
	}

	for (int x = 1; x < 9; x++)
	{
		for (int y = 1; y < 9; y++)
		{
			m_Occupied[x][y] = Colour::NONE;
		}
	}

	for (int i = 1; i < 9; i++)
	{
		//whitePawn[i].spawn(Vector2i(i,2), true);
		blackPawn[i].spawn(Vector2i(i, 7), false);
		//m_Occupied[i][2] = Colour::WHITE;
		m_Occupied[i][7] = Colour::BLACK;
	}

	whiteRook[0].spawn(Vector2i(1, 1), true);
	blackRook[0].spawn(Vector2i(1, 8), false);
	m_Occupied[1][1] = Colour::WHITE;
	m_Occupied[1][8] = Colour::BLACK;

	whiteRook[1].spawn(Vector2i(8, 1), true);
	blackRook[1].spawn(Vector2i(8, 8), false);
	m_Occupied[8][1] = Colour::WHITE;
	m_Occupied[8][8] = Colour::BLACK;

	whiteKnight[0].spawn(Vector2i(2, 1), true);
	blackKnight[0].spawn(Vector2i(2, 8), false);
	m_Occupied[2][1] = Colour::WHITE;
	m_Occupied[2][8] = Colour::BLACK;

	whiteKnight[1].spawn(Vector2i(7, 1), true);
	blackKnight[1].spawn(Vector2i(7, 8), false);
	m_Occupied[7][1] = Colour::WHITE;
	m_Occupied[7][8] = Colour::BLACK;

	whiteBishop[0].spawn(Vector2i(3, 3), true);
	blackBishop[0].spawn(Vector2i(3, 8), false);
	m_Occupied[3][3] = Colour::WHITE;
	m_Occupied[3][8] = Colour::BLACK;

	whiteBishop[1].spawn(Vector2i(6, 1), true);
	blackBishop[1].spawn(Vector2i(6, 8), false);
	m_Occupied[6][1] = Colour::WHITE;
	m_Occupied[6][8] = Colour::BLACK;

	whiteKing.spawn(Vector2i(4, 6), true);
	blackKing.spawn(Vector2i(5, 8), false);
	m_Occupied[4][6] = Colour::WHITE;
	m_Occupied[5][8] = Colour::BLACK;

	whiteQueen[0].spawn(Vector2i(4, 1), true);
	blackQueen[0].spawn(Vector2i(4, 8), false);
	m_Occupied[4][1] = Colour::WHITE;
	m_Occupied[4][8] = Colour::BLACK;
	
}

void GameLogic::checkHovered()
{

	if (m_GameState == InGameState::WHITE_TURN) {
		for (int i = 1; i < 9; i++)
		{
			if (whitePawn[i].isHovered())
			{
				whitePawn[i].showPossibleMoves(m_Occupied);
			}
		}
		if (whiteRook[0].isHovered())
		{
			whiteRook[0].showPossibleMoves(m_Occupied);
		}
		if (whiteRook[1].isHovered())
		{
			whiteRook[1].showPossibleMoves(m_Occupied);
		}
		whiteKnight[0].isHovered();
		whiteKnight[1].isHovered();

		if (whiteBishop[0].isHovered())
		{
			whiteBishop[0].showPossibleMoves(m_Occupied);
		}
		if (whiteBishop[1].isHovered())
		{
			whiteBishop[1].showPossibleMoves(m_Occupied);
		}
		if (whiteKing.isHovered()) {
			whiteKing.showPossibleMoves(m_Occupied);
		}
		whiteQueen[0].isHovered();
	} 
	else if (m_GameState == InGameState::BLACK_TURN)
	{
		for (int i = 1; i < 9; i++)
		{
			blackPawn[i].isHovered();
		}

		blackRook[0].isHovered();
		blackRook[1].isHovered();
		blackKnight[0].isHovered();
		blackKnight[1].isHovered();
		blackBishop[0].isHovered();
		blackBishop[1].isHovered();
		blackKing.isHovered();
		blackQueen[0].isHovered();
	}
	
}
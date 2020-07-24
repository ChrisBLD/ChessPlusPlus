#pragma once
#include "Definitions.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"

class GameLogic
{
private:

	//Define a game state for us to monitor turns
	InGameState m_GameState = InGameState::NOTPLAYING;

	//2D int array to track occupied tiles
	Colour** m_Occupied = new Colour *[9];

public:

	//Store all white pieces. Extra spaces are for promotion.
	King whiteKing;
	Queen whiteQueen[4];
	Bishop whiteBishop[4];
	Rook whiteRook[4];
	Knight whiteKnight[4];
	Pawn whitePawn[9];

	//Store all black pieces.
	King blackKing;
	Queen blackQueen[4];
	Bishop blackBishop[4];
	Rook blackRook[4];
	Knight blackKnight[4];
	Pawn blackPawn[9];

	GameLogic();

	void startGame();
	void checkHovered();
};
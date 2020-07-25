#include "Engine.h"
#include <iostream>

void Engine::draw()
{
	m_Window.clear(Color::Cyan);

	if (state == State::MENU)
	{
		//m_UI.getMenu()->getStartText()->setFillColor(Color::Red);
		//Made text elements editable
		m_Window.draw(m_UI.getMenu()->getMainMenuSprite());
		m_Window.draw(*m_UI.getMenu()->getStartText());
		m_Window.draw(*m_UI.getMenu()->getExitText());
	}

	if (state == State::PLAYING)
	{
		//std::cout << "Turn State" << endl;
		m_Window.draw(m_UI.getSpriteBoard());
		
		for (int i = 0; i < 8; i++)
		{
			m_Window.draw(m_GL.whitePawn[i + 1].getSprite());
			m_Window.draw(m_GL.blackPawn[i + 1].getSprite());
			if (i < 2)
			{
				m_Window.draw(m_GL.whiteRook[i].getSprite());
				m_Window.draw(m_GL.blackRook[i].getSprite());

				m_Window.draw(m_GL.whiteKnight[i].getSprite());
				m_Window.draw(m_GL.blackKnight[i].getSprite());

				m_Window.draw(m_GL.whiteBishop[i].getSprite());
				m_Window.draw(m_GL.blackBishop[i].getSprite());
			}
		}
		m_Window.draw(m_GL.whiteKing.getSprite());
		m_Window.draw(m_GL.whiteQueen[0].getSprite());

		m_Window.draw(m_GL.blackKing.getSprite());
		m_Window.draw(m_GL.blackQueen[0].getSprite());

		if (m_GL.whiteKing.getPieceState() == PieceState::HOVERED) {
			m_Window.draw(m_GL.whiteKing.getPossibleMoves()[0]);
			m_Window.draw(m_GL.whiteKing.getPossibleMoves()[1]);
			m_Window.draw(m_GL.whiteKing.getPossibleMoves()[2]);
			m_Window.draw(m_GL.whiteKing.getPossibleMoves()[3]);
			m_Window.draw(m_GL.whiteKing.getPossibleMoves()[4]);
			m_Window.draw(m_GL.whiteKing.getPossibleMoves()[5]);
			m_Window.draw(m_GL.whiteKing.getPossibleMoves()[6]);
			m_Window.draw(m_GL.whiteKing.getPossibleMoves()[7]);
		}

		for (int i = 1; i < 9; i++)
		{
			if (m_GL.whitePawn[i].getPieceState() == PieceState::HOVERED)
			{
				m_Window.draw(m_GL.whitePawn[i].getPossibleMoves()[0]);
				m_Window.draw(m_GL.whitePawn[i].getPossibleMoves()[1]);
				m_Window.draw(m_GL.whitePawn[i].getPossibleMoves()[2]);
				m_Window.draw(m_GL.whitePawn[i].getPossibleMoves()[3]);
			}
		}

		if (m_GL.whiteRook[0].getPieceState() == PieceState::HOVERED)
		{
			m_Window.draw(m_GL.whiteRook[0].getPossibleMoves()[0]);
			m_Window.draw(m_GL.whiteRook[0].getPossibleMoves()[1]);
			m_Window.draw(m_GL.whiteRook[0].getPossibleMoves()[2]);
			m_Window.draw(m_GL.whiteRook[0].getPossibleMoves()[3]);
		}
	}

	if (state == State::PAUSED)
	{
		m_Window.draw(m_UI.getPauseBackground());
		m_Window.draw(*m_UI.getMenu()->getExitText());
	}
	//m_Window.draw(m_UI.getSpriteBoard());

	


	m_Window.display();
}
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
			for (int i = 0; i < 8; i++)
			{
				m_Window.draw(m_GL.whiteKing.getPossibleMoves()[i]);
			}
		}

		for (int i = 1; i < 9; i++)
		{
			if (m_GL.whitePawn[i].getPieceState() == PieceState::HOVERED)
			{
				for (int j = 0; j < 4; j++)
				{
					m_Window.draw(m_GL.whitePawn[i].getPossibleMoves()[j]);
				}
			}
		}

		if (m_GL.whiteBishop[0].getPieceState() == PieceState::HOVERED)
		{
			for (int i = 0; i < 13; i++)
			{
				m_Window.draw(m_GL.whiteBishop[0].getPossibleMoves()[i]);
			}
		}

		if (m_GL.whiteRook[0].getPieceState() == PieceState::HOVERED)
		{
			for (int i = 0; i < 4; i++)
			{
				m_Window.draw(m_GL.whiteRook[0].getPossibleMoves()[i]);
			}
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
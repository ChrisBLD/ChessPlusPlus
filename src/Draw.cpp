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
	}

	if (state == State::PAUSED)
	{
		m_Window.draw(m_UI.getPauseBackground());
		m_Window.draw(*m_UI.getMenu()->getExitText());
	}
	//m_Window.draw(m_UI.getSpriteBoard());

	


	m_Window.display();
}
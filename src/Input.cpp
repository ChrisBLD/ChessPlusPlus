#include "Engine.h"

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			//Handle the player quitting
			if (Keyboard::isKeyPressed(Keyboard::Escape) && state == State::MENU)
			{
				m_Window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::Return) && state == State::MENU)
			{
				state = State::PLAYING;
				m_GL.startGame();
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape) && state == State::PLAYING)
			{
				state = State::PAUSED;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Escape) && state == State::PAUSED)
			{
				state = State::PLAYING;
			}
		}

		if (event.type == Event::MouseMoved && state == State::MENU)
		{
			m_UI.getMenu()->checkStartHovered();
			m_UI.getMenu()->checkExitHovered();
		}

		if (event.type == Event::MouseMoved && state == State::PLAYING)
		{
			m_GL.checkHovered();
		}


	}

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (m_UI.getMenu()->checkStartHovered())
		{
			state = State::PLAYING;
			m_GL.startGame();
		}
		if (m_UI.getMenu()->checkExitHovered())
		{
			m_Window.close();
		}
	}

	
}
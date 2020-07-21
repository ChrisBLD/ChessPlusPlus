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
	}
}
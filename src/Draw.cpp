#include "Engine.h"
#include <iostream>

void Engine::draw()
{
	m_Window.clear(Color::Cyan);

	if (state == State::MENU)
	{
		m_Window.draw(m_UI.getMenu().getMainMenuSprite());
		m_Window.draw(m_UI.getMenu().getStartText());
		m_Window.draw(m_UI.getMenu().getExitText());
	}

	if (state == State::PLAYING)
	{
		//std::cout << "Turn State" << endl;
		m_Window.draw(m_UI.getSpriteBoard());
	}

	if (state == State::PAUSED)
	{
		m_Window.draw(m_UI.getPauseBackground());
	}
	//m_Window.draw(m_UI.getSpriteBoard());

	


	m_Window.display();
}
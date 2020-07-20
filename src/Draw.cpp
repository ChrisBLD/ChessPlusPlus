#include "Engine.h"
#include <iostream>

void Engine::draw()
{
	m_Window.clear(Color::Cyan);

	if (state == State::MENU)
	{
		std::cout << "Menu State" << endl;
		m_Window.draw(m_UI.getMenuBackground());
	}

	if (state == State::WHITE_TURN || state == State::BLACK_TURN)
	{
		std::cout << "Turn State" << endl;
		m_Window.draw(m_UI.getSpriteBoard());
	}
	//m_Window.draw(m_UI.getSpriteBoard());

	


	m_Window.display();
}
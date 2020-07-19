#include "Engine.h"

void Engine::draw()
{
	m_Window.clear(Color::Cyan);

	m_Window.draw(m_UI.getSprite());

	m_Window.display();
}
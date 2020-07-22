#include "MainMenu.h"

MainMenu::MainMenu()
{

	m_MenuBackground.setTexture(TextureHolder::GetTexture("assets/mainmenu.png"));
	m_Font.loadFromFile("assets/fonts/Roboto-Light.ttf");

	m_Start.setCharacterSize(80);
	m_Start.setFont(m_Font);
	m_Start.setFillColor(Color::White);
	m_Start.setString("Start Game");
	m_Start.setOrigin(Vector2f(m_Start.getLocalBounds().width / 2.0f, m_Start.getLocalBounds().height / 2.0f));

	m_Exit.setCharacterSize(80);
	m_Exit.setFont(m_Font);
	m_Exit.setFillColor(Color::White);
	m_Exit.setString("Quit");
	m_Exit.setOrigin(Vector2f(m_Exit.getLocalBounds().width / 2.0f, m_Exit.getLocalBounds().height / 2.0f));

}

void MainMenu::init(Vector2f res)
{
	resolution = res;
	m_Start.setPosition(resolution.x / 2.0f, resolution.y / 1.7f);
	m_Exit.setPosition(resolution.x / 2.0f, resolution.y / 1.2f);
}

void MainMenu::setStartText(String newText)
{
	m_Start.setString(newText);
}


Text* MainMenu::getStartText()
{
	return &m_Start;
}

Text* MainMenu::getExitText()
{
	return &m_Exit;
}

Sprite MainMenu::getMainMenuSprite()
{
	return m_MenuBackground;
}
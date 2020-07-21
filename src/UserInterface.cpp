#include "UserInterface.h"
#include "TextureHolder.h"

UserInterface::UserInterface()
{

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_SpriteBoard.setTexture(TextureHolder::GetTexture("assets/chessboard.png"));
	m_SpriteBoard.setOrigin(m_SpriteBoard.getTexture()->getSize().x / 2.0f, m_SpriteBoard.getTexture()->getSize().y / 2.0f);

	m_SpriteBoard.setPosition((resolution.x / 4.0f) + resolution.x / 2.0f, resolution.y / 2.0f);

	m_PauseBackground.setTexture(TextureHolder::GetTexture("assets/pausemenu.png"));

	m_MainMenu.init(resolution);
}

Sprite UserInterface::getSpriteBoard()
{
	return m_SpriteBoard;
}


Sprite UserInterface::getPauseBackground()
{
	return m_PauseBackground;
}

MainMenu UserInterface::getMenu()
{
	return m_MainMenu;
}
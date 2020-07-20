#include "UserInterface.h"
#include "TextureHolder.h"

UserInterface::UserInterface()
{

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_SpriteBoard.setTexture(TextureHolder::GetTexture("assets/chessboard.png"));
	m_SpriteBoard.setOrigin(m_SpriteBoard.getTexture()->getSize().x / 2.0f, m_SpriteBoard.getTexture()->getSize().y / 2.0f);

	m_SpriteBoard.setPosition((resolution.x / 4.0f) + resolution.x / 2.0f, resolution.y / 2.0f);

	m_MenuBackground.setTexture(TextureHolder::GetTexture("assets/mainmenu.png"));

}

Sprite UserInterface::getSpriteBoard()
{
	return m_SpriteBoard;
}

Sprite UserInterface::getMenuBackground()
{
	return m_MenuBackground;
}
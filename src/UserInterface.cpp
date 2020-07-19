#include "UserInterface.h"
#include "TextureHolder.h"

UserInterface::UserInterface()
{

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Sprite.setTexture(TextureHolder::GetTexture("assets/chessboard.png"));
	m_Sprite.setOrigin(m_Sprite.getTexture()->getSize().x / 2.0f, m_Sprite.getTexture()->getSize().y / 2.0f);

	m_Sprite.setPosition((resolution.x / 4.0f) + resolution.x / 2.0f, resolution.y / 2.0f);
}

Sprite UserInterface::getSprite()
{
	return m_Sprite;
}
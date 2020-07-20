#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class UserInterface
{
private:

	//Screen resolution
	Vector2f resolution;

	//Sprite for menu background
	Sprite m_MenuBackground;

	//Sprite for chess board:
	Sprite m_SpriteBoard;


public:

	UserInterface();

	Sprite getSpriteBoard();
	Sprite getMenuBackground();



};
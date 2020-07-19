#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class UserInterface
{
private:

	//Screen resolution
	Vector2f resolution;

	//Sprite for chess board:
	Sprite m_Sprite;


public:

	UserInterface();

	Sprite getSprite();


};
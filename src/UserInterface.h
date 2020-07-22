#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.h"

using namespace sf;

class UserInterface
{
private:

	//Screen resolution
	Vector2f resolution;

	//Main menu object
	MainMenu m_MainMenu;

	//Sprite for pause background
	Sprite m_PauseBackground;

	//Sprite for chess board:
	Sprite m_SpriteBoard;


public:

	UserInterface();

	Sprite getSpriteBoard();
	Sprite getPauseBackground();

	MainMenu* getMenu();



};
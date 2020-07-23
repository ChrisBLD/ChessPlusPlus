#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;


class MainMenu
{
private:

	//Screen resolution
	Vector2f resolution;

	//Sprite for menu background
	Sprite m_MenuBackground;

	//Font for menu items
	Font m_Font;

	//Start game button
	Text m_Start;

	//Exit game button
	Text m_Exit;

public:
	MainMenu();

	void init(Vector2f res);
	void setStartText(String newText);

	bool checkStartHovered();
	bool checkExitHovered();

	Text* getStartText();
	Text* getExitText();
	Sprite getMainMenuSprite();
};
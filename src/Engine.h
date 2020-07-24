#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "UserInterface.h"
#include "GameLogic.h"
#include "Definitions.h"

using namespace sf;

class Engine
{
private:
	//Game state
	State state;

	//The Texture Holder
	TextureHolder textureHolder;

	//The game window
	RenderWindow m_Window;

	//Monitor the total game time so far
	Time m_GameTimeTotal;

	//Create a UI object
	UserInterface m_UI;

	//Create a game logic object
	GameLogic m_GL;

	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine();

	void run();
};
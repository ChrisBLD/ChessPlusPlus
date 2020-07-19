#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;

class Engine
{
private:
	//The Texture Holder
	TextureHolder textureHolder;

	//The game window
	RenderWindow m_Window;

	//Monitor the total game time so far
	Time m_GameTimeTotal;

	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine();

	void run();
};
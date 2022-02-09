/*
Game.h
Game header file
Psudo game engine class
*/
#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "Line.h"
#include <iostream>

class Game
{
private:
	//objects
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	//objects from headers
	Line line;

	//private Variables
	int windowHeight;
	int windowWidth;

	//private functions
	void initVariables();
	void initWindow();

public:
	//constructors and destructors
	Game();
	virtual	~Game();

	//accessors
	const bool running() const;
	//functions
	void pollEvents();
	void update();
	void render();
};

#endif
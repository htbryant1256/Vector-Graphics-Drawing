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
	//Objects
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	//Objects from headers
	Line line;

	//Private Variables
	int windowHeight;
	int windowWidth;
	sf::View view1;

	//Private functions
	void initVariables();
	void initWindow();

public:
	//Constructors and destructors
	Game();
	virtual	~Game();

	//Accessors
	const bool running() const;
	int angle;
	//Functions
	void pollEvents();
	void update();
	void render();
};

#endif
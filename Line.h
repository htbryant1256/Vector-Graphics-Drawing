#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "Enemy.h"
#include "Player.h"
#include "Map.h"
#include <iostream>
class Line
{

public:
	bool autoMode;
	int x, y;
	sf::Font font;
	sf::Text text;
	sf::Text text2;
	sf::RectangleShape displayRect;
	sf::RectangleShape vectorLine;
	
	sf::RectangleShape cursor;
	
	void initLine();
	void updateLine();
private:


};


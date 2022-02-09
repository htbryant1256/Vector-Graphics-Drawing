#ifndef LINE_H
#define LINE_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include <iostream>

class Line
{
public:
	Line();
	sf::Font font;
	sf::Text text;
	sf::RectangleShape displayRect;
	sf::RectangleShape vectorLine;
	
	sf::RectangleShape cursor;
	
	void initLine();
	void updateLine();
private:
	int xVel, yVel, angle;
	bool autoMode;
};

#endif
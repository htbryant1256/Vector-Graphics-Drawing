/*
Map.h
Map header file
Map Data

Loads sprite for map. Map moves around player and player stays in middle of screen.
Because of this the map movement and playerSpeed (Technically inverse map speed) is contained
in this class.


*/
#ifndef MAP_H
#define MAP_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "Player.h"
#include <fstream>

class Map
{
private:
	float mapScale;
	std::ifstream fp;

public:
	//Map Size
	char mapArray[50][50];
	std::vector<sf::Sprite> tileVector;

	sf::Texture map;
	sf::Sprite mapSprite;
	sf::Texture grass;
	sf::Sprite grassTile;
	sf::Texture grassTree;
	sf::Sprite grassTreeTile;
	sf::RectangleShape wallTile;
	
	float playerSpeed;
	Player playerData;

	std::ifstream file;
	void initMap();
	void mapUpdate(sf::RenderWindow*, Map&);
	void mapLoad();
	void mapRender(sf::RenderWindow*, Map&, sf::RectangleShape&);
};

#endif
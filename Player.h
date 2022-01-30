/*
Player.h
Player header file
Player Data

Player stands still and the map moves around the player. Therefore playerSpeed is in the Map class.
*/
#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"

class Player
{
private:
	sf::Vector2f playerSize;
	sf::Vector2f playerCollisionSize;

public:
	float playerSpeed;
	sf::RectangleShape playerRect;
	sf::RectangleShape playerCollisionRect;
	void initPlayer(float, float);
	void playerInputUpdate(sf::View&);
};

#endif
/*
Enemy.h
Enemy header file
Enemy Data
*/
#ifndef ENEMY_H
#define ENEMY_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"

class Enemy
{
private:
	//sf::RectangleShape enemy;

public:
	sf::RectangleShape enemyRect;
	void initEnemies();
	//void spawnEnemies();
};

#endif
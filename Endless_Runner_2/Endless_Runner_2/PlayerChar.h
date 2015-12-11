#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "MyVector.h"

using namespace std;

class Player;

class Player_State
{

public:
	virtual ~Player_State()
	{

	}
	virtual void handleInput(Player &player)
	{

	}
	virtual void update(Player &player)
	{

	}

};

class Walking_Player_State : Player_State
{

public:

	virtual void handleInput(Player &player)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{

		}
	}

	virtual void update(Player &player)
	{

	}
};

class Ducking_Player_State : Player_State
{

public:

	virtual void handleInput(Player &player)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
            
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{

		}
	}

	virtual void update(Player &player)
	{

	}
};

class Airborne_Player_State : Player_State
{

public:

	virtual void handleInput(Player &player)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{

		}
	}

	virtual void update(Player &player)
	{

	}
};

class Player
{
	My_Vector player_pos;
	My_Vector player_velocity;
	My_Vector player_gravity;
	Player_State *state_;

	//collision objects
	sf::RectangleShape platform1;
	sf::RectangleShape platform2;
	sf::RectangleShape platform3;

	sf::Texture player_texture_left;
	sf::Texture player_texture_right;
	sf::Texture player_duck;

public:
	Player(sf::RectangleShape platform1Arg, sf::RectangleShape platform2Arg, sf::RectangleShape platform3Arg)
	{

	}
	virtual void handleInput()
	{

	}
	virtual void update()
	{

	}

	void checkCollision()
	{

	}
};

#endif
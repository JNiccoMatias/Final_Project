#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "MyVector.h"

using namespace std;

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

class Walking_Player_State
{

	virtual void handleInput(Player &player)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{

		}
	}
};

class Player
{
	My_Vector player_pos;
	My_Vector player_velocity;
	My_Vector player_gravity;
	Player_State *state_;


	sf::Texture player_texture_left;
	sf::Texture player_texture_left;

public:
	Player()
	{

	}
	virtual void handleInput()
	{

	}
	virtual void update()
	{

	}
};

#endif
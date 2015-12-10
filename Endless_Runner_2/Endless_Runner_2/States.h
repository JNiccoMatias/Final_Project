#pragma once

#ifndef STATES_H
#define STATES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include <memory>
#include <random>

#include "MyVector.h"

class GamesStateManager;

class Gamestate
{
	friend class GameStateManager;
public:
	virtual ~Gamestate()
	{

	}

	virtual void onActivate() = 0;
	virtual void onDeactivate() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void handleInputs() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

};

class LiveGame_Gamestate : public Gamestate
{
	sf::RenderWindow &render_window;
	int window_width;
	int window_height;
	int platform_height;
	int platform_width;
	My_Vector run_speed;

	//sf::CircleShape shape;

	sf::RectangleShape platform1;
	sf::RectangleShape platform2;
	sf::RectangleShape platform3;
	int gap_distance;


public:
	LiveGame_Gamestate(sf::RenderWindow &window, int width, int height, int fps) : render_window(window)
	{
		window_width = width;
		window_height = height;
		run_speed.Set_X(-1 * window_width / 2.5 / fps);

		platform_height = window_height / 20;

		gap_distance = window_width / 4;

		platform_width = window_width / 3;

		platform1.setPosition(sf::Vector2f(window_width, platform_height * 19));
		platform2.setPosition(sf::Vector2f(platform1.getPosition().x + platform_width + gap_distance, platform_height * 19));
		platform3.setPosition(sf::Vector2f(platform2.getPosition().x + platform_width + gap_distance, platform_height * 19));
	}

	virtual void onActivate()
	{
		//sf::CircleShape shape(100.f);
		//shape.setFillColor(sf::Color::Green);
		//shape.setRadius(100.f);


		platform1.setSize(sf::Vector2f(platform_width, platform_height));
		platform1.setFillColor(sf::Color::Green);
		platform2.setSize(sf::Vector2f(platform_width, platform_height));
		platform2.setFillColor(sf::Color::Red);
		platform3.setSize(sf::Vector2f(platform_width, platform_height));
		platform3.setFillColor(sf::Color::Blue);
	}
	virtual void onDeactivate()
	{

	}
	
	virtual void pause()
	{

	}
	virtual void resume()
	{

	}

	virtual void handleInputs()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//shape.move(run_speed.Get_X(), run_speed.Get_Y());
		}
	}
	virtual void update()
	{
		platform1.move(run_speed.Get_X(), run_speed.Get_Y());
		platform2.move(run_speed.Get_X(), run_speed.Get_Y());
		platform3.move(run_speed.Get_X(), run_speed.Get_Y());

		if (platform1.getPosition().x + platform_width < 0)
		{
			platform1.setPosition(platform3.getPosition().x + platform_width + gap_distance, platform_height * 19);
		}
		if (platform2.getPosition().x + platform_width < 0)
		{
			platform2.setPosition(platform1.getPosition().x + platform_width + gap_distance, platform_height * 19);
		}
		if (platform3.getPosition().x + platform_width < 0)
		{
			platform3.setPosition(platform2.getPosition().x + platform_width + gap_distance, platform_height * 19);
		}
	}
	virtual void draw()
	{
		//sf::CircleShape shape(100.f);
		//shape.setFillColor(sf::Color::Green);
		//render_window.draw(shape);
		//platform1.move(-100, 0);
		render_window.draw(platform1);
		render_window.draw(platform2);
		render_window.draw(platform3);
	}
};

class MainMenu_Gamestate : public Gamestate
{
	sf::RenderWindow &render_window;

public:
	MainMenu_Gamestate(sf::RenderWindow &window) : render_window(window)
	{

	}

	virtual void onActivate()
	{

	}
	virtual void onDeactivate()
	{

	}

	virtual void pause()
	{

	}
	virtual void resume()
	{

	}

	virtual void handleInputs()
	{

	}
	virtual void update()
	{

	}
	virtual void draw()
	{

	}
};

class Pause_Gamestate : public Gamestate
{
	sf::RenderWindow &render_window;

public:
	Pause_Gamestate(sf::RenderWindow &window) : render_window(window)
	{

	}

	virtual void onActivate()
	{

	}
	virtual void onDeactivate()
	{

	}

	virtual void pause()
	{

	}
	virtual void resume()
	{

	}

	virtual void handleInputs()
	{

	}
	virtual void update()
	{

	}
	virtual void draw()
	{

	}
};

class GameOver_Gamestate : public Gamestate
{
	sf::RenderWindow &render_window;

public:
	GameOver_Gamestate(sf::RenderWindow &window) : render_window(window)
	{

	}

	virtual void onActivate()
	{

	}
	virtual void onDeactivate()
	{

	}

	virtual void pause()
	{

	}
	virtual void resume()
	{

	}

	virtual void handleInputs()
	{

	}
	virtual void update()
	{

	}
	virtual void draw()
	{

	}
};

class Leaderboard_Gamestate : public Gamestate
{
	sf::RenderWindow &render_window;

public:
	Leaderboard_Gamestate(sf::RenderWindow &window) : render_window(window)
	{

	}

	virtual void onActivate()
	{

	}
	virtual void onDeactivate()
	{

	}

	virtual void pause()
	{

	}
	virtual void resume()
	{

	}

	virtual void handleInputs()
	{

	}
	virtual void update()
	{

	}
	virtual void draw()
	{

	}
};



class GameStateManager
{
	//vector<std::shared_ptr<Gamestate>> m_states;

public:
	void ChangeState(Gamestate* state);
	void PushState(Gamestate* state);
	void PopState();
	void Clear();
};

void GameStateManager::Clear()
{
	/**
	while (!m_states.empty())
	{
	m_states.back()->cleanUp();
	m_states.pop_back();
	}
	**/
}

void GameStateManager::ChangeState(Gamestate *state)
{
	/**
	// Cleanup the current state
	if (!m_states.empty())
	{
	m_states.back()->cleanUp();
	m_states.pop_back();
	}

	// Store and init the new state
	m_states.push_back(state);
	m_states.back()->init();
	**/
}

// Pause the current state and go to a new state
void GameStateManager::PushState(Gamestate *state)
{
	/**
	if (!m_states.empty())
	m_states.back()->pause();

	m_states.push_back(state);
	m_states.back()->init();
	**/
}


//Leave current state and go to previous state
void GameStateManager::PopState()
{
	/**
	if (!m_states.empty())
	{
	m_states.back()->cleanUp();
	m_states.pop_back();
	}

	if (!m_states.empty())
	m_states.back()->resume();
	**/
}
#endif

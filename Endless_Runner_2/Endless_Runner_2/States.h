#pragma once

#ifndef STATES_H
#define STATES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include <memory>

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

public:
	LiveGame_Gamestate(sf::RenderWindow &window) : render_window(window)
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
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);
		render_window.draw(shape);
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
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);
		render_window.draw(shape);
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
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);
		render_window.draw(shape);
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
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);
		render_window.draw(shape);
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
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);
		render_window.draw(shape);
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

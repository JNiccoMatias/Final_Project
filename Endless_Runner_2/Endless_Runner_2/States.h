#pragma once

#ifndef STATES_H
#define STATES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include <memory>

#include "MyVector.h"

class Gamestate
{
	friend class GameStateManager;
public:

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void handleInputs() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	virtual void onActivate() = 0;
	virtual void onDeactivate() = 0;
};

class GameStateManager
{
public:
	void ChangeState(Gamestate* state);
	void PushState(Gamestate* state);
	void PopState();
	void Clear();

private:
	std::vector<Gamestate*> m_states;
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


class MainMenu_Gamestate : public Gamestate
{
public:
	//MainMenu_Gamestate() {}
};

class Pause_Gamestate : public Gamestate
{
public:
	//Pause_Gamestate() {}
};

class GameOver_Gamestate : public Gamestate
{
public:
	//GameOver_Gamestate() {}
};

class Leaderboard_Gamestate : public Gamestate
{
public:
	//Leaderboard_Gamestate() {}
};
#endif

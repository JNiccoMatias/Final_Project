#pragma once

#ifndef STATES_H
#define STATES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include <memory>
#include <random>

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
	int current_platform_elevation;
	int run_speed;

	//sf::CircleShape shape;

	sf::RectangleShape platform1;
	sf::RectangleShape platform2;
	sf::RectangleShape platform3;
	int gap_distance;

public:
	LiveGame_Gamestate(sf::RenderWindow &window, int width, int height, int fps);

	virtual void onActivate();

	virtual void onDeactivate();
	
	virtual void pause();

	virtual void resume();

	virtual void handleInputs();

	virtual void update();

	virtual void draw();
};

class MainMenu_Gamestate : public Gamestate
{
	sf::RenderWindow &render_window;

public:
	MainMenu_Gamestate(sf::RenderWindow &window);

	virtual void onActivate();

	virtual void onDeactivate();

	virtual void pause();

	virtual void resume();

	virtual void handleInputs();

	virtual void update();

	virtual void draw();
};

class Pause_Gamestate : public Gamestate
{
	sf::RenderWindow &render_window;

public:
	Pause_Gamestate(sf::RenderWindow &window);

	virtual void onActivate();

	virtual void onDeactivate();

	virtual void pause();

	virtual void resume();

	virtual void handleInputs();

	virtual void update();

	virtual void draw();
};

class GameOver_Gamestate : public Gamestate
{
	sf::RenderWindow &render_window;

public:
	GameOver_Gamestate(sf::RenderWindow &window);

	virtual void onActivate();

	virtual void onDeactivate();

	virtual void pause();

	virtual void resume();

	virtual void handleInputs();

	virtual void update();

	virtual void draw();
};

class Leaderboard_Gamestate : public Gamestate
{
	sf::RenderWindow &render_window;

public:
	Leaderboard_Gamestate(sf::RenderWindow &window);

	virtual void onActivate();

	virtual void onDeactivate();

	virtual void pause();

	virtual void resume();

	virtual void handleInputs();

	virtual void update();

	virtual void draw();
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
#endif

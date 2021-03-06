#pragma once

#ifndef STATES_H
#define STATES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include <memory>
#include <random>
#include <cassert>

//#include "MyVector.h"
//class My_Vector;
#include "PlayerChar.h"

using namespace std;

class GamesStateManager;

class Gamestate
{
	friend class GameStateManager;
	GamesStateManager *manager;

protected:
	sf::RenderWindow &render_window;
	int window_width;
	int window_height;
	int run_speed;
	sf::Font font;
	//int rand1;

	

public:

	Gamestate(sf::RenderWindow &window, int width, int height, int fps);

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
	//sf::RenderWindow &render_window;
	//int window_width;
	//int window_height;
	//int run_speed;

	int platform_height;
	int platform_width;
	int current_platform_elevation;
	int bomb_elevation;

	//random_device random_seeder;
	//My_Vector vec;
	//sf::CircleShape shape;
    int score;
    sf::Text tScore;
    
    class player player1;

    sf::RectangleShape platform1;
	sf::RectangleShape platform2;
	sf::RectangleShape platform3;
	int gap_distance;
    mt19937 engine;

	sf::Texture bombpic;
	sf::Sprite bomb1_1;
	sf::Sprite bomb1_2;
	sf::Sprite bomb2_1;
	sf::Sprite bomb2_2;
	sf::Sprite bomb3_1;
	sf::Sprite bomb3_2;

public:
	LiveGame_Gamestate(sf::RenderWindow &window, int width, int height, int fps);
	//LiveGame_Gamestate();

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
	//sf::RenderWindow &render_window;
	//int window_width;
	//int window_height;
	//int run_speed;
    
    sf::Texture tStateMain;
    sf::Sprite sStateMain;
    
    sf::RectangleShape Play;
    sf::RectangleShape Leaderboards;
    sf::RectangleShape Quit;

public:
	MainMenu_Gamestate(sf::RenderWindow &window, int width, int height, int fps);
	//MainMenu_Gamestate();

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
	//sf::RenderWindow &render_window;
	//int window_width;
	//int window_height;
	//int run_speed;
    
    sf::Texture tStatePause;
    sf::Sprite sStatePause;

public:
	Pause_Gamestate(sf::RenderWindow &window, int width, int height, int fps);
	//Pause_Gamestate();

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
	//sf::RenderWindow &render_window;
	//int window_width;
	//int window_height;
	//int run_speed;
    
    sf::Texture tStateGameOver;
    sf::Sprite sStateGameOver;

public:
	GameOver_Gamestate(sf::RenderWindow &window, int width, int height, int fps);
	//GameOver_Gamestate();

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
	//sf::RenderWindow &render_window;
	//int window_width;
	//int window_height;
	//int run_speed;

public:
	Leaderboard_Gamestate(sf::RenderWindow &window, int width, int height, int fps);
	//Leaderboard_Gamestate();

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
	vector<Gamestate*> m_states;

public:
	GameStateManager()
	{

	}
	void ChangeState(Gamestate* state);
	void PushState(Gamestate* state);
	void PopState();
	void Clear();
};
#endif

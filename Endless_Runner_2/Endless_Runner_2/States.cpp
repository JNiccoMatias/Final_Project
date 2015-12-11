#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include <memory>
#include <random>

#include "MyVector.h"
#include "States.h"
#include "PlayerChar.h"
#include "ResourcePath.hpp"

using namespace std;

Gamestate::Gamestate(sf::RenderWindow &window, int width, int height, int fps) : render_window(window)
{
	window_width = width;
	window_height = height;
	//run_speed.Set_X(-1 * window_width / 2.5 / fps);
	run_speed = -1 * window_width / 2.5 / fps;

	/*if (!font.loadFromFile("AlegreyaSans-Regular.ttf"))
	{
		render_window.close();
	}*/
}

/*
void Gamestate::update(int rand_arg1)
{
	rand1 = rand_arg1;
}
*/

/*
LiveGame_Gamestate::LiveGame_Gamestate(sf::RenderWindow &window, int width, int height, int fps) : render_window(window)
{
	window_width = width;
	window_height = height;
	//run_speed.Set_X(-1 * window_width / 2.5 / fps);
	run_speed = -1 * window_width / 2.5 / fps;
	current_platform_elevation = 19;

	//platform_height = window_height / 20;

	//gap_distance = window_width / 4;

	//platform_width = window_width * 2 / 3;

	//platform1.setPosition(sf::Vector2f(window_width, platform_height * current_platform_elevation));
	//platform2.setPosition(sf::Vector2f(platform1.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation));
	//platform3.setPosition(sf::Vector2f(platform2.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation));
}
*/

LiveGame_Gamestate::LiveGame_Gamestate(sf::RenderWindow &window, int width, int height, int fps) : Gamestate(window, width, height, fps)
{
	current_platform_elevation = 19;
	platform_height = window_height / 20;
	gap_distance = window_width / 4;
	platform_width = window_width * 0.9;

	//platform1.setPosition(sf::Vector2f(window_width, platform_height * current_platform_elevation));
	//platform2.setPosition(sf::Vector2f(platform1.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation));
	//platform3.setPosition(sf::Vector2f(platform2.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation));
}

void LiveGame_Gamestate::onActivate()
{
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	//shape.setRadius(100.f);

	//current_platform_elevation = 19;
	//platform_height = window_height / 20;
	//gap_distance = window_width / 4;
	//platform_width = window_width * 2 / 3;

	platform1.setSize(sf::Vector2f(platform_width, platform_height));
	platform1.setFillColor(sf::Color::Green);
	platform2.setSize(sf::Vector2f(platform_width, platform_height));
	platform2.setFillColor(sf::Color::Red);
	platform3.setSize(sf::Vector2f(platform_width, platform_height));
	platform3.setFillColor(sf::Color::Blue);

	platform1.setPosition(sf::Vector2f(window_width, platform_height * current_platform_elevation));
	platform2.setPosition(sf::Vector2f(platform1.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation));
	platform3.setPosition(sf::Vector2f(platform2.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation));

	if (!bombpic.loadFromFile(resourcePath() + "bomb.png"))
	{
		render_window.close();
	}
	bomb1_1.setTexture(bombpic);
	bomb1_2.setTexture(bombpic);
	bomb2_1.setTexture(bombpic);
	bomb2_2.setTexture(bombpic);
	bomb3_1.setTexture(bombpic);
	bomb3_2.setTexture(bombpic);

	bomb_elevation =  2;
	//bomb1_1.setPosition(window_width, bomb_elevation);
	bomb1_1.setPosition(platform1.getPosition().x + platform_width / 3 - bomb1_1.getGlobalBounds().width / 2, platform_height * current_platform_elevation - (125 * bomb_elevation));
	bomb1_2.setPosition(platform1.getPosition().x + platform_width * 2 / 3 - bomb1_2.getGlobalBounds().width / 2, platform_height * current_platform_elevation - (125 * bomb_elevation));
	bomb2_1.setPosition(platform2.getPosition().x + platform_width / 3 - bomb2_1.getGlobalBounds().width / 2, platform_height * current_platform_elevation - (125 * bomb_elevation));
	bomb2_2.setPosition(platform2.getPosition().x + platform_width * 2 / 3 - bomb2_2.getGlobalBounds().width / 2, platform_height * current_platform_elevation - (125 * bomb_elevation));
	bomb3_1.setPosition(platform3.getPosition().x + platform_width / 3 - bomb3_1.getGlobalBounds().width / 2, platform_height * current_platform_elevation - (125 * bomb_elevation));
	bomb3_2.setPosition(platform3.getPosition().x + platform_width * 2 / 3 - bomb3_2.getGlobalBounds().width / 2, platform_height * current_platform_elevation - (125 * bomb_elevation));

}
void LiveGame_Gamestate::onDeactivate()
{

}

void LiveGame_Gamestate::pause()
{
    
}
void LiveGame_Gamestate::resume()
{

}

void LiveGame_Gamestate::handleInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

	}
}
void LiveGame_Gamestate::update()
{
	platform1.move(run_speed, 0);
	platform2.move(run_speed, 0);
	platform3.move(run_speed, 0);

	bomb1_1.move(run_speed, 0);
	bomb1_2.move(run_speed, 0);
	bomb2_1.move(run_speed, 0);
	bomb2_2.move(run_speed, 0);
	bomb3_1.move(run_speed, 0);
	bomb3_2.move(run_speed, 0);

	if ((platform1.getPosition().x + platform_width < 0) || (platform2.getPosition().x + platform_width < 0) || (platform3.getPosition().x + platform_width < 0))
	{
		//default_random_engine generator;
		//uniform_int_distribution<int> platform_elevation_randomizer(0, 19);
		//current_platform_elevation = platform_elevation_randomizer(generator);

		//random_device random_seeder;
		mt19937 engine(time(0));
		uniform_int_distribution<int> platform_dist(current_platform_elevation - 4, 19);
		uniform_int_distribution<int> bomb_dist(1, 2);

		current_platform_elevation = platform_dist(engine);
		if (current_platform_elevation < 10)
		{
			current_platform_elevation = 10;
		}
		if (platform1.getPosition().x + platform_width < 0)
		{
			platform1.setPosition(platform3.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation);

			bomb_elevation = bomb_dist(engine);
			bomb1_1.setPosition(platform1.getPosition().x + platform_width / 3 - bomb1_1.getGlobalBounds().width / 2, platform_height * current_platform_elevation - (125 * bomb_elevation));
			bomb_elevation = bomb_dist(engine);
			bomb1_2.setPosition(platform1.getPosition().x + platform_width * 2 / 3 - bomb1_2.getGlobalBounds().width / 2, platform_height * current_platform_elevation - (125 * bomb_elevation));

		}
		if (platform2.getPosition().x + platform_width < 0)
		{
			platform2.setPosition(platform1.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation);

			bomb_elevation = bomb_dist(engine);
			bomb2_1.setPosition(platform2.getPosition().x + platform_width / 3 - bomb2_1.getGlobalBounds().width / 2, platform_height * current_platform_elevation - (125 * bomb_elevation));
			bomb_elevation = bomb_dist(engine);
			bomb2_2.setPosition(platform2.getPosition().x + platform_width * 2 / 3 - bomb2_2.getGlobalBounds().width / 2, platform_height * current_platform_elevation - (125 * bomb_elevation));

		}
		if (platform3.getPosition().x + platform_width < 0)
		{
			platform3.setPosition(platform2.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation);
			bomb_elevation = bomb_dist(engine);
			bomb3_1.setPosition(platform3.getPosition().x + platform_width / 3 - bomb3_1.getGlobalBounds().width / 2, platform_height * current_platform_elevation - (125 * bomb_elevation));
			bomb_elevation = bomb_dist(engine);
			bomb3_2.setPosition(platform3.getPosition().x + platform_width * 2 / 3 - bomb3_2.getGlobalBounds().width / 2, platform_height * current_platform_elevation - (125 * bomb_elevation));

		}
	}
}
void LiveGame_Gamestate::draw()
{
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	//render_window.draw(shape);
	//platform1.move(-100, 0);
	render_window.draw(platform1);
	render_window.draw(platform2);
	render_window.draw(platform3);
	render_window.draw(bomb1_1);
	render_window.draw(bomb1_2);
	render_window.draw(bomb2_1);
	render_window.draw(bomb2_2);
	render_window.draw(bomb3_1);
	render_window.draw(bomb3_2);
}


MainMenu_Gamestate::MainMenu_Gamestate(sf::RenderWindow &window, int width, int height, int fps) : Gamestate(window, width, height, fps)
{
    
}

void MainMenu_Gamestate::onActivate()
{
    if (!tStateMain.loadFromFile(resourcePath() + "state-mainMenu.png"))
    {
        render_window.close();
    }
    sStateMain.setTexture(tStateMain);
    
    Play.setSize(sf::Vector2f(600, 100));
    Play.setFillColor(sf::Color::Transparent);
    Play.setOutlineColor(sf::Color::White);
    Play.setOutlineThickness(5);
    Leaderboards.setSize(sf::Vector2f(600, 100));
    Leaderboards.setFillColor(sf::Color::Transparent);
    Leaderboards.setOutlineColor(sf::Color::White);
    Leaderboards.setOutlineThickness(5);
    Quit.setSize(sf::Vector2f(600, 100));
    Quit.setFillColor(sf::Color::Transparent);
    Quit.setOutlineColor(sf::Color::White);
    Quit.setOutlineThickness(5);
    
    
    Play.setPosition(sf::Vector2f(300, 365));
    Leaderboards.setPosition(sf::Vector2f(300, 485));
    Quit.setPosition(sf::Vector2f(300, 605));
    
}

void MainMenu_Gamestate::onDeactivate()
{

}

void MainMenu_Gamestate::pause()
{

}
void MainMenu_Gamestate::resume()
{

}

void MainMenu_Gamestate::handleInputs()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        //start livegame
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        //show leaderboards
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        render_window.close();
    }
}
void MainMenu_Gamestate::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        Play.setOutlineColor(sf::Color::Blue);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        Leaderboards.setOutlineColor(sf::Color::Blue);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        Quit.setOutlineColor(sf::Color::Blue);
    }
}
void MainMenu_Gamestate::draw()
{
    render_window.draw(sStateMain);
    render_window.draw(Play);
    render_window.draw(Leaderboards);
    render_window.draw(Quit);
}


Pause_Gamestate::Pause_Gamestate(sf::RenderWindow &window, int width, int height, int fps) : Gamestate(window, width, height, fps)
{
    
}

void Pause_Gamestate::onActivate()
{
    if (!tStatePause.loadFromFile(resourcePath() + "state-pause.png"))
    {
        render_window.close();
    }
    sStatePause.setTexture(tStatePause);
}
void Pause_Gamestate::onDeactivate()
{

}

void Pause_Gamestate::pause()
{

}
void Pause_Gamestate::resume()
{

}

void Pause_Gamestate::handleInputs()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        //continue livegame
    }

}
void Pause_Gamestate::update()
{

}
void Pause_Gamestate::draw()
{
    render_window.draw(sStatePause);
}


GameOver_Gamestate::GameOver_Gamestate(sf::RenderWindow &window, int width, int height, int fps) : Gamestate(window, width, height, fps)
{

}

void GameOver_Gamestate::onActivate()
{
    if (!tStateGameOver.loadFromFile(resourcePath() + "state-gameOver.png"))
    {
        render_window.close();
    }
    sStateGameOver.setTexture(tStateGameOver);
}
void GameOver_Gamestate::onDeactivate()
{

}

void GameOver_Gamestate::pause()
{

}
void GameOver_Gamestate::resume()
{

}

void GameOver_Gamestate::handleInputs()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        //go to Main Menu
    }
}
void GameOver_Gamestate::update()
{

}
void GameOver_Gamestate::draw()
{

}


Leaderboard_Gamestate::Leaderboard_Gamestate(sf::RenderWindow &window, int width, int height, int fps) : Gamestate(window, width, height, fps)
{

}


void Leaderboard_Gamestate::onActivate()
{

}
void Leaderboard_Gamestate::onDeactivate()
{

}

void Leaderboard_Gamestate::pause()
{

}
void Leaderboard_Gamestate::resume()
{

}

void Leaderboard_Gamestate::handleInputs()
{

}
void Leaderboard_Gamestate::update()
{

}
void Leaderboard_Gamestate::draw()
{

}


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
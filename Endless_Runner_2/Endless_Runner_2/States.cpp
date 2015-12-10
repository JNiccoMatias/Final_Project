#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include <memory>
#include <random>

//#include "MyVector.h"
#include "States.h"

LiveGame_Gamestate::LiveGame_Gamestate(sf::RenderWindow &window, int width, int height, int fps) : render_window(window)
{
	window_width = width;
	window_height = height;
	//run_speed.Set_X(-1 * window_width / 2.5 / fps);
	run_speed = -1 * window_width / 2.5 / fps;
	current_platform_elevation = 19;

	platform_height = window_height / 20;

	gap_distance = window_width / 4;

	platform_width = window_width * 2 / 3;

	platform1.setPosition(sf::Vector2f(window_width, platform_height * current_platform_elevation));
	platform2.setPosition(sf::Vector2f(platform1.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation));
	platform3.setPosition(sf::Vector2f(platform2.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation));
}

void LiveGame_Gamestate::onActivate()
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
	if ((platform1.getPosition().x + platform_width < 0) || (platform2.getPosition().x + platform_width < 0) || (platform3.getPosition().x + platform_width < 0))
	{
		//default_random_engine generator;
		//uniform_int_distribution<int> platform_elevation_randomizer(current_platform_elevation - 2, current_platform_elevation);

		//current_platform_elevation = platform_elevation_randomizer(generator);

		if (platform1.getPosition().x + platform_width < 0)
		{
			platform1.setPosition(platform3.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation);
		}
		if (platform2.getPosition().x + platform_width < 0)
		{
			platform2.setPosition(platform1.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation);
		}
		if (platform3.getPosition().x + platform_width < 0)
		{
			platform3.setPosition(platform2.getPosition().x + platform_width + gap_distance, platform_height * current_platform_elevation);
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
}


MainMenu_Gamestate::MainMenu_Gamestate(sf::RenderWindow &window) : render_window(window)
{

}

void MainMenu_Gamestate::onActivate()
{

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

}
void MainMenu_Gamestate::update()
{

}
void MainMenu_Gamestate::draw()
{

}


Pause_Gamestate::Pause_Gamestate(sf::RenderWindow &window) : render_window(window)
{

}

void Pause_Gamestate::onActivate()
{

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

}
void Pause_Gamestate::update()
{

}
void Pause_Gamestate::draw()
{

}


GameOver_Gamestate::GameOver_Gamestate(sf::RenderWindow &window) : render_window(window)
{

}

void GameOver_Gamestate::onActivate()
{

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

}
void GameOver_Gamestate::update()
{

}
void GameOver_Gamestate::draw()
{

}


Leaderboard_Gamestate::Leaderboard_Gamestate(sf::RenderWindow &window) : render_window(window)
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
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include <memory>
#include <random>

//#include "MyVector.h"
#include "States.h"
#include "ResourcePath.hpp"

using namespace std;

std::string resourcePath()
{
	return "";
}

int main()
{
	//constant variables
	const int window_width = 1200;
	const int window_height = 800;
	const int fps = 60;
	const sf::Time mspf = sf::milliseconds(1000 / fps);

	//generate random number ranges
	//random_device random_seeder;
	//mt19937 engine(random_seeder());
	//uniform_int_distribution<int> platform_elevation_dist(-2, 19);
	//int random_platform_elevation;

	/*
	sf::Font font;
	
	*/

	sf::RenderWindow window1(sf::VideoMode(window_width, window_height), "Endless Runner", sf::Style::Close);
    
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window1.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	//GamesStateManager manager;
	MainMenu_Gamestate mainMenu(window1,window_width,window_height,fps);

	LiveGame_Gamestate livegame(window1, window_width,window_height, fps);

	livegame.onActivate();

	//Main Game Loop
	while (window1.isOpen())
	{
		//Start Clock
		sf::Clock frame_timer;

		//Handle Inputs
		sf::Event event;
		while (window1.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window1.close();
		}

		livegame.handleInputs();

		//Update Assets
		livegame.update();


		//Draw
		window1.clear();
		livegame.draw();
		window1.display();

		//Sync Time Step
		if (frame_timer.getElapsedTime() < mspf)
		{
			sf::sleep(mspf - frame_timer.getElapsedTime());
		}
		frame_timer.restart();
	}

	return 0;
}
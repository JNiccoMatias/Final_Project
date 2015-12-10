#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include <memory>
#include <random>

#include "MyVector.h"
#include "States.h"

using namespace std;

int main()
{
	//constant variables
	const int window_width = 1200;
	const int window_height = 800;
	const int fps = 60;
	const sf::Time mspf = sf::milliseconds(1000 / fps);

	//generate random number ranges
	random_device random_seeder;
	mt19937 random_engine(random_seeder());


	sf::Font font;
	if (!font.loadFromFile("AlegreyaSans-Regular.ttf"))
	{
		return 0;
	}

	sf::RenderWindow window1(sf::VideoMode(window_width, window_height), "Endless Runner", sf::Style::Close);

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
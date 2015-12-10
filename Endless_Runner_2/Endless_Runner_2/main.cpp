#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include <memory>

#include "MyVector.h"
#include "States.h"

using namespace std;

int main()
{
	const int window_width = 1200;
	const int window_height = 800;
	const int fps = 60;
	const sf::Time mspf = sf::milliseconds(1000 / fps);

	sf::Font font;
	if (!font.loadFromFile("AlegreyaSans-Regular.ttf"))
	{
		return 0;
	}

	sf::RenderWindow window1(sf::VideoMode(window_width, window_height), "Endless Runner", sf::Style::Close);

	LiveGame_Gamestate livegame(window1);

	//Main Game Loop
	while (window1.isOpen())
	{

		//Start Clock
		sf::Clock frame_timer;

		sf::Event event;
		while (window1.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window1.close();
		}

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
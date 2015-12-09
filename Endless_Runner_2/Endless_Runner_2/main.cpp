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
	int window_width = 1200;
	int window_height = 800;

	sf::Font font;
	if (!font.loadFromFile("AlegreyaSans-Regular.ttf"))
	{
		return 0;
	}

	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Endless Runner", sf::Style::Close);

	//Main game/window loop
	while (window.isOpen())
	{

		//closing event check
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Draw
		window.clear();
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);
		window.draw(shape);
		window.display();
	}

	return 0;
}
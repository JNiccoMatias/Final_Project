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

player::player()
{
    sf::Texture tPlayer;
    if (!tPlayer.loadFromFile(resourcePath() + "player.png"))
    {
        return EXIT_FAILURE;
    }
    sPlayer.setPosition(200, 500);
    sPlayer.setTextureRect(sf::IntRect(0, 0, 100, 200));
}

void player::update()
{
    sPlayer.setPosition(sPlayer.getPosition());
}

void player::updateMovement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (jump == -500)
        {
            do {
                jump += 1;
            }while (jump != 0);
        }
        else if (( -500 < jump) || (jump == 0))
        {
            do{
                jump-=1;
            }while (jump != -500);
        }
        sPlayer.move(0,jump);
        sPlayer.setTextureRect(sf::IntRect(counterWalking * 100, 0, 100, 200));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        sPlayer.setTextureRect(sf::IntRect(0, 200, 100, 400));
    }
    
    counterWalking++;
    
    if (counterWalking == 2)
    {
        counterWalking = 0;
    }
}

#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "MyVector.h"
#include "ResourcePath.hpp"

#include <stdio.h>

using namespace std;

class player
{
public:
    //sf::RectangleShape rect;
    sf::Sprite sPlayer;
    
    int counterWalking = 0;
    
    player();
    void update();
    void updateMovement();
};

#endif
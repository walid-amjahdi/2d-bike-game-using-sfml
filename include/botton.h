#pragma once
#include "sprites.h"
class botton :
    public sprites
{
protected :

public : 
    botton(const std::string);
    bool isclicked(sf::Vector2i);
};


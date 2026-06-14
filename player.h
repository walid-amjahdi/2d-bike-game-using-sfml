#pragma once

#include "sprites.h"


class player : public sprites 
{
protected :

public :
	const float jumpheight = -500.0f;
	const float speed = 150.0f;
	const float acceleration = 2.0f;
	bool isjumping;
public :
	const float initialPos = 10.f;
	player(const std::string);
	void move(sf::Vector2f);
};


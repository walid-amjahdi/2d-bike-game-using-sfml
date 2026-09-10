#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>



class sprites
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;

public:
	sprites(const std::string );

	sf::Vector2f getposition();
	void setposition(float,float);
	sf::Vector2f getsize();
	void scale(float, float);
	void draw(sf::RenderWindow&);
	sf::FloatRect globalBounds();
	void setOrigin(float,float);
};


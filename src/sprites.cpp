#include "sprites.h"


sprites::sprites(const std::string textureFile) 
{
	texture.loadFromFile(textureFile);
	sprite.setTexture(texture);
}

sf::Vector2f sprites::getposition ()
{
	return { sprite.getPosition().x, sprite.getPosition().y };
}

sf::Vector2f sprites::getsize()
{
	return { sprite.getGlobalBounds().width, sprite.getGlobalBounds().height};
}

void sprites::setposition(float x, float y)
{
	sprite.setPosition(x, y);
}

void sprites::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void sprites::scale(float x, float y)
{
	sprite.scale(x, y);
}

sf::FloatRect sprites::globalBounds()
{
	return sprite.getGlobalBounds();
}

void sprites::setOrigin(float dx, float dy)
{
	sprite.setOrigin(dx, dy);
}
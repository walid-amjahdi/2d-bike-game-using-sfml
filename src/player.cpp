#include "player.h"


player::player(const std::string fileTexture)
	:sprites(fileTexture)
{}


void player::move(sf::Vector2f velocity)
{
	sprite.move(velocity);
}
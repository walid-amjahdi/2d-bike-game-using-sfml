#include "botton.h"


 bool botton::isclicked(sf::Vector2i mousePos)
{
	return sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

 botton::botton(const std::string filetexture)
	 : sprites(filetexture)
 {}
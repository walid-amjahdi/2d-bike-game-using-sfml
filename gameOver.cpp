#include "gameOver.h"





int gameRestart()
{
	sf::RenderWindow window(sf::VideoMode(700.f, 700.f), " game over", sf::Style::None);

	background restartWindow("gameOver.png");

	botton restart("restart.png");
	restart.setOrigin(restart.getsize().x / 2.f, restart.getsize().y / 2.f);
	restart.setposition(window.getSize().x / 2.f, 250.f);
	botton exit("return.png");
	exit.setOrigin(exit.getsize().x / 2.f, exit.getsize().y / 2.f);
	exit.scale(0.5f, 0.5f);
	exit.setposition(window.getSize().x / 2.f, restart.getposition().y + restart.getsize().y + 100.f);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
			{
				if (restart.isclicked(sf::Mouse::getPosition(window)))
				{
					window.close();
					return 1;
				}
				if (exit.isclicked(sf::Mouse::getPosition(window)))
				{
					window.close();
					return 0;
				}
			}
		}
		window.clear();

		restartWindow.draw(window);
		restart.draw(window);
		exit.draw(window);

		window.display();
	}
}
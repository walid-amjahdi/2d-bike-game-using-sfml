#include "menu.h"

Menu::Menu(const std::string filetexture)
	:sprites(filetexture)
{}

int menu()
{
	// the window rendering
	sf::RenderWindow menuWindow(sf::VideoMode(700.f, 700.f), "menu", sf::Style::None);

	Menu menu("menu.png");

	botton play("play.png");
	botton about("about.png");
	botton exit("exit.png");

	play.setOrigin(play.getsize().x / 2.0f, play.getsize().y / 2.0f);
	exit.setOrigin(exit.getsize().x / 2.0f, exit.getsize().y / 2.0f);
	about.setOrigin(about.getsize().x / 2.0f, about.getsize().y / 2.0f);

	play.setposition(menuWindow.getSize().x / 2.f, 150.f);
	about.setposition(menuWindow.getSize().x / 2.f, play.getposition().y + play.getsize().y + 50);
	exit.setposition(menuWindow.getSize().x / 2.f, about.getposition().y + about.getsize().y + 50);

	//  game loop 

	while (menuWindow.isOpen())
	{
		sf::Event evnt;
		while (menuWindow.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Escape)
				return 0;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (play.isclicked(sf::Mouse::getPosition(menuWindow)))
			{
				menuWindow.close();
				return 1;
			}
			if (exit.isclicked(sf::Mouse::getPosition(menuWindow)))
			{
				menuWindow.close();
				return 0;
			}
			if (about.isclicked(sf::Mouse::getPosition(menuWindow)))
			{
				menuWindow.close();
				return 2;
			}
		}

		menuWindow.clear();

		menu.draw(menuWindow);
		play.draw(menuWindow);
		about.draw(menuWindow);
		exit.draw(menuWindow);
		
		menuWindow.display();

	}


}



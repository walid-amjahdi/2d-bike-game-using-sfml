#include "aboutPage.h"



void About()
{
	sf::RenderWindow window(sf::VideoMode(700.f, 700.f), "level 2", sf::Style::None);


	background aboutBottom("aboutBottom.png");
	aboutBottom.setposition(0.f, window.getSize().y - aboutBottom.getsize().y);
	background aboutTop("aboutTop.png");
	aboutTop.setposition(0.f, 0.f);
	background Background("aboutpage.png");

	sf::Font font;
	font.loadFromFile("Fredoka.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString
	(
		"About the Game:\n"
		"Game Title: Leo's Adventure\n"
		"Developer(s): WALID AMJAHDI \n"
		"Institution: FSSM\n"
		"Course: Mini Project in C++\n"
		"Academic Year: 2025\n\n"
		"Description:\n"
		"Leo's Adventure is an exciting 2D \n"
		"adventure game developed in C++ \n"
		"using object-oriented programming \n"
		"principles and the SFML library. \n"
		"The goal is simple: retrieve a forgotten \n"
		"backpack before time runs out, \n"
		"while avoiding various obstacles along the way.\n\n"
		"In this single-player game, players \n"
		"control a bike through a series of challenging \n"
		"tracks filled with obstacles. If the \n"
		"bike collides with an obstacle, the game ends.\n"
		"Players must navigate the course and adjust \n"
		"the bike's speed and direction to avoid \n"
		"the obstacles and make it to the goal in time.\n\n"
		"The game utilizes SFML for smooth 2D graphics \n"
		"and movements, \n"
		"providing an immersive and enjoyable adventure \n"
		"experience.\n\n"
		"Gameplay Features:\n"
		"- Time Limit: Complete the course before \n"
		"time runs out.\n"
		"- Collision Detection: Avoid hitting \n"
		"obstacles, or the game ends.\n"
		"- Bike Control:\n"
		"  D: Normal speed to the right\n"
		"  Q: Normal speed to the left\n"
		"  LShift: Acceleration\n"
		"  Space: Jump\n"
		"  Escape: Return to back\n"
		"- Main Menu: Choose to play, learn more \n"
		"about the game, or quit.\n"
		"- Visuals: Simple and colorful 2D graphics.\n\n"
		"Credits:\n"
		"Development: WALID AMJAHDI , OUMAHA MALIKA\n"
		"Graphics: WALID AMJAHDI\n"
		"Special Thanks: Prof  R.HANNANE"
	);

	text.setCharacterSize(20);
	text.setPosition(100.f, aboutTop.getsize().y + 20.f );
	text.setFillColor(sf::Color::Black);


	botton goToMenu("return.png");
	goToMenu.setOrigin(goToMenu.getsize().x / 2.f, goToMenu.getsize().y / 2.f);
	goToMenu.scale(0.5f, 0.5f);
	goToMenu.setposition(window.getSize().x / 2.f, Background.getsize().y - 50.f );

	const float scrolSpeed = 30.f;

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Escape)
			{
				window.close();
				return;
			}
			if (evnt.type == sf::Event::MouseWheelScrolled)
			{
				if (evnt.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
				{
					float delta = evnt.mouseWheelScroll.delta;
					if (text.getPosition().y <= aboutTop.getsize().y + 20.f && delta == 1)
					{
						text.move(0.f, delta * scrolSpeed);
					}
					if (delta == -1 && text.getPosition().y + text.getGlobalBounds().height >= (window.getSize().y / 2.f) + 150.f)
					{
						text.move(0.f, delta * scrolSpeed);
					}
				}
			}
		}


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (goToMenu.isclicked(sf::Mouse::getPosition(window)))
			{
				window.close();
				return;
			}
		}
		window.clear();
		Background.draw(window);
		window.draw(text);
		aboutBottom.draw(window);
		aboutTop.draw(window);
		goToMenu.draw(window);

		window.display();
	}
}

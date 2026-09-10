#include "tutorial.h"

void story()
{
	sf::RenderWindow window(sf::VideoMode(700.f, 700.f), "tutorial", sf::Style::None);


	background storyPage("storyPage.png");
	

	sf::Font font;
	font.loadFromFile("Fredoka.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25);
	text.setPosition(75.f, 100.f);
	text.setFillColor(sf::Color::Black);

	sf::Text text2;
	text2.setFont(font);
	text2.setCharacterSize(15);
	text2.setPosition(400.f, 600.f);
	text2.setFillColor(sf::Color::Black);
	text2.setString("TAP SPACE FOR THE NEXT");

	player leo("leo.png");
	leo.setposition(50.f, storyPage.getsize().y - leo.getsize().y - 50.f);

	int clicked = 0;

	while (window.isOpen())
	{
		
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Space)
			{
				++clicked;
			}
		}


		switch (clicked)
		{
		case 0 :
			text.setString("Hi! My name is Leo.");
			break;
		case 1 :
			text.setString("I really messed up this time... \nAfter an awesome ride through the forest,\n"
				"I realized I forgot my backpack! \nIt has everything important:\n"
				"my map, snacks... even my homework!\n\n");
			break;
		case 2 :
			text.setString("There are two roads to go back. \nOne is the long, safe road the one I came from.\n"
				"But if I take that, I will never make it in time.\n\n");
			break;
		case 3 :
			text.setString("The other road is short... \nbut no one ever takes it.\n"
				"Nobody really knows what is down there. \nIt is risky, maybe even dangerous.\n\n");
			break;
		case 4:
			text.setString("Still... \nif I want to get my backpack back \nbefore it is too late,\n"
				"I have to take the shortcut.\n\n");
			break;
		case 5 :
			text.setString("Think you can help me through it? Let s go together!");
			break;
		default :
			break;
		}



		window.clear();

		storyPage.draw(window);
		leo.draw(window);
		window.draw(text);
		window.draw(text2);

		window.display();

		if (clicked >= 6)
		{
			window.close();
		}
		
	}
}


void backStory()
{
	sf::RenderWindow window(sf::VideoMode(700.f, 700.f), "tutorial", sf::Style::None);


	background storyPage("storyPage.png");


	sf::Font font;
	font.loadFromFile("Fredoka.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25);
	text.setPosition(75.f, 100.f);
	text.setFillColor(sf::Color::Black);

	sf::Text text2;
	text2.setFont(font);
	text2.setCharacterSize(15);
	text2.setPosition(400.f, 600.f);
	text2.setFillColor(sf::Color::Black);
	text2.setString("TAP SPACE FOR THE NEXT");

	player leo("leo.png");
	leo.setposition(50.f, storyPage.getsize().y - leo.getsize().y - 50.f);

	int clicked = 0;

	while (window.isOpen())
	{

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Space)
			{
				++clicked;
			}
		}


		switch (clicked)
		{
		case 0:
			text.setString("Yes! I finally found my backpack!\n\n");
			break;
		case 1:
			text.setString("Now I need to go back.\n");
			break;
		case 2:
			text.setString("I can not move forward using the 'D' key anymore.\n\n");
			break;
		case 3:
			text.setString("From now on, use the 'Q' key to go back.\n\n");
			break;
		case 4:
			text.setString("It is not over yet let s get out of here!");
			break;
		default:
			break;
		}



		window.clear();

		storyPage.draw(window);
		leo.draw(window);
		window.draw(text);
		window.draw(text2);

		window.display();

		if (clicked >= 5)
		{
			window.close();
		}

	}
}


void endStory()
{
	sf::RenderWindow window(sf::VideoMode(700.f, 700.f), "tutorial", sf::Style::None);


	background storyPage("storyPage.png");


	sf::Font font;
	font.loadFromFile("Fredoka.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25);
	text.setPosition(75.f, 100.f);
	text.setFillColor(sf::Color::Black);

	sf::Text text2;
	text2.setFont(font);
	text2.setCharacterSize(15);
	text2.setPosition(400.f, 600.f);
	text2.setFillColor(sf::Color::Black);
	text2.setString("TAP SPACE FOR THE NEXT");

	player leo("leo.png");
	leo.setposition(50.f, storyPage.getsize().y - leo.getsize().y - 50.f);

	int clicked = 0;

	while (window.isOpen())
	{

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Space)
			{
				++clicked;
			}
		}


		switch (clicked)
		{
		case 0:
			text.setString("Thanks, man! You saved my day!\n");
			break;
		case 1:
			text.setString("Now, time to head home with my backpack!\n\n");
			break;
		case 2:
			text.setString("Thanks for being part of the adventure!\n\n");
			break;
		default:
			break;
		}



		window.clear();

		storyPage.draw(window);
		leo.draw(window);
		window.draw(text);
		window.draw(text2);

		window.display();

		if (clicked >= 3)
		{
			window.close();
		}

	}
}
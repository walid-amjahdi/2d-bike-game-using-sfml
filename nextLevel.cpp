#include "nextLevel.h"



int winingWindow()
{
	sf::RenderWindow window(sf::VideoMode(700.f, 700.f), "win window", sf::Style::None);

	background win("menu.png");

	botton nextLevel("play.png");
	nextLevel.setOrigin(nextLevel.getsize().x / 2.f, nextLevel.getsize().y / 2.f);
	nextLevel.setposition(win.getsize().x / 2.f, 200.f);

	botton goToMenu("return.png");
	goToMenu.setOrigin(goToMenu.getsize().x / 2.f, goToMenu.getsize().y / 2.f);
	goToMenu.scale(0.5f, 0.5f);
	goToMenu.setposition(win.getsize().x / 2.f, nextLevel.getposition().y + nextLevel.getsize().y + 50.f );

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Escape)
			{
				window.close();
				return 0; 
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (nextLevel.isclicked(sf::Mouse::getPosition(window)))
			{
				window.close();
				return 1;
			}
			if (goToMenu.isclicked(sf::Mouse::getPosition(window)))
			{
				window.close();
				return 0;
			}
		}
		window.clear();
		win.draw(window);
		nextLevel.draw(window);
		goToMenu.draw(window);
		window.display();
	}
}

int level2()
{
	sf::RenderWindow window(sf::VideoMode(700.f, 700.f), "level 2", sf::Style::None);

	sf::Font font;
	font.loadFromFile("Fredoka.ttf");
	sf::Text timetext;
	timetext.setFont(font);
	timetext.setFillColor(sf::Color::Black);
	timetext.setCharacterSize(25);


	sf::Text guidetext;
	guidetext.setFont(font);
	guidetext.setCharacterSize(20);
	guidetext.setFillColor(sf::Color::Black);
	guidetext.setString(" Q: Normal speed\n");

	//						backgrounds
	background Background1("background.png");

	background Background2("background2.png");
	Background2.setposition(Background1.getsize().x, 0.f);
	//                grounds
	ground Ground1("ground.png");
	Ground1.setposition(0.f, Background1.getsize().y - Ground1.getsize().y);
	ground Ground2("ground.png");
	Ground2.setposition(Ground1.getsize().x , Background2.getsize().y - Ground2.getsize().y);

	//            player 

	player leo("leoBack.png");
	leo.scale(0.5f, 0.5f);
	leo.setposition(2.f * Background1.getsize().x - leo.getsize().x - leo.initialPos, Ground1.getposition().y - leo.getsize().y );


	//				view 
	sf::View view;
	view.setSize(700.f, 700.f);

	//					obstacles
	obstacles obstacle1("obstacl1.png");
	obstacle1.scale(0.5f, 0.5f);
	obstacles obstacle2("obstacl2.png");
	obstacle2.scale(0.75f, 0.75f);
	obstacles obstacle3("obstacl3.png");
	obstacle3.scale(0.75f, 0.75f);

	float distance = 600.0f;


	obstacle1.setposition(leo.getposition().x - distance , Ground1.getposition().y - obstacle1.getsize().y);
	obstacle2.setposition(obstacle1.getposition().x - distance, Ground1.getposition().y - obstacle2.getsize().y);
	obstacle3.setposition(obstacle2.getposition().x - distance, Ground1.getposition().y - obstacle3.getsize().y);



	//			physics

	sf::Vector2f velocity(0.f, 0.f);

	sf::Clock deltaClock;
	sf::Clock timeClock;
	const float levelTime = 40.f;

	const float gravity = 981.f;

	//    checking's bools 
	bool start = false;
	bool win = false;

	while (window.isOpen())
	{
		//    physics updates

		float deltaT = deltaClock.restart().asSeconds();
		if (deltaT > 1.f / 60.f)
		{
			deltaT = 1.f / 60.f;
		}

		float remaining = 40.f;

		if (start)
		{
			remaining = levelTime - timeClock.getElapsedTime().asSeconds();
		}
		else
		{
			timeClock.restart();
		}

		if (remaining <= 5.f)
		{
			timetext.setFillColor(sf::Color::Red);
			timetext.setCharacterSize(30);
		}

		if (remaining <= 0.f)
		{
			window.close();
			return gameRestart();
		}

		if (start)
		{
			velocity.x = -50.f;
		}
		else
		{
		velocity.x = 0.f;
		}

		if (leo.getposition().x <= leo.initialPos + 10.f)
		{
			win = true;
			window.close();
			endStory();
			return 0;
		}


		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Escape)
			{
				window.close();
				return 0;
			}
		}


		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && leo.getposition().x >= leo.initialPos)
		{
			start = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				velocity.x = -leo.speed * leo.acceleration;
			}
			velocity.x += -leo.speed;
		}

		leo.isjumping = leo.getposition().y + leo.getsize().y < Ground2.getposition().y;

		
		if(!leo.isjumping)
		{
			velocity.y = 0.f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !leo.isjumping)
		{
			velocity.y = leo.jumpheight;
			leo.isjumping = true;
		}

		if (leo.isjumping)
		{
			velocity.y += gravity * deltaT;
		}

		leo.move(velocity * deltaT);

		float Xview = leo.getposition().x;

		Xview = std::min(Background1.getsize().x * 2.f - window.getSize().x / 2.f, std::max(window.getSize().x / 2.f, Xview));
		view.setCenter(Xview , window.getSize().y / 2.f);


		//			obstacles position 

		if (obstacle1.getposition().x > Xview  + window.getSize().x / 2.f && obstacle3.getposition().x > window.getSize().x )
		{
			obstacle1.setposition(obstacle3.getposition().x - distance, Ground1.getposition().y - obstacle1.getsize().y);
		}

		if (obstacle2.getposition().x > Xview + window.getSize().x / 2.f && obstacle1.getposition().x > window.getSize().x )
		{
			obstacle2.setposition(obstacle1.getposition().x - distance, Ground1.getposition().y - obstacle2.getsize().y);
		}

		if (obstacle3.getposition().x > Xview + window.getSize().x / 2.f && obstacle2.getposition().x > window.getSize().x )
		{
			obstacle3.setposition(obstacle2.getposition().x - distance, Ground1.getposition().y - obstacle3.getsize().y);
		}


		if (collision(leo, obstacle1) || collision(leo, obstacle2) || collision(leo, obstacle3))	
		{
			window.close();
			return gameRestart();
		}



		//		timer pos and text
		timetext.setString("Remaining time : " + std::to_string(static_cast<int>(remaining)) + "  sec");
		timetext.setOrigin(timetext.getGlobalBounds().width / 2.0f, timetext.getGlobalBounds().height / 2.0f);
		timetext.setPosition(Xview, 50.f);

		guidetext.setPosition(Xview + 100.f, 100.f);

		window.clear();
		
		window.setView(view);


		Background1.draw(window);
		Background2.draw(window);
		Ground1.draw(window);
		Ground2.draw(window);

		leo.draw(window);

		obstacle1.draw(window);
		obstacle2.draw(window);
		obstacle3.draw(window);

		window.draw(timetext);
		if (remaining >= 35.f)
		{
			window.draw(guidetext);
		}


		
		window.display();
	}


}
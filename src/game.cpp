#include "game.h"
#include "tutorial.h"

bool collision(sprites obj1, sprites obj2)
{
	return obj1.globalBounds().intersects(obj2.globalBounds());
}

int startGame()
{
	//				window

	sf::RenderWindow window(sf::VideoMode(700, 700),"level 1", sf::Style::None);
	
	//					view		
	sf::View view;
	view.setSize(700.f, 700.f);

	//			texts
	
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
	guidetext.setString("- Bike Control:\n"
		"  D: Normal speed\n"
		"  LShift: Acceleration\n"
		"  Space: Jump\n"
		"  Escape: Return to back\n");

	//sprites

	//					back and groud 
	background Background("background.png");

	ground Ground("Ground.png");
	Ground.setposition(0.f, Background.getsize().y - Ground.getsize().y);


	background Background2("background2.png");
	Background2.setposition(Background.getsize().x, 0.f);


	ground Ground2("Ground.png");
	Ground2.setposition(Background.getsize().x, Background.getsize().y - Ground.getsize().y);
	//							player
	player Player("bike.png");
	Player.scale(0.5f, 0.5f);
	Player.setposition(Player.initialPos, Ground.getposition().y - Player.getsize().y);
	//						obstacles 
	float distance = 550.0f;
	obstacles obstacl1("obstacl1.png");
	obstacl1.scale(0.5f, 0.5f);
	obstacles obstacl2("obstacl2.png");
	obstacl2.scale(0.75f, 0.75f);
	obstacles obstacl3("obstacl3.png");
	obstacl3.scale(0.75f, 0.75f);

	obstacl1.setposition(distance, Ground.getposition().y - obstacl1.getsize().y);
	obstacl2.setposition(obstacl1.getposition().x + obstacl1.getsize().x + distance, Ground.getposition().y - obstacl2.getsize().y);
	obstacl3.setposition(obstacl2.getposition().x + obstacl2.getsize().x + distance, Ground.getposition().y - obstacl3.getsize().y);


	// end flag

	sprites endflag("schoolBag.png");
	endflag.scale(0.5f, 0.5f);
	endflag.setposition(Ground.getsize().x * 2.f - 150.f, Ground.getposition().y - (endflag.getsize().y + 50.f));


	

	//							physics
	sf::Vector2 velocity(0.f, 0.f);

	sf::Clock clock;
	sf::Clock timerClock;
	const float levelTime = 40.f;
	
	const float gravity = 981.0f;

	//				bool losing
	bool start = false;
	bool lose = false;
	bool win = false;
	
	//						game loop 
	while (window.isOpen())
	{
		//  delta time and velocity updating 

		float deltaT = clock.restart().asSeconds();
		if (deltaT > 1.f / 60.f)
		{
			deltaT = 1.f / 60.f;
		}

		float remaining = 40.f;
		// timer checking 
		if (start)
		{
			remaining = levelTime - timerClock.getElapsedTime().asSeconds();
		}
		else
		{
			timerClock.restart();
		}

		if (remaining <= 5.0f)
		{
			timetext.setFillColor(sf::Color::Red);
			timetext.setCharacterSize(30);
		}
		 
		//  player speed
		 
		if (start && Player.getposition().x + Player.getsize().x < 2.f * Ground.getsize().x)
		{
			velocity.x = 50.f;
		}
		else
		{
			velocity.x = 0.f;
		}

		//					game logic
		// evnts 
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Escape)
			{
				window.close();
				return 0;
			}
		}



		//					updating
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Player.getposition().x + Player.getsize().x < 2.f * Ground.getsize().x)
		{
			start = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
				velocity.x = Player.speed * Player.acceleration;
			velocity.x += Player.speed;
		}
		//on ground detection 
		bool onground = Player.getposition().y >= Ground.getposition().y - Player.getsize().y;
		if (onground)
		{
			velocity.y = 0.f;
			Player.isjumping = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && onground)
		{
			velocity.y = Player.jumpheight;
			Player.isjumping = true;
		}
		if(Player.isjumping)
		{
		velocity.y += gravity * deltaT;
		}
		//				moving 
		Player.move(velocity * deltaT);
		//				seting view
		float Xview = Player.getposition().x + Player.getsize().x + 200;
		float halfWindow = window.getSize().x / 2.0f;

		Xview = std::max(halfWindow, std::min(Xview, 2.f * Ground.getsize().x - halfWindow));
		view.setCenter(Xview, Background.getsize().y / 2.0f);

		//		timer pos and text
		timetext.setString("Remaining time : " + std::to_string(static_cast<int>(remaining)) + "  sec");
		timetext.setOrigin(timetext.getGlobalBounds().width / 2.0f, timetext.getGlobalBounds().height / 2.0f);
		timetext.setPosition(Xview, 50.f);

		guidetext.setPosition(Xview + 100.f, 100.f);


		// obstacle's position updating

		if(obstacl1.getposition().x <= endflag.getposition().x - 2000.f)
		{
		if (obstacl1.getposition().x < Xview - (halfWindow + obstacl1.getsize().x))
			obstacl1.setposition(obstacl3.getposition().x + obstacl3.getsize().x + distance, Ground.getposition().y - obstacl1.getsize().y);
		}

		if (obstacl2.getposition().x <= endflag.getposition().x - 2000.f)
		{
		if (obstacl2.getposition().x < Xview - (halfWindow + obstacl2.getsize().x))
			obstacl2.setposition(obstacl1.getposition().x + obstacl1.getsize().x + distance, Ground.getposition().y - obstacl2.getsize().y);
		}

		if (obstacl3.getposition().x <= endflag.getposition().x - 2000.f)
		{
		if (obstacl3.getposition().x < Xview - (halfWindow + obstacl3.getsize().x))
			obstacl3.setposition(obstacl2.getposition().x + obstacl2.getsize().x + distance, Ground.getposition().y - obstacl3.getsize().y);
		}

		//			global checking


		if (Player.getposition().x + Player.getsize().x /2.f >= endflag.getposition().x)
		{
			win = true;
			window.close();
			backStory();
			return 2;
		}
		

		//				collision detction 
		lose = collision(Player, obstacl1) || collision(Player, obstacl2) || collision(Player, obstacl3) || remaining <= 0.f;

		if (lose) 
		{
			window.close();
			return gameRestart();
		}




		//					rendring 
		window.clear();

		window.setView(view);

		Background.draw(window);
		Ground.draw(window);
		Background2.draw(window);
		Ground2.draw(window);
		
		obstacl1.draw(window);
		obstacl2.draw(window);
		obstacl3.draw(window);
		
		window.draw(timetext);
		if (remaining >= 35.f)
		{
			window.draw(guidetext);
		}

		endflag.draw(window);

		Player.draw(window);

		window.display();
	}
}

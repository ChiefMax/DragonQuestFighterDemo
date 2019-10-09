#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "fightScreen.h"

int mainFightscreen() 
{
	return OpenFightWindow();
}

int OpenFightWindow()
{
	sf::RenderWindow battleWindow(sf::VideoMode(1280, 720), "Fight!");
	sf::RectangleShape rectangeleStrenght(sf::Vector2f(25.f,50.f));
	rectangeleStrenght.setFillColor(sf::Color(100, 250, 50));
	sf::Texture texture;
	sf::Texture player;
	sf::Texture enemy;
	sf::Texture headP;
	sf::Texture headE;
<<<<<<< HEAD
	sf::Texture attackT;
	sf::Texture prepareT;
	sf::Texture recoverT;
	sf::Texture castmagicT;
	sf::Texture quitT;

	//Loading Textures.
=======
>>>>>>> develop
	if (!texture.loadFromFile("img/background.jpg"))
		return EXIT_FAILURE;
	if (!player.loadFromFile("img/player.png"))
		return EXIT_FAILURE;
	if (!enemy.loadFromFile("img/enemy.png"))
		return EXIT_FAILURE;
	if (!headP.loadFromFile("img/headP.png"))
		return EXIT_FAILURE;
	if (!headE.loadFromFile("img/headE.png"))
		return EXIT_FAILURE;
	sf::Sprite fightScreenTexture(texture);
	sf::Sprite playerS(player);
	playerS.setPosition(450,200);
	sf::Sprite enemyS(enemy);
	enemyS.setPosition(700,200);
	sf::Sprite headPS(headP);
	headPS.setPosition(100,50);
	sf::Sprite headES(headE);
	headES.setPosition(1100, 50);
	while (battleWindow.isOpen())
	{
		sf::Event evnt;
		while (battleWindow.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:battleWindow.close();
				break;
			default:
				break;
			}
		}
		battleWindow.clear();
		battleWindow.draw(fightScreenTexture);
		battleWindow.draw(playerS);
		battleWindow.draw(enemyS);
		battleWindow.draw(headPS);
		battleWindow.draw(headES);
		battleWindow.draw(rectangeleStrenght);
		battleWindow.display();
	}
	return 0;
}

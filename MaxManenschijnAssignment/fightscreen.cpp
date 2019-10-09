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

	sf::RectangleShape rectangeleStrength(sf::Vector2f(25.f,50.f));
	rectangeleStrength.setFillColor(sf::Color(255, 0, 0));

	sf::RectangleShape rectangeleStrengthEnemy(sf::Vector2f(25.f, 50.f));
	rectangeleStrengthEnemy.setFillColor(sf::Color(255, 0, 0));

	sf::RectangleShape rectangeleAgilty(sf::Vector2f(25.f, 50.f));
	rectangeleAgilty.setFillColor(sf::Color(0, 255, 0));

	sf::RectangleShape rectangeleAgiltyEnemy(sf::Vector2f(25.f, 50.f));
	rectangeleAgiltyEnemy.setFillColor(sf::Color(0, 255, 0));

	sf::RectangleShape rectangeleWits(sf::Vector2f(25.f, 50.f));
	rectangeleWits.setFillColor(sf::Color(0, 0, 255));

	sf::RectangleShape rectangeleWitsEnemy(sf::Vector2f(25.f, 50.f));
	rectangeleWitsEnemy.setFillColor(sf::Color(0, 0, 255));

	sf::Texture texture;
	sf::Texture player;
	sf::Texture enemy;
	sf::Texture headP;
	sf::Texture headE;

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

	//Player Stats
	rectangeleStrength.setPosition(105, 180);
	rectangeleAgilty.setPosition(145, 180);
	rectangeleWits.setPosition(185, 180);

	//Enemy Stats
	rectangeleStrengthEnemy.setPosition(1100, 180);
	rectangeleAgiltyEnemy.setPosition(1140, 180);
	rectangeleWitsEnemy.setPosition(1180, 180);

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
		battleWindow.draw(rectangeleStrength);
		battleWindow.draw(rectangeleStrengthEnemy);
		battleWindow.draw(rectangeleAgilty);
		battleWindow.draw(rectangeleWits);
		battleWindow.draw(rectangeleAgiltyEnemy);
		battleWindow.draw(rectangeleWitsEnemy);
		battleWindow.display();
	}
	return 0;
}

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

	sf::RectangleShape rectangeleHealth(sf::Vector2f(200.f, 25.f));
	rectangeleHealth.setFillColor(sf::Color(255, 0, 0));

	sf::RectangleShape rectangeleMana(sf::Vector2f(200.f, 25.f));
	rectangeleMana.setFillColor(sf::Color(0, 0, 255));

	sf::RectangleShape rectangeleHealthEnemy(sf::Vector2f(200.f, 25.f));
	rectangeleHealthEnemy.setFillColor(sf::Color(255, 0, 0));

	sf::RectangleShape rectangeleManaEnemy(sf::Vector2f(200.f, 25.f));
	rectangeleManaEnemy.setFillColor(sf::Color(0, 0, 255));

	sf::Texture texture;
	sf::Texture player;
	sf::Texture enemy;
	sf::Texture headP;
	sf::Texture headE;
	sf::Texture attackT;
	sf::Texture prepareT;
	sf::Texture recoverT;
	sf::Texture castmagicT;
	sf::Texture quitT;

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
	headES.setPosition(1000, 50);

	//Player Stats
	rectangeleStrength.setPosition(50, 180);
	rectangeleAgilty.setPosition(150, 180);
	rectangeleWits.setPosition(250, 180);

	//Player Heatlh and Mana
	rectangeleHealth.setPosition(50, 250);
	rectangeleMana.setPosition(50, 300);

	//Enemy Stats
	rectangeleStrengthEnemy.setPosition(950, 180);
	rectangeleAgiltyEnemy.setPosition(1050, 180);
	rectangeleWitsEnemy.setPosition(1150, 180);

	//Enemy Health and Mana
	rectangeleHealthEnemy.setPosition(950, 250);
	rectangeleManaEnemy.setPosition(950, 300);

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
		battleWindow.draw(rectangeleHealth);
		battleWindow.draw(rectangeleMana);
		battleWindow.draw(rectangeleHealthEnemy);
		battleWindow.draw(rectangeleManaEnemy);
		battleWindow.display();
	}
	return 0;
}

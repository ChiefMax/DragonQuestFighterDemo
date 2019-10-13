#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "main.h"
#include <Windows.h>
#include "fightScreen.h"
#include "scene.h"
#include "spriteObject.hpp"
#include "sceneHandler.h"
#include <string>
#include <iostream>

int main() {

	bool battleWindowOpen = false;
	bool once = false;
	int counter = 0;
	bool fightWindowBool = false;

	sf::RenderWindow ourWindow(sf::VideoMode(1280, 720), "Dronken Quest");
	Scene scene1("scene01");

	SpriteObject sprite1("backgroundSprite", "img/backgroundMainMenu.png");
	scene1.addGameObject(sprite1);

	SpriteObject playSprite("playSprite", "img/buttonStart.png");
	playSprite.setPosition(sf::Vector2f(1100.0f, 150.0f));
	scene1.addGameObject(playSprite);

	SpriteObject eraseSprite("eraseSprite", "img/trashcan.png");
	eraseSprite.setPosition(sf::Vector2f(1100.0f, 250.0f));
	scene1.addGameObject(eraseSprite);

	SpriteObject quitSprite("quitSprite", "img/exit.png");
	quitSprite.setPosition(sf::Vector2f(1100.0f, 350.0f));
	scene1.addGameObject(quitSprite);

	//Button handling.
	sf::Texture playT;
	sf::Texture eraseT;
	sf::Texture quitT;
	if (!playT.loadFromFile("img/buttonStart.png"))
		return EXIT_FAILURE;
	if (!eraseT.loadFromFile("img/trashcan.png"))
		return EXIT_FAILURE;
	if (!quitT.loadFromFile("img/exit.png"))
		return EXIT_FAILURE;
	sf::Sprite play(playT);
	play.setPosition(sf::Vector2f(1100, 150));
	sf::Sprite erase(eraseT);
	erase.setPosition(sf::Vector2f(1100, 250));
	sf::Sprite quit(quitT);
	quit.setPosition(sf::Vector2f(1100, 350));

	Scene scene2("scene02");

	/*sf::RectangleShape rectangeleStrength(sf::Vector2f(25.f, 50.f));
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
	rectangeleManaEnemy.setFillColor(sf::Color(0, 0, 255));*/

	SpriteObject playerStatsSprite("playerStatsSprite", "img/playerStatsT.png");
	playerStatsSprite.setPosition(sf::Vector2f(50.0f, 50.0f));
	scene2.addGameObject(playerStatsSprite);

	SpriteObject enemyStatsSprite("enemyStatsSprite", "img/enemyStatsT.png");
	enemyStatsSprite.setPosition(sf::Vector2f(950.0f, 50.0f));
	scene2.addGameObject(enemyStatsSprite);

	SpriteObject playerSprite("playerSprite", "img/player.png");
	playerSprite.setPosition(sf::Vector2f(450, 200));
	scene2.addGameObject(playerSprite);

	SpriteObject enemySprite("enemySprite", "img/enemy.png");
	enemySprite.setPosition(sf::Vector2f(700, 200));
	scene2.addGameObject(enemySprite);


	sf::RectangleShape rectangeleHealth(sf::Vector2f(200.f, 25.f));
	rectangeleHealth.setFillColor(sf::Color(255, 0, 0));

	sf::RectangleShape rectangeleMana(sf::Vector2f(200.f, 25.f));
	rectangeleMana.setFillColor(sf::Color(0, 0, 255));

	sf::RectangleShape rectangeleHealthEnemy(sf::Vector2f(200.f, 25.f));
	rectangeleHealthEnemy.setFillColor(sf::Color(255, 0, 0));

	sf::RectangleShape rectangeleManaEnemy(sf::Vector2f(200.f, 25.f));
	rectangeleManaEnemy.setFillColor(sf::Color(0, 0, 255));

	//Player Heatlh and Mana
	rectangeleHealth.setPosition(90, 300);
	rectangeleMana.setPosition(90, 350);

	//Enemy Health and Mana
	rectangeleHealthEnemy.setPosition(990, 300);
	rectangeleManaEnemy.setPosition(990, 350);

	SceneHandler handler;
	handler.addScene(scene1);
	handler.addScene(scene2);

	while (ourWindow.isOpen())
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			// transform the mouse position from window coordinates to world coordinates
			sf::Vector2f mouse = ourWindow.mapPixelToCoords(sf::Mouse::getPosition(ourWindow));

			// retrieve the bounding box of the sprite
			sf::FloatRect boundsPlayButton = play.getGlobalBounds();
			sf::FloatRect boundsQuitButton = quit.getGlobalBounds();

			//Going to the next screen.
			if (boundsPlayButton.contains(mouse))
			{
				// mouse is on sprite!
				battleWindowOpen = true;
				once = true;
				fightWindowBool = true;
				//counter++;
			}

			//Closing the game.
			if (boundsQuitButton.contains(mouse))
			{
				// mouse is on sprite!
				ourWindow.close();
			}
		}


		sf::Event evnt;
		while (ourWindow.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed) {
				ourWindow.close();
			}
			if (battleWindowOpen && once) {
				if (counter == 0) {
					handler.stackScene("scene02");
					counter++;
					ourWindow.clear();
				}
				else {
					handler.popScene();
					counter--;
				}
			}
		}
		ourWindow.clear();
		//ourWindow.draw(play);
		//ourWindow.draw(erase);
		//ourWindow.draw(quit);
		handler.update();
		handler.render(ourWindow);
		if (fightWindowBool) 
		{
			DrawHeathAndMana(ourWindow, rectangeleHealth, rectangeleMana, rectangeleHealthEnemy, rectangeleManaEnemy);
		}
		ourWindow.display();

		if (battleWindowOpen && once) 
		{
			once = false;
		}
	}
}

void DrawHeathAndMana(sf::RenderWindow &ourWindow, sf::RectangleShape &rectangeleHealth, sf::RectangleShape &rectangeleMana, sf::RectangleShape &rectangeleHealthEnemy, sf::RectangleShape &rectangeleManaEnemy)
{
	ourWindow.draw(rectangeleHealth);
	ourWindow.draw(rectangeleMana);
	ourWindow.draw(rectangeleHealthEnemy);
	ourWindow.draw(rectangeleManaEnemy);
}

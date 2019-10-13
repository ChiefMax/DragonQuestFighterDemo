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

	Scene scene2("scene02");

	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(100, 250, 50));
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
	play.setPosition(sf::Vector2f(1100,150));
	sf::Sprite erase(eraseT);
	erase.setPosition(sf::Vector2f(1100, 250));
	sf::Sprite quit(quitT);
	quit.setPosition(sf::Vector2f(1100, 350));

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
				switch (evnt.type)
				{
				case sf::Event::Closed:ourWindow.close(); break;
				default:
					break;
				}
			}
		}
		ourWindow.clear();
		//ourWindow.draw(play);
		//ourWindow.draw(erase);
		//ourWindow.draw(quit);
		handler.update();
		handler.render(ourWindow);
		ourWindow.display();

		if (battleWindowOpen && once) 
		{
			once = false;
		}
	}
}

//void FightWindow(sf::CircleShape &shape)
//{
//	//Hadouken!
//	sf::RenderWindow battleWindow(sf::VideoMode(1280, 720), "Fight!");
//	while (battleWindow.isOpen())
//	{
//		sf::Event evnt;
//		while (battleWindow.pollEvent(evnt))
//		{
//			switch (evnt.type)
//			{
//			case sf::Event::Closed:battleWindow.close();
//				break;
//			default:
//				break;
//			}
//		}
//		battleWindow.clear();
//		battleWindow.draw(shape);
//		battleWindow.display();
//	}
//}

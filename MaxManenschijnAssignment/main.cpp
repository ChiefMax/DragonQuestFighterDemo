#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {

	bool battleWindowOpen = false;
	bool once = false;

	sf::RenderWindow ourWindow(sf::VideoMode(1280, 720), "Dronken Quest");

	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(100, 250, 50));
	sf::Texture texture;
	sf::Texture playT;
	sf::Texture eraseT;
	sf::Texture quitT;
	if (!texture.loadFromFile("img/backgroundMainMenu.jpg"))
		return EXIT_FAILURE;
	if (!playT.loadFromFile("img/buttonStart.png"))
		return EXIT_FAILURE;
	if (!eraseT.loadFromFile("img/trashcan.png"))
		return EXIT_FAILURE;
	if (!quitT.loadFromFile("img/exit.png"))
		return EXIT_FAILURE;
	sf::Sprite backgroundMainMenu(texture);
	sf::Sprite play(playT);
	play.setPosition(sf::Vector2f(1100,150));
	sf::Sprite erase(eraseT);
	erase.setPosition(sf::Vector2f(1100, 250));
	sf::Sprite quit(quitT);
	quit.setPosition(sf::Vector2f(1100, 350));

	while (ourWindow.isOpen())
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			// transform the mouse position from window coordinates to world coordinates
			sf::Vector2f mouse = ourWindow.mapPixelToCoords(sf::Mouse::getPosition(ourWindow));

			// retrieve the bounding box of the sprite
			sf::FloatRect boundsPlayButton = play.getGlobalBounds();
			sf::FloatRect boundsQuitButton = quit.getGlobalBounds();

			// Going to the next screen.
			if (boundsPlayButton.contains(mouse))
			{
				// mouse is on sprite!
				battleWindowOpen = true;
				once = true;
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
			switch (evnt.type)
			{
			case sf::Event::Closed:ourWindow.close(); break;
			default:
				break;
			}
		}
		ourWindow.clear();
		ourWindow.draw(backgroundMainMenu);
		ourWindow.draw(play);
		ourWindow.draw(erase);
		ourWindow.draw(quit);
		ourWindow.display();

		if (battleWindowOpen && once) 
		{
			//Hadouken!
			sf::RenderWindow battleWindow(sf::VideoMode(1280, 720), "Fight!");
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
				battleWindow.draw(shape);
				battleWindow.display();
			}
			once = false;
		}
	}
}
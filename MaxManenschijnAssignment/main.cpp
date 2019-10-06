#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow ourWindow(sf::VideoMode(1280, 720), "My Game");
	
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
	}
}
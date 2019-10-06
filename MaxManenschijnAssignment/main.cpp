#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow ourWindow(sf::VideoMode(800, 600), "My Game");
	
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(100, 250, 50));
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
		ourWindow.draw(shape);
		ourWindow.display();
	}
}
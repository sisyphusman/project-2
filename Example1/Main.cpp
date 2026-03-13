#include <iostream>

#include <SFML/Graphics.hpp>

// 창 띄우기
int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1980, 1080 }), "Example1");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}
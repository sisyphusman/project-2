#include <iostream>

#include <SFML/Graphics.hpp>

// 마우스를 중심으로 원 그리기
int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1980, 1080 }), "Example2");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	// 좌표 기준을 원의 왼쪽 위에서 (100, 100) 만큼 이동
	shape.setOrigin({ 100.f, 100.f });

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		sf::Vector2i mouseWindowPos = sf::Mouse::getPosition(window);
		shape.setPosition({
			static_cast<float>(mouseWindowPos.x),
			static_cast<float>(mouseWindowPos.y)
		});

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
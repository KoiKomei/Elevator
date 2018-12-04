#include "LeftRight.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

	Handler* h = new Handler();

	Paint* p = new Paint();
	Click* l = new Left(p);
	Click* r = new Right(p);


	window.display();
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				(*h).execute(l, window, event);
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				(*h).execute(r, window, event);
			}
		}
		if (event.type == sf::Event::KeyReleased) {
			switch (event.key.code) {
			case sf::Keyboard::R:
				window.clear();
				window.display();
				break;
			case sf::Keyboard::Q:
				(*h).increase(l);
				break;
			case sf::Keyboard::W:
				(*h).reduce(l);
				break;
			case sf::Keyboard::A:
				(*h).increase(r);
				break;
			case sf::Keyboard::S:
				(*h).reduce(r);
				break;
			case sf::Keyboard::E:
				(*h).normal(l);
				break;
			case sf::Keyboard::D:
				(*h).normal(r);
				break;
			case sf::Keyboard::Escape:
				window.close();
				break;
			}
		}
	}

	return 0;
}
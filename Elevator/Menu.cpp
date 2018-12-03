#include "Menu.h"

Menu::Menu(float width, float height) {

	selectedItemIndex = 0;
	
	background.loadFromFile("el2.png");
	sprite.setTexture(background);
	menu[0].setFont(font);
	menu[0].setCharacterSize(60);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f((width / 2)-50, height / (ITEM_NUMBER)*1));

	menu[1].setFont(font);
	menu[1].setCharacterSize(60);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f((width / 2)-50, height / (ITEM_NUMBER)*2));

}


void Menu::draw(sf::RenderWindow &window) {
	window.draw(sprite);
	for (int i = 0; i < ITEM_NUMBER-1; i++) {
		window.draw(menu[i]);
	}

}

void Menu::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}


}

void Menu::MoveDown() {
	if (selectedItemIndex +1< ITEM_NUMBER-1) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}

}

void Menu::drawer(Context* cont, sf::RenderWindow &window) {
	bool open = true;
	bool es = false;
	while (open)	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				open = false;
			}
			if (event.type == sf::Event::MouseMoved) {
				cout << event.mouseMove.x << endl;
				cout << event.mouseMove.y << endl;
			}
			
			if (event.type == sf::Event::MouseButtonPressed) {
				cout << menu[0].getPosition().y << endl;
				cout << menu[0].getPosition().x << endl;
				if (event.mouseButton.button == sf::Mouse::Right && event.mouseButton.x == menu[0].getPosition().x && menu[0].getPosition().y==event.mouseButton.y) {
					cout << "Right was clicked over 300" << endl;
				}
				else if (event.mouseButton.button == sf::Mouse::Right) {
					cout << "Right was clicked " << endl;

				}
			}
			
			if (event.type == sf::Event::KeyReleased) {
				switch (event.key.code) {
				case sf::Keyboard::W:
					MoveUp();
					break;
				case sf::Keyboard::S:
					MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (GetPressedItem()) {
					case 0:
						cout << "Play button" << endl;
						open = false;
						es = true;
						break;
					case 1:
						cout << "Esc button" << endl;
						open = false;
						break;
					}
				}
			}
			
		}
		

		window.clear();
		draw(window);
		window.display();
	}
	if (es) {
			cont->setState(new Game(window.getSize().x, window.getSize().y));
			cont->changer(window);
	}
	
}
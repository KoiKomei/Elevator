#pragma once
#include "Menu.h"
class Up: public Floors {

public:
	Up() {
		txt.setFont(font);
		txt.setCharacterSize(48);
		txt.setFillColor(sf::Color::Red);
		txt.setString("Moving up");
		txt.setPosition(sf::Vector2f(220, 80));
	}
	void moving(Game* game, sf::RenderWindow &window);


};

class Down : public Floors {

public:
	Down() {
		txt.setFont(font);
		txt.setCharacterSize(48);
		txt.setFillColor(sf::Color::Red);
		txt.setString("Moving down");
		txt.setPosition(sf::Vector2f(200, 80));
	}

	void moving(Game* game, sf::RenderWindow &window);


};

class Idle : public Floors {

public:
	void moving(Game* game, sf::RenderWindow &window);


};
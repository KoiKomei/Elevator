#pragma once

#include "Click.h"

class Right:public Click {
public:
	Right(Paint* p) {
		DefaultSize();
		
		paint = p;
		bl.setFillColor(sf::Color::Blue);
		
	}
	void ReduceSize() {

		bl.setRadius(10.0);

	}
	void IncreaseSize() {

		bl.setRadius(30.0);

	}
	void DefaultSize() {
		bl.setRadius(20.0);
	}
	void circledraw(sf::RenderWindow &window, sf::Event &event) {
		bl.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
		//circles.push_back(bl);
		(*paint).blue(bl,window, event);
	};
private:
	Paint* paint;
	sf::CircleShape bl;
	float radius;


};

class Left :public Click {
public:
	Left(Paint* p) {
		DefaultSize();
		
		paint = p;
		bl.setFillColor(sf::Color::Red);
		
	}
	void circledraw(sf::RenderWindow &window, sf::Event &event) {
		
		bl.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
		//circles.push_back(bl);
		(*paint).red(bl, window, event);
	}
	void ReduceSize() {
		
			bl.setRadius(10.0);
		
	}
	void IncreaseSize() {
		
			bl.setRadius(30.0);
		
	}
	void DefaultSize() {
		bl.setRadius(20.0);
	}
private:
	Paint* paint;
	sf::CircleShape bl;
	
};
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace std;
class Click {

public:
	virtual void circledraw(sf::RenderWindow &window, sf::Event &event)=0;
	virtual void ReduceSize() = 0;
	virtual void IncreaseSize() = 0;
	virtual void DefaultSize() = 0;

protected:
	vector<sf::CircleShape> circles;
	
	
};

class Paint {
		
public:
	void blue(sf::CircleShape &c, sf::RenderWindow &window, sf::Event &event) {
		window.draw(c);
		window.display();
	}
	void red(sf::CircleShape &c, sf::RenderWindow &window, sf::Event &event) {
		window.draw(c);
		window.display();
	}

};

class Handler {

public:
	void execute(Click* c, sf::RenderWindow &window, sf::Event &event) {
		(*c).circledraw(window, event);
	}

	void reduce(Click* c) {
		(*c).ReduceSize();
	}
	void increase(Click *c) {
		(*c).IncreaseSize();
	}

	void normal(Click *c) {
		(*c).DefaultSize();
	}
	
};
#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
using namespace std;
class Menu;
class Context;

class State {

public:

	State() { font.loadFromFile("arial.ttf"); };
	virtual void drawer(Context* cont, sf::RenderWindow &window) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
protected:
	int selectedItemIndex;
	sf::Font font;
	sf::Texture background;
	sf::Sprite sprite;

};


class Context {
	
public:
	
	Context(sf::RenderWindow &window);
	void setState(State* state) {
		current = state;
		
	}
	void changer(sf::RenderWindow &window) {
		(*current).drawer(this, window);
		
	}

private:
	State* current;
	

};


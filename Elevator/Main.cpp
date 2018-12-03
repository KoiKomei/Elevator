
#include <iostream>
#include "Menu.h"
using namespace std;
int main(){
	cout << "Hello world!"<<endl;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	Context cont(window);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	cont.changer(window);
	window.close();

	return 0;
}
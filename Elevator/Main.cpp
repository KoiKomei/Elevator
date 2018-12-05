
#include <iostream>
#include "Menu.h"
using namespace std;
int main(){
	cout << "Hello world!"<<endl;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	Context cont(window);
	cont.changer(window);
	window.close();

	return 0;
}
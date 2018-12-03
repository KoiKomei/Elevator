#include "Moving.h"

void Up::moving(Game *game, sf::RenderWindow &window) {
	cout << "We are moving up lads"<<endl;
	window.draw(txt);
	window.display();
	this_thread::sleep_for(chrono::milliseconds(3000));
	game->setMotion(new Idle());
	game->AscDesc(window);
}

void Down::moving(Game *game, sf::RenderWindow &window) {
	cout << "We are moving down lads"<<endl;
	window.draw(txt);
	window.display();
	this_thread::sleep_for(chrono::milliseconds(3000));
	game->setMotion(new Idle());
	game->AscDesc(window);
}

void Idle::moving(Game *game, sf::RenderWindow &window) {
	cout << "We are idling lad"<<endl;
}
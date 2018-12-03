#include "StateAndContext.h"
#include "Menu.h"

Context::Context(sf::RenderWindow& window) {
	setState(new Menu(window.getSize().x, window.getSize().y));
}
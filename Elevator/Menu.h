#pragma once

#include "StateAndContext.h"
#define ITEM_NUMBER 3
#define ROW_ 3
#define COLUMN_ 2
class Floors;
class Menu: public State{
public:
	Menu(float width, float height);
	~Menu() {};

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	
	void drawer(Context* cont, sf::RenderWindow &window);
private:
	sf::Text menu[ITEM_NUMBER];
};



class Game : public State {

public:
	Game(float width, float height);
	~Game() {};
	void draw(sf::RenderWindow &window);
	void drawer(Context* cont, sf::RenderWindow &window);
	int getPressedItem();
	int getSndItem() { return index; }
	void Move(int m);
	void setMotion(Floors *fl);
	void AscDesc(sf::RenderWindow &window);

private:
	
	sf::Text buttons[ROW_][COLUMN_];
	sf::RectangleShape shape;
	sf::RectangleShape shape2;
	int index;
	Floors* floor;
	int currentFloor;
	sf::Sprite charas[6];
	sf::Texture t[6];

};

class Floors {
public:
	Floors() { font.loadFromFile("arial.ttf"); };
	virtual void moving(Game *game, sf::RenderWindow &window) = 0;

protected:
	sf::Text txt;
	sf::Font font;

};
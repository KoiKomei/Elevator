#include "Menu.h"
#include "Moving.h"

Game::Game(float width, float height) {
	setMotion(new Idle());
	selectedItemIndex = 0;
	index = 0;
	currentFloor = 1;
	background.loadFromFile("el3.png");
	t[0].loadFromFile("elp1.png");
	t[1].loadFromFile("elp2.png");
	t[2].loadFromFile("elp3.png");
	t[3].loadFromFile("elp4.png");
	t[4].loadFromFile("elp5.png");
	t[5].loadFromFile("elp6.png");
	for (int i = 0; i < 6; i++) {
		charas[i].setTexture(t[i]);
	}
	sprite.setTexture(background);
	shape.setFillColor(sf::Color::Cyan);
	shape.setSize(sf::Vector2f(400, 600));
	shape.setPosition(sf::Vector2f(100, 50));
	shape2.setFillColor(sf::Color::Black);
	shape2.setSize(sf::Vector2f(390, 590));
	shape2.setPosition(sf::Vector2f(105, 55));

	
	buttons[0][0].setFont(font);
	buttons[0][0].setCharacterSize(60);
	buttons[0][0].setFillColor(sf::Color::Red);
	buttons[0][0].setString("1");
	buttons[0][0].setPosition(sf::Vector2f(260,160));

	
	buttons[0][1].setFont(font);
	buttons[0][1].setCharacterSize(60);
	buttons[0][1].setFillColor(sf::Color::White);
	buttons[0][1].setString("2");
	buttons[0][1].setPosition(sf::Vector2f(400,160));

	buttons[1][0].setFont(font);
	buttons[1][0].setCharacterSize(60);
	buttons[1][0].setFillColor(sf::Color::White);
	buttons[1][0].setString("3");
	buttons[1][0].setPosition(sf::Vector2f(260, 300));

	
	buttons[1][1].setFont(font);
	buttons[1][1].setCharacterSize(60);
	buttons[1][1].setFillColor(sf::Color::White);
	buttons[1][1].setString("4");
	buttons[1][1].setPosition(sf::Vector2f(400,300));

	buttons[2][0].setFont(font);
	buttons[2][0].setCharacterSize(60);
	buttons[2][0].setFillColor(sf::Color::White);
	buttons[2][0].setString("5");
	buttons[2][0].setPosition(sf::Vector2f(260,440));


	buttons[2][1].setFont(font);
	buttons[2][1].setCharacterSize(60);
	buttons[2][1].setFillColor(sf::Color::White);
	buttons[2][1].setString("6");
	buttons[2][1].setPosition(sf::Vector2f(400,440));
}

void Game::draw(sf::RenderWindow &window) {
	window.draw(sprite);
	window.draw(charas[currentFloor-1]);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			window.draw(buttons[i][j]);
		}
	}
	
	
}

void Game::Move(int m) {
	switch (m) {
	case 0:
		if (selectedItemIndex -1 >= 0) {
			buttons[selectedItemIndex][index].setFillColor(sf::Color::White);
			selectedItemIndex--;
			buttons[selectedItemIndex][index].setFillColor(sf::Color::Red);
		}
		break;
	case 1:
		if (selectedItemIndex + 1 < ROW_) {
			buttons[selectedItemIndex][index].setFillColor(sf::Color::White);
			selectedItemIndex++;
			buttons[selectedItemIndex][index].setFillColor(sf::Color::Red);
		}
		break;
	case 2:
		if (index+ 1 < COLUMN_) {
			buttons[selectedItemIndex][index].setFillColor(sf::Color::White);
			index++;
			buttons[selectedItemIndex][index].setFillColor(sf::Color::Red);
		}
		break;
	case 3:
		if (index - 1 >= 0) {
			buttons[selectedItemIndex][index].setFillColor(sf::Color::White);
			index--;
			buttons[selectedItemIndex][index].setFillColor(sf::Color::Red);
		}
		break;
	}

}


int Game::getPressedItem() { return selectedItemIndex; }

void Game::drawer(Context* cont, sf::RenderWindow &window) {
	bool open = true;
	bool es = false;
	int movement = 0;
	while (open) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				open = false;
				es = true;
			}
			if (event.type == sf::Event::MouseMoved) {
				cout << event.mouseMove.x << endl;
				cout << event.mouseMove.y << endl;
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				cout << buttons[0][0].getPosition().y << endl;
				cout << buttons[0][0].getPosition().x << endl;
				if (event.mouseButton.button == sf::Mouse::Right) {
					cout << "Right was clicked " << endl;

				}
			}

			if (event.type == sf::Event::KeyReleased) {
				switch (event.key.code) {
				case sf::Keyboard::W:
					cout << "Funzione W"<<endl;
					movement = 0;
					Move(movement);
					break;
				case sf::Keyboard::S:
					cout << "Funzione S"<<endl;
					movement = 1;
					Move(movement);
					break;
				case sf::Keyboard::D:
					cout << "Funzione D"<<endl;
					movement = 2;
					Move(movement);
					break;
				case sf::Keyboard::A:
					cout << "Funzione A" << endl;
					movement = 3;
					Move(movement);
					break;
				case sf::Keyboard::Escape:
					open = false;
					es = true;
					break;

				case sf::Keyboard::Return:
					switch (getPressedItem()) {
					case 0:
						switch (getSndItem()) {
						case 0:
							cout << "1" << endl;
							if (currentFloor > 1) {
								setMotion(new Down());
								floor->moving(this, window);
							}
							else {
								floor->moving(this, window);
							}
							currentFloor = 1;
							break;
						case 1:
							cout << "2" << endl;
							if (currentFloor > 2) {
								setMotion(new Down());
								floor->moving(this, window);
							}
							else if(currentFloor<2) {
								setMotion(new Up());
								floor->moving(this, window);
							}
							else {
								floor->moving(this, window);
							}
							currentFloor = 2;
							break;
						}
						break;
					
					case 1:
						switch (getSndItem()) {
						case 0:
							cout << "3" << endl;
							if (currentFloor > 3) {
								setMotion(new Down());
								floor->moving(this, window);
							}
							else if (currentFloor < 3) {
								setMotion(new Up());
								floor->moving(this, window);
							}
							else {
								floor->moving(this, window);
							}
							currentFloor = 3;
							break;
						case 1:
							cout << "4" << endl;
							if (currentFloor > 4) {
								setMotion(new Down());
								floor->moving(this, window);
							}
							else if (currentFloor < 4) {
								setMotion(new Up());
								floor->moving(this, window);
							}
							else {
								floor->moving(this, window);
							}
							currentFloor = 4;
							break;
						}
						break;
					case 2:
						switch (getSndItem()) {
						case 0:
							cout << "5" << endl;
							if (currentFloor > 5) {
								setMotion(new Down());
								floor->moving(this, window);
							}
							else if (currentFloor < 5) {
								setMotion(new Up());
								floor->moving(this, window);
							}
							else {
								floor->moving(this, window);
							}
							currentFloor = 5;
							break;
						case 1:
							cout << "6" << endl;
							if (currentFloor < 6) {
								setMotion(new Up());
								floor->moving(this, window);
							}
							else {
								floor->moving(this, window);
							}
							currentFloor = 6;
							break;
						}
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
		cont->setState(new Menu(window.getSize().x, window.getSize().y));
		cont->changer(window);
	}
}

void Game::setMotion(Floors *fl) { floor = fl; }

void Game::AscDesc(sf::RenderWindow &window) {
	(*floor).moving(this, window);
}
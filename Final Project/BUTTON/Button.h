
#ifndef BUTTON_H
#define BUTTON_H
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Button {
private:
	bool active;
	bool pressed = true;
	sf::Vector2i mousePos = sf::Vector2i(0,0);
	sf::CircleShape button;
	sf::Text text;
public: 
	Button(float yPosition, float xPosition, float scaledSize, std::string headline, sf::Font& font);
	void isPressed(sf::Vector2i mousePosition);
	bool isActive();
	void switchState();
	void draw(sf::RenderTarget& window);

};
#endif // !BUTTON_H
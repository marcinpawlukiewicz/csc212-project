#include "Button.h"
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

Button::Button(float yPosition, float xPosition, float scaledSize, std::string headline, sf::Font& font) {
    
    active = false;

    button.setPosition(xPosition, yPosition);
    button.setRadius(scaledSize);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(2);
    button.setFillColor(sf::Color(230, 230, 230));

    sf::String word = headline;

    text.setString(word);
    text.setFont(font);
    text.setCharacterSize(scaledSize/2);
    text.setPosition(xPosition + scaledSize/2 - headline.length(), yPosition - 30);
    text.setFillColor(sf::Color::Black);
}

void Button::isPressed(sf::Vector2i mousePosition) {
    
    mousePos = mousePosition;
    if (mousePos.x >= button.getPosition().x && mousePos.x <= ( button.getPosition().x + 2 * button.getRadius() )
        && mousePos.y >= button.getPosition().y && mousePos.y <= (button.getPosition().y + 2 * button.getRadius())) {
        
        button.setFillColor(sf::Color::Cyan);

        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            pressed = false;
            if (!active) {
                active = true;
                button.setFillColor(sf::Color::Cyan);
            }
            else {
                active = false;
                button.setFillColor(sf::Color(230, 230, 230));
            }
           

        }
    }
    else if(!active){
        button.setFillColor(sf::Color(230, 230, 230));
    }
}

bool Button::isActive() {
    return active;
}

void Button::switchState() {
    active = false;
}

void Button::draw(sf::RenderTarget& window) {
    window.draw(text);
    window.draw(button);
}
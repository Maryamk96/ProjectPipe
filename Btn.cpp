#include "Btn.h"

Btn::Btn(float x, float y, float w, float h) 
{
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(w, h));
}

void Btn::events(sf::Vector2f mousePos) 
{
    isClicked = false;
    if (shape.getGlobalBounds().contains(mousePos))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
        {
            isClicked = true;
        }
    }
}

void Btn::render(sf::RenderTarget* target) {
    target->draw(shape);
}

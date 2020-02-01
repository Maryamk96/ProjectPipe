#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Btn 
{

public:
    Btn(float x, float y, float w, float h);
    void events(sf::Vector2f mousePos);
    virtual void render(sf::RenderTarget* target);

protected:
    const std::string resDir = "res/";
    bool isClicked = false;
    sf::RectangleShape shape;
};

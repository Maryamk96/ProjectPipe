#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "TextBtn.h"
#include "enum.h"

class MenuWindow {

public:
    explicit MenuWindow(sf::RenderWindow* window);
    ~MenuWindow();
    WindowType events(sf::Event& event);
    void render();
private:
    const std::string resDir = "res/";
    const std::string menuImg = "Menu.png";
    const std::string mainFont = "Main.ttf";
private:
    sf::RenderWindow* window;
    sf::Texture texture = sf::Texture();
    sf::Sprite sprite = sf::Sprite();
    TextBtn* playBtn;
    TextBtn* exitBtn;
    TextBtn* aboutBtn;
    sf::Vector2f mousePos;
private:
    void btnEvents(sf::Event& event);
    void updateMousePos();
};

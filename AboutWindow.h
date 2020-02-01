#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "ImgBtn.h"
#include "enum.h"

class AboutWindow {

public:
    explicit AboutWindow(sf::RenderWindow* window);
    WindowType events();
    void render();
    void backBtnEvents();
    void updateMousePos();
private:
    const std::string resDir = "res/";
    const std::string aboutImg = "About.png";
    const std::string backImg = "Back.png";
private:
    sf::RenderWindow* window;
    sf::Texture texture = sf::Texture();
    sf::Sprite sprite = sf::Sprite();
    ImgBtn* backBtn;
    sf::Vector2f mousePos;
};

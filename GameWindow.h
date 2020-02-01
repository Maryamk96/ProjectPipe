#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "ImgBtn.h"
#include "enum.h"

class GameWindow {

public:
    explicit GameWindow(sf::RenderWindow* window);
    ~GameWindow();
    WindowType events();
    void render();
    void backBtnEvents();
    void updateMousePos();

private:
    const std::string resDir = "res/";
    const std::string gameImg = "Game.png";
    const std::string backImg = "Back.png";
    const std::string mainMusic = "Main.ogg";
private:
    sf::RenderWindow* window;
    sf::Texture texture = sf::Texture();
    sf::Sprite sprite = sf::Sprite();
    ImgBtn* backBtn;
    sf::Vector2f mousePos;
    sf::Music music;
};

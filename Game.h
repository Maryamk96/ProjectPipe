#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "MenuWindow.h"
#include "GameWindow.h"
#include "AboutWindow.h"

class Game {

public:
    Game();
    ~Game();
    void start();
    void events();
    void render();
    void renderWindows();

private:
    const std::string gameName = "Water Pipes";
    const int windowH = 800;
    const int windowW = 800;
//
    sf::RenderWindow* window;
    sf::Event event;
    WindowType currentWindow;
    MenuWindow* menuWindow;
    GameWindow* gameWindow;
    AboutWindow* aboutWindow;
};

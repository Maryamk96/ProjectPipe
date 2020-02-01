#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "MenuWindow.h"
#include "GameWindow.h"
#include "AboutWindow.h"
#include "enum.h"
#include "Pipe.h"

class Game
{
public:
    Game();
    ~Game();
    void start();
    void events();
    void render();
    void renderWindows();
   
    //**************************

    bool isValid(int row, int col);
    Pipe* customPipeAt(sf::Vector2i index, PipeType t);
    Pipe* randomPipeAt(sf::Vector2i index);
    void randomPipes();
    void removePipes();
    void randomizePipes();
    sf::Vector2i upIndexOf(sf::Vector2i index);
    sf::Vector2i rightIndexOf(sf::Vector2i index);
    sf::Vector2i downIndexOf(sf::Vector2i index);
    sf::Vector2i leftIndexOf(sf::Vector2i index);
    Pipe* upPipeOf(Pipe* pipe);
    Pipe* rightPipeOf(Pipe* pipe);
    Pipe* downPipeOf(Pipe* pipe);
    Pipe* leftPipeOf(Pipe* pipe);
    void updateConnectionsOf(Pipe* pipe);
    bool isConnectedFromDirection(Direction d, Pipe* p1, Pipe* p2);
    void changePlace(Pipe* p1, Pipe* p2);
    bool moveWaterToEnd(); // if player wins returns true
    bool recursiveMove(Pipe* p, Direction from);

    //*******************************
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

    //******************************
    int score;
    Pipe* first;
    Pipe* second;
    Pipe* pipes[5][5];
};

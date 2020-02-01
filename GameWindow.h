#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "ImgBtn.h"
#include "enum.h"
#include "Pipe.h"

class GameWindow {

public:
    explicit GameWindow(sf::RenderWindow* window);
    ~GameWindow();
    WindowType events(sf::Event& event);
    void render();
    void backBtnEvents(sf::Event& event);
    void updateMousePos();
    void initPipeBtns();
    void eventsPipeBtns(sf::Event& event);
    void renderPipeBtns();
    //
    bool isValid(int row, int col);
    Pipe* customPipeAt(sf::Vector2i index, PipeType t);
    Pipe* randomPipeAt(sf::Vector2i index);
    void randomPipes();
    void removePipes();
    void randomizePipes();
    Pipe* upPipeOf(Pipe* pipe);
    Pipe* rightPipeOf(Pipe* pipe);
    Pipe* downPipeOf(Pipe* pipe);
    Pipe* leftPipeOf(Pipe* pipe);
    void updateConnectionsOf(Pipe* pipe);
    bool isConnectedFromDirection(Direction d, Pipe* p1, Pipe* p2);
    void changePlace(Pipe* p1, Pipe* p2);
    bool recursiveMove(Pipe* p, Direction from);
    bool moveWaterToEnd(); // if player wins returns true

private:
    const std::string resDir = "res/";
    const std::string gameImg = "Game.png";
    const std::string backImg = "Back.png";
    const std::string mainMusic = "Main.ogg";
//
    sf::RenderWindow* window;
    sf::Texture texture = sf::Texture();
    sf::Sprite sprite = sf::Sprite();
    ImgBtn* backBtn;
    sf::Vector2f mousePos;
    sf::Music music;
    ImgBtn* pipeBtns[5][5] = { {nullptr} };
//
    int score;
    Pipe* first;
    Pipe* second;
    Pipe* pipes[5][5] = { {nullptr} };

};

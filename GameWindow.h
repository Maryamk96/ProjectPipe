#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "ImgBtn.h"
#include "enum.h"
#include "Pipe.h"
#include "TextBtn.h"

class GameWindow {

public:
    explicit GameWindow(sf::RenderWindow* window);
    ~GameWindow();
    WindowType events();
    void render();
    WindowType btnEvents();
    void updateMousePos();
    void setupPipeBtns();
    void eventsPipeBtns();
    void renderPipeBtns();
    void renderScoreText();
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
    void rotatePipe(Pipe* p);
    PipeType pipeTypeFromChars(char chars[10]);
    bool saveGame();
    void randomizeGame();
    bool loadGame();

private:
    const std::string resDir = "res/";
    const std::string gameImg = "Game.png";
    const std::string backImg = "Back.png";
    const std::string mainFont = "Main.ttf";
    const std::string mainMusic = "Main.ogg";
//
    sf::RenderWindow* window;
    sf::Texture texture;
    sf::Sprite sprite;
    ImgBtn* backBtn;
    sf::Vector2f mousePos;
    sf::Music music;
    TextBtn* scoreText;
    TextBtn* saveBtn;
    TextBtn* randomizeBtn;
    TextBtn* loadBtn;
    ImgBtn* pipeBtns[5][5] = { {nullptr} };

//
    int score = 0;
    bool hasWon = false;
    Pipe* pipes[5][5] = { {nullptr} };

};

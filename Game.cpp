#include "Game.h"

Game::Game()
{
    window = new sf::RenderWindow(sf::VideoMode(windowW, windowH), gameName);
    event = sf::Event();
    currentWindow = MENU_WINDOW;
    menuWindow = new MenuWindow(window);
    gameWindow = new GameWindow(window);
    aboutWindow = new AboutWindow(window);
}

Game::~Game() 
{
    delete menuWindow;
    delete gameWindow;
    delete aboutWindow;
    delete window;
}

void Game::start() {
    while (window->isOpen())
    {
        events();
        render();
    }
}

void Game::events() {
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window->close();
    }
    WindowType win;
    switch (currentWindow) {
    case MENU_WINDOW:
        win = menuWindow->events();
        break;
    case GAME_WINDOW:
        win = gameWindow->events();
        break;
    case ABOUT_WINDOW:
        win = aboutWindow->events();
        break;
    default:
        win = CURRENT_WINDOW;
        break;
    }
    if (win != CURRENT_WINDOW) currentWindow = win;
}

void Game::render() {
    window->clear();
    ///
    renderWindows();
    ///
    window->display();
}

void Game::renderWindows()
{
    switch (currentWindow)
    {
    case MENU_WINDOW:
        menuWindow->render();
        break;
    case GAME_WINDOW:
        gameWindow->render();
        break;
    case ABOUT_WINDOW:
        aboutWindow->render();
        break;
    case CLOSE_WINDOW:
        window->close();
        break;
    default:
        break;
    }
}

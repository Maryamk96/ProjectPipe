#include "GameWindow.h"

GameWindow::GameWindow(sf::RenderWindow* window) : window(window) {
    texture.loadFromFile(resDir + gameImg);
    sprite.setTexture(texture);
    backBtn = new ImgBtn(10, 10, 75, 75, backImg);
    music.openFromFile(resDir + mainMusic);
    music.setLoop(true);
    music.play();
}

GameWindow::~GameWindow() {
    delete backBtn;
}

void GameWindow::backBtnEvents() {
    backBtn->events(mousePos);
}

WindowType GameWindow::events() {
    updateMousePos();
    backBtnEvents();
    if (backBtn->isClicked) return MENU_WINDOW;
    else return CURRENT_WINDOW;
}

void GameWindow::render() {
    window->draw(sprite);
    backBtn->render(window);
}

void GameWindow::updateMousePos() {
    mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

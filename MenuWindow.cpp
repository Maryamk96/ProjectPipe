#include "MenuWindow.h"

MenuWindow::MenuWindow(sf::RenderWindow* window) : window(window) {
    int d = 150;
    int x = (window->getSize().x - TextBtn::textW) / 2;
    int y = (window->getSize().y - TextBtn::textH) / 2 - d;
    playBtn = new TextBtn(x, y, sf::Color(0xF02219FF), "Play", mainFont);
    exitBtn = new TextBtn(x, y + d, sf::Color(0x1B11E9FF), "Exit", mainFont);
    aboutBtn = new TextBtn(x, y + d * 2, sf::Color(0x1B11E9FF), "About", mainFont);
    texture.loadFromFile(resDir + menuImg);
    sprite.setTexture(texture);
}

MenuWindow::~MenuWindow() {
    delete playBtn;
    delete exitBtn;
    delete aboutBtn;
}

void MenuWindow::btnEvents(sf::Event& event) {
    playBtn->events(mousePos, event);
    exitBtn->events(mousePos, event);
    aboutBtn->events(mousePos, event);
}

WindowType MenuWindow::events(sf::Event& event) {
    updateMousePos();
    btnEvents(event);
    if (playBtn->isClicked) return GAME_WINDOW;
    else if (exitBtn->isClicked) return CLOSE_WINDOW;
    else if (aboutBtn->isClicked) return ABOUT_WINDOW;
    else return CURRENT_WINDOW;
}

void MenuWindow::render() {
    window->draw(sprite);
    playBtn->render(window);
    exitBtn->render(window);
    aboutBtn->render(window);
}

void MenuWindow::updateMousePos() {
    mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

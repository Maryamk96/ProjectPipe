#include "AboutWindow.h"

AboutWindow::AboutWindow(sf::RenderWindow* window) : window(window) {
    texture.loadFromFile(resDir + aboutImg);
    sprite.setTexture(texture);
    backBtn = new ImgBtn(10, 10, 75, 75, backImg);
}

void AboutWindow::backBtnEvents() {
    backBtn->events(mousePos);
}

WindowType AboutWindow::events() {
    updateMousePos();
    backBtnEvents();
    if (backBtn->isClicked) return MENU_WINDOW;
    else return CURRENT_WINDOW;
}

void AboutWindow::render() {
    window->draw(sprite);
    backBtn->render(window);
}

void AboutWindow::updateMousePos() {
    mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

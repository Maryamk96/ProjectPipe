#include "AboutWindow.h"

AboutWindow::AboutWindow(sf::RenderWindow* window) : window(window) 
{
    texture.loadFromFile(resDir + aboutImg);
    sprite.setTexture(texture);
    backBtn = new ImgBtn(10, 10, 75, 75, backImg);
}

void AboutWindow::backBtnEvents(sf::Event& event)
{
    backBtn->events(mousePos, event);
}

WindowType AboutWindow::events(sf::Event& event)
{
    updateMousePos();
    backBtnEvents(event);
    if (backBtn->isClicked) return MENU_WINDOW;
    else return CURRENT_WINDOW;
}

void AboutWindow::render()
{
    window->draw(sprite);
    backBtn->render(window);
}

void AboutWindow::updateMousePos()
{
    mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

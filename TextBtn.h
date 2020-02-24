#pragma once

#include "Btn.h"
#include <string>

class MenuWindow;
class GameWindow;

class TextBtn : public Btn 
{
    friend class MenuWindow;
    friend class GameWindow;

public:
    TextBtn(float x, float y, sf::Color color, std::string txt, std::string fontName, int size = 60);
    void render(sf::RenderTarget* target) override;

private:
    sf::Font font;
    sf::Text text;
};

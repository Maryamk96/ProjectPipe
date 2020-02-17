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
    static const int textW = 200;
    static const int textH = 100;
private:
    sf::Font font;
    sf::Text text;
public:
    TextBtn(float x, float y, sf::Color color, std::string txt, std::string fontName);
    void render(sf::RenderTarget* target) override;
};

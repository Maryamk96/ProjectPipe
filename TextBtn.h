#pragma once

#include "Btn.h"
#include <string>

class MenuWindow;

class TextBtn : public Btn 
{
    friend class MenuWindow;
public:
    static const int textW = 200;
    static const int textH = 100;
private:
    sf::Font font = sf::Font();
    sf::Text text = sf::Text();
public:
    TextBtn(float x, float y, sf::Color color, std::string txt, std::string fontName);
    void render(sf::RenderTarget* target) override;
};

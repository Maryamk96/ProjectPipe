#pragma once

#include "Btn.h"
#include <string>

class GameWindow;
class AboutWindow;

class ImgBtn : public Btn
{
    friend class GameWindow;
    friend class AboutWindow;

public:
    ImgBtn(float x, float y, float w, float h, std::string imgName, sf::Color color = sf::Color::Transparent);
protected:
    sf::Texture texture = sf::Texture();
};

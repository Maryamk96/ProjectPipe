#include "ImgBtn.h"

using namespace std;

ImgBtn::ImgBtn(float x, float y, float w, float h, string imgName, sf::Color color) : Btn(x, y, w, h) {
    texture.loadFromFile(resDir + imgName);
    shape.setTexture(&texture);
    if (color != sf::Color::Transparent) shape.setFillColor(color);
}

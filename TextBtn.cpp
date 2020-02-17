#include "TextBtn.h"

using namespace std;

TextBtn::TextBtn(float x, float y, sf::Color color, string txt, string fontName) : Btn(x, y, textW, textH)
{
    font.loadFromFile(resDir + fontName);
    text.setFont(font);
    text.setFillColor(color);
    text.setString(txt);
    text.setCharacterSize(60);
    text.setStyle(sf::Text::Bold);
    sf::Vector2f shapePos = shape.getPosition();
    sf::Vector2f shapeSize = shape.getSize();
    sf::FloatRect textRect = text.getGlobalBounds();
    text.setPosition(shapePos.x + shapeSize.x / 2.f - textRect.width / 2.f, shapePos.y + shapeSize.y / 2.f - textRect.height);
    shape.setFillColor(sf::Color::Transparent);
}

void TextBtn::render(sf::RenderTarget* target)
{
    Btn::render(target);
    target->draw(text);
}

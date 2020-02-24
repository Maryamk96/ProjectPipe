#include "TextBtn.h"

using namespace std;

TextBtn::TextBtn(float x, float y, sf::Color color, string txt, string fontName, int size) : Btn(x, y, 200, 100)
{
    font.loadFromFile(resDir + fontName);
    text.setFont(font);
    text.setFillColor(color);
    text.setString(txt);
    text.setCharacterSize(size);
    text.setStyle(sf::Text::Bold);
    shape.setFillColor(sf::Color::Transparent);
    sf::FloatRect textRect = text.getGlobalBounds();
    shape.setSize(sf::Vector2f(textRect.width, textRect.height));
    sf::Vector2f shapePos = shape.getPosition();
    sf::Vector2f shapeSize = shape.getSize();
    text.setPosition(shapePos.x + shapeSize.x / 2.f - textRect.width / 2.f, shapePos.y + shapeSize.y / 2.f - textRect.height);
}

void TextBtn::render(sf::RenderTarget* target)
{
    Btn::render(target);
    target->draw(text);
}

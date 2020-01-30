#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("sketchy.ttf"))
	{
		//handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setCharacterSize(80);
	menu[0].setStyle(sf::Text::Bold);
	menu[0].setPosition(sf::Vector2f((width / 2)-90, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Blue);
	menu[1].setString("Exit");
	menu[1].setCharacterSize(80);
	menu[1].setStyle(sf::Text::Bold);
	menu[1].setPosition(sf::Vector2f((width / 2)-90, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));


	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Blue);
	menu[2].setString("About");
	menu[2].setCharacterSize(80);
	menu[2].setStyle(sf::Text::Bold);
	menu[2].setPosition(sf::Vector2f((width / 2)-110, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::Moveup()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}

void Menu::Movedown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}
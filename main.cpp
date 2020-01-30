#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include "Pipe.h"
#include "Menu.h"

using namespace std;

array<array < Pipe*, 5>,5>pipewater;

void GameMenu();
void Form();
void About();



int main()
{
	GameMenu();
        return 0;
}

//menu start Program
void GameMenu()
{
	////***sf::RenderWindow window(sf::VideoMode(550,600),"Pipe water");

	sf::RenderWindow window;
	window.create(sf::VideoMode(800,800), "waterPipe",sf::Style::Close);
	window.setKeyRepeatEnabled(false);
	

	

	Menu menu(window.getSize().x, window.getSize().y);

	sf::Texture texture;
	sf::Sprite sprite;
	if (!texture.loadFromFile("3.jpg"))
	{
		cout << "Error!!! can not load image!" << endl;
	}
	sprite.setTexture(texture);
	//sf::Vector2u size = texture.getSize();
	//sprite.setTexture(texture);
	//sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setScale(sf::Vector2f(0.165, 0.245));
	while (window.isOpen())
	{
		//sf::Event e;
		sf::Event event;
		while (window.pollEvent(event))
		{
			//if (event.type == sf::Event::Closed)

			switch (event.type)
			{
			case  sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.Moveup();
					break;

				case sf::Keyboard::Down:
					menu.Movedown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetpressItem())
					{
					case 0:
						Form();
						break;
					case 1:
						window.close();
						break;
					case 2:
						About();
						break;
					}
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
			//window.close();
		//break;
		}
		window.draw(sprite);
		menu.draw(window);
		window.display();
	}

	//while (window.isOpen())
	//{
	//	window.clear();

	//	window.display();
	//}
}

void Form()
{
	

	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 800), "waterPipe",sf::Style::Close);
	window.setKeyRepeatEnabled(false);

	sf::Music music;
	if (!music.openFromFile("07 Walking on Air Crashing Waves.ogg"))
	{
		cout << "Error! can not play music" << endl;
	}
	music.play();
	sf::Texture texture;
	sf::Sprite sprite;
	if (!texture.loadFromFile("BG3.jpg"))
	{
		cout << "Error!!! can not load image!" << endl;
	}
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(0.314, 0.32));

	string st[7]("l1.jpg", );
	

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
					window.close();
					break;
			}
		}
		window.draw(sprite);
		window.display();
	}
}

void About()
{
	

	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 800), "waterPipe",sf::Style::Close);
	window.setKeyRepeatEnabled(false);


	sf::Texture texture;
	sf::Sprite sprite;
	if (!texture.loadFromFile("about.png"))
	{
		cout << "Error!!! can not load image!" << endl;
	}
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(1.03 , 1.05));

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
					window.close();
					break;
			}
		}
		window.draw(sprite);
		window.display();
	}
}
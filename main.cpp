#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include "Pipe.h"
#include "Menu.h"

//******************************************************************

using namespace std;

array<array < Pipe*, 5>,5>pipewater;

void GameMenu();
void Form();
void About();

//******************************************************************

int main()
{
	GameMenu();
        return 0;
}

//******************************************************************

//menu start Program
void GameMenu()
{
	////***sf::RenderWindow window(sf::VideoMode(550,600),"Pipe water");
	//Create a new window
	sf::RenderWindow window;
	window.create(sf::VideoMode(800,800), "waterPipe",sf::Style::Close); //size window
	window.setKeyRepeatEnabled(false);
	

	

	Menu menu(window.getSize().x, window.getSize().y);

	sf::Texture texture;
	sf::Sprite sprite;
	//select image for background
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
		//create menu
		while (window.pollEvent(event))
		{
			//if (event.type == sf::Event::Closed)

			switch (event.type)  // menu 
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
//******************************************************************
void Form()
{

	//create window game
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 800), "waterPipe", sf::Style::Close); //size window
	window.setKeyRepeatEnabled(false);
	//craete object for play music
	sf::Music music;
	//select music
	if (!music.openFromFile("07 Walking on Air Crashing Waves.ogg"))
	{
		cout << "Error! can not play music" << endl;
	}
	music.play(); //play music in form game
	sf::Texture texture;
	sf::Sprite sprite;

	//select image for background form game
	if (!texture.loadFromFile("pic1.png"))
	{
		cout << "Error!!! can not load image!" << endl;
	}
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(1, 1.04));




	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			/*switch (e.type)
			{
			case sf::Event::Closed:
					window.close();
					break;
			}*/

			if (e.type == sf::Event::Closed)
			{
				window.close();
				break;
			}
			//*******************************
			if (e.type == sf::Event::MouseButtonPressed)
			{
				if (e.mouseButton.button == sf::Mouse::Left)
				{
					if ((e.mouseButton.x >= 21 && e.mouseButton.x <= 92) && (e.mouseButton.y >= 52 && e.mouseButton.y <= 55))
					{
						window.close();
						music.pause();
					}
					else continue;
				}
			}
			window.draw(sprite);
			window.display();
		}
	}
}

//******************************************************************

//create form about
//function
void About()
{
	
	//create new form 
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 800), "waterPipe",sf::Style::Close);
	window.setKeyRepeatEnabled(false);


	sf::Texture texture;
	sf::Sprite sprite;
	//select image for background
	if (!texture.loadFromFile("about.png"))
	{
		cout << "Error!!! can not load image!" << endl;
	}
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(1.03 , 1.05)); //size pic

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

//******************************************************************
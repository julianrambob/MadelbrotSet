//Madelbrot Project by Julian Rambob and Prabhi Singh

// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <complex>
//#include "ComplexPlane.h"

using namespace sf;
using namespace std;
int main()
{
	float width = sf::VideoMode::getDesktopMode().width;
	float height = sf::VideoMode::getDesktopMode().height;
	View mainView(FloatRect(0.0f, 0.0f, width, height));
	//width = 800; height = 600;
	// Create a video mode object
	VideoMode vm(width, height);
	// Create and open a window for the game
	RenderWindow window(vm, "Madelbrot", Style::Default);

	double aspectRatio = height / width;

	//ComplexPlane complex(aspectRatio);

	VertexArray pixels(Points);
	pixels.resize(height * width);


	Font f;
	f.loadFromFile("ApeMount-WyPM9.ttf");

	Text instructions;
	instructions.setPosition(10, 10);
	instructions.setFont(f);
	instructions.setCharacterSize(24);
	instructions.setFillColor(Color::White);


	while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			//mouse click event
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{

				}
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{

				}
			}
		}

		/*****************************************
			Update the scene
		*****************************************/
		//generate points

		instructions.setString("Mandelbrot Set");


		/*
		****************************************
		Draw the scene
		****************************************
		*/
		window.setView(mainView);
		// Clear everything from the last run frame
		window.clear();
		// Draw our game scene here
		RectangleShape r{ Vector2f{ 5, 5} }; //width, height. Center uninitialized
		r.setFillColor(Color::Cyan);


		window.draw(instructions);

		// Show everything we just drew
		window.display();
	}

	return 0;
}

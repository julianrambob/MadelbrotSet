//Madelbrot Project by Julian Rambob and Prabhi Singh

// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
//#include <complex>
#include "ComplexPlane.h"

using namespace sf;
using namespace std;
int main()
{
	float width = sf::VideoMode::getDesktopMode().width;
	float height = sf::VideoMode::getDesktopMode().height;
	View mainView(FloatRect(0.0f, 0.0f, width, height));
	// Create a video mode object
	VideoMode vm(width, height);
	// Create and open a window for the game
	RenderWindow window(vm, "Mandelbrot", Style::Default);

	double aspectRatio = height / width;

	ComplexPlane complex(aspectRatio);

	VertexArray pixels(Points);
	pixels.resize(height * width);

	bool calc = true;

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
				calc = true;
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					Vector2f click = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
					complex.setCenter(click);
					complex.zoomIn();
				}
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				calc = true;
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					Vector2f click = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
					complex.setCenter(click);
					complex.zoomOut();
				}
			}

			if (event.type == sf::Event::MouseMoved)
			{
				Vector2f cursor = window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));
				complex.setMouseLocation(cursor);
			}
		}

		/*****************************************
			Update the scene
		*****************************************/


		if (calc)
		{
			for (int j = 0; j < width; j++)
			{
				for (int i = 0; i < height; i++)
				{
					pixels[j + i * width].position = { (float)j,(float)i };
					Vector2i pixelLocation(j, i);
					Vector2f viewCoord = window.mapPixelToCoords(pixelLocation, complex.getView());
					int iterations = complex.countIterations(viewCoord);
					Uint8 r, g, b;
					complex.iterationsToRGB(iterations, r, g, b);
					pixels[j + i * width].color = { r, g, b };

				}
			}
			calc = false;
		}

		complex.loadText(instructions);
		/*
		****************************************
		Draw the scene
		****************************************
		*/
		window.setView(mainView);
		// Clear everything from the last run frame
		window.clear();
		// Draw our game scene here
		window.draw(pixels);

		complex.loadText(instructions);

		window.draw(instructions);

		// Show everything we just drew
		window.display();
	}

	return 0;
}

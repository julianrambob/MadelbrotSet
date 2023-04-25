#include "ComplexPlane.h"

ComplexPlane::ComplexPlane(float aspectRatio)
{
	m_aspectRatio = aspectRatio;
	m_view.setSize(BASE_WIDTH, -BASE_HEIGHT*aspectRatio);
	m_view.setCenter(0.0, 0.0);
	m_zoomCount = 0;
}

void ComplexPlane::zoomIn()
{
	m_zoomCount++; 
}

void ComplexPlane::zoomOut()
{

}

void ComplexPlane::setCenter(Vector2f coord)
{

}

View ComplexPlane::getView()
{

}

void ComplexPlane::setMouseLocation(Vector2f coord)
{

}

void ComplexPlane::loadText(Text& text)
{

}

//UML diagram says static?
size_t ComplexPlane::counterIterations(Vector2f coord)
{

}

//UML diagram says static?
void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{

}
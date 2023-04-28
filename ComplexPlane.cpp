#include "ComplexPlane.h"
#include <complex>

using namespace std;

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
	float x = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
	float y = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);
	m_view.setSize(x, y);
}

void ComplexPlane::zoomOut()
{
	m_zoomCount--;
	float x = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
	float y = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);
	m_view.setSize(x, y);
}

void ComplexPlane::setCenter(Vector2f coord)
{
	m_view.setCenter(coord);
}

View ComplexPlane::getView()
{
	return m_view;
}

void ComplexPlane::setMouseLocation(Vector2f coord)
{
	m_mouseLocation = coord;
}

void ComplexPlane::loadText(Text& text)
{
    stringstream output;
    output << "Mandelbrot Set \n" << "Center: (" << m_view.getCenter().x << ", " << m_view.getCenter().y << ")\n"
        << "Cursor: (" << m_mouseLocation.x << ", " << m_mouseLocation.y << ")\n"
        << "Left-click to Zoom in \n" << "Right-click to Zoom out\n";
    text.setString(output.str());
}   

//UML diagram says static?
size_t ComplexPlane::countIterations(Vector2f coord)
{
    complex<float> c(coord.x, coord.y);
    complex<float> z(0, 0);
    size_t counter;

    for (int i = 0; i < MAX_ITER; i++)
    {
        counter = i + 1;
        z = z * z + c;
        if (abs(z) > 2.0)
            return counter;
    }
    return counter;
}

//UML diagram says static?
void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{

    int step = MAX_ITER/5;

    if (count == MAX_ITER   )
    {
        r = 0;
        g = 0;
        b = 0;
    }

    else if (count >= 0 && count < step) 
    {
        r = 64;
        g = 0;
        b = 255;
    }

    else if (count >= step && count < 2 * step) 
    {
        r = 0;
        g = 255;
        b = 255;
    }

    else if (count >= 2 * step && count < 3 * step) 
    {
        r = 0;
        g = 255;
        b = 64;
    }

    else if (count >= 3 * step && count < 4 * step) 
    {
        r = 255;
        g = 255;
        b = 0;
    }

    else 
    {
        r, g, b = 255, 38, 0;
    }

}
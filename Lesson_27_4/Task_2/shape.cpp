#include "shape.h"

void Coord::setCoord(void)
{
    int x, y;
    cout << "Enter the coordinates of the center of the shape: ";
    cin >> x >> y;
    this->x = x;
    this->y = y;
}

void Shape::setColor(void)
{
    int color;
    cout << "Select shape color:\n\t0 - None\n\t1 - Red\n\t2 - Green\n\t3 - Yellow" << endl;
    cin >> color;
    this->color = (Colors)color;
}

string Shape::getColor(void)
{
    return this->txtColor[(int)color];
}

void Shape::overShape(int length, int width)
{
    cout << "Length A = " << length + 1 << ", Width B = " << width + 1 << endl;
}

void Shape::displayColor(void)
{
    cout << "Color - \"" << getColor() << "\"" << endl;
}

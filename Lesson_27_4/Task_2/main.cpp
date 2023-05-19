#include <iostream>
#include <string>
#include "shape.h"
#include <cmath>

using namespace std;

class Circle : public Shape
{
    double radius;

    void setRadius(double radius)
    {
        if(radius > 0) this->radius = radius;
    }

    void createCircle(void)
    {
        setCoord();
        cout << "Enter the radius of the circle: ";
        double radius;
        cin >> radius;
        setRadius(radius);
        setColor();
    }

    void squareCircle(void)
    {
        cout << "Square S = " << (3.14 * radius * radius) << endl;
    }

public:
    Circle(){}

    void displayCircle(void)
    {
        createCircle();
        cout << "\n\n********************************" << endl;
        cout << "Radius R = " << radius << endl;
        displayColor();
        squareCircle();
        overShape(2 * radius, 2 * radius);
    }
};

class Square : public Shape
{
    double length;

    void setSide(double length)
    {
        if(length > 0) this->length = length;
    }

    void createSquare(void)
    {
        setCoord();
        cout << "Enter the side of the square: ";
        double length;
        cin >> length;
        setSide(length);
        setColor();
    }

    void squareSquare(void)
    {
        cout << "Square S = " << (length * length) << endl;
    }

public:
    Square(){}

    void displaySquare(void)
    {
        createSquare();
        cout << "\n\n********************************" << endl;
        cout << "\nLength L = " << length << endl;
        displayColor();
        squareSquare();
        overShape(length, length);
    }
};

class Triangle : public Shape
{
    double length;

    void setSide(double length)
    {
        if(length > 0) this->length = length;
    }

    void createTriangle(void)
    {
        setCoord();
        cout << "Enter the side of the triangle: ";
        double side;
        cin >> side;
        setSide(side);
        setColor();
    }

    void squareTriangle(void)
    {
        cout << "Square S = " << (length * length * sqrt(3)/4) << endl;
    }

public:
    Triangle(){}

    void displayTriangle(void)
    {
        createTriangle();
        cout << "\n\n********************************" << endl;
        cout << "\nLength L = " << length << endl;
        displayColor();
        squareTriangle();
        overShape(length, (length * sqrt(3)/2));
    }
};

class Rectangle : public Shape
{
    double length, width;

    void setSide(double length, double width)
    {
        if(length > 0 && width > 0){
            this->length = length;
            this->width = width;
        }
    }

    void createRectangle(void)
    {
        setCoord();
        cout << "Enter the side of the rectangle (length, width): ";
        double length, width;
        cin >> length >> width;
        setSide(length, width);
        setColor();
    }

    void squareRectangle(void)
    {
        cout << "Square S = " << (length * width) << endl;
    }

public:
    Rectangle(){}

    void displayRectangle(void)
    {
        createRectangle();
        cout << "\n\n********************************" << endl;
        cout << "Length l = " << length << "; Width w = " << width << endl;
        displayColor();
        squareRectangle();
        overShape(length, width);
    }
};

int main()
{
    string com_shape;
    cout << "Choose a figure: circle, square, triangle, rectangle." << endl;
    cin >> com_shape;
    if(com_shape == "circle"){
        Circle circle;
        circle.displayCircle();
    } else if(com_shape == "square"){
        Square square;
        square.displaySquare();
    } else if(com_shape == "triangle"){
        Triangle triangle;
        triangle.displayTriangle();
    } else if(com_shape == "rectangle"){
        Rectangle rectangle;
        rectangle.displayRectangle();
    }
    return 0;
}

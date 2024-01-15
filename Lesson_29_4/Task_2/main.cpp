#include <iostream>
#include <math.h>

using namespace std;

class Shape
{
private:

public:
    struct BoundingBoxDimensions
    {
        double width;
        double height;
    };

    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual string type() = 0;
};

class Circle :public Shape
{
private:
    int rad;
    double pi = 3.14;
public:
    Circle(int rad)
    {
        this->rad = rad;
    }

    virtual double square() override
    {
        return pi * rad * rad;
    }

    virtual BoundingBoxDimensions dimensions() override
    {
        BoundingBoxDimensions BoundCircle;
        BoundCircle.width = 2 * rad;
        BoundCircle.height = 2 * rad;
        return BoundCircle;
    }

    virtual string type() override
    {
        return "Circle";
    }
};

class Rectangle :public Shape
{
private:
    int a, b;

public:
    Rectangle(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    virtual double square() override
    {
        return a * b;
    }

    virtual BoundingBoxDimensions dimensions() override
    {
        BoundingBoxDimensions BoundRectangle;
        BoundRectangle.width = a;
        BoundRectangle.height = b;
        return BoundRectangle;
    }

    virtual string type() override
    {
        return "Rectangle";
    }
};

class Triangle :public Shape
{
private:
    int a, b, c;
public:
    Triangle(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    virtual double square() override
    {
        double p = (a + b + c)/2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    virtual BoundingBoxDimensions dimensions() override
    {
        BoundingBoxDimensions BoundTriangle;
        double p = (a + b + c)/2;
        double r = (a * b * c)/(4 * sqrt(p * (p - a) * (p - b) * (p - c)));
        BoundTriangle.width = 2 * r;
        BoundTriangle.height = 2 * r;
        return BoundTriangle;
    }

    virtual string type() override
    {
        return "Triangle";
    }
};

void printParams(Shape *shape)
{
   std::cout <<"Type: " << shape->type() << endl;
   std::cout <<"\tSquare: " << shape->square() << endl;
   std::cout <<"\tWidth: " << shape->dimensions().width << endl;
   std::cout <<"\tHeight: " << shape->dimensions().height << endl << endl;
}

int main()
{
    Shape* shape;
    Triangle t(5, 5, 6);
    Rectangle r(4, 7);
    Circle c(5);

    printParams(&t);
    printParams(&r);
    printParams(&c);

    return 0;
}

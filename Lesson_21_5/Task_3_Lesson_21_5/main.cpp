#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Vect{
    double x = 0;
    double y = 0;
};

void adding(void);
void subtracting(void);
void vectScale(void);
void lengthing(void);
void normalizing(void);

int main()
{
    cout << "Task 3. Implementation of the mathematical vector." << endl;
    string command;
    cout << "Input command: add/subtract/scale/length/normalize: ";
    cin >> command;
    if(command == "add"){
        adding();
    } else if(command == "subtract"){
        subtracting();
    } else if(command == "scale"){
        vectScale();
    } else if(command == "length"){
        lengthing();
    } else if(command == "normalize"){
        normalizing();
    }
    return 0;
}

void adding(void)
{
    cout << "Input coordinates \"X\" and \"Y\" for vector 1: ";
    Vect a;
    cin >> a.x >> a.y;
    cout << "Input coordinates \"X\" and \"Y\" for vector 1: ";
    Vect b;
    cin >> b.x >> b.y;
    Vect c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    cout << "c{" << c.x << "; " << c.y << "}\n";
}

void subtracting(void)
{
    cout << "Input coordinates \"X\" and \"Y\" for vector 1: ";
    Vect a;
    cin >> a.x >> a.y;
    cout << "Input coordinates \"X\" and \"Y\" for vector 1: ";
    Vect b;
    cin >> b.x >> b.y;
    Vect c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    cout << "c{" << c.x << "; " << c.y << "}\n";
}

void vectScale(void)
{
    cout << "Input coordinates \"X\" and \"Y\" for vector 1: ";
    Vect a;
    cin >> a.x >> a.y;
    cout << "Input scalar number: ";
    double b;
    cin >> b;
    Vect c;
    c.x = a.x * b;
    c.y = a.y * b;
    cout << "c{" << c.x << "; " << c.y << "}\n";
}

void lengthing(void)
{
    cout << "Input coordinates \"X\" and \"Y\" for vector 1: ";
    Vect a;
    cin >> a.x >> a.y;
    double len = sqrt(pow(a.x, 2) + pow(a.y, 2));
    cout << "Length for vector = " << len << endl;
}

void normalizing(void)
{
    cout << "Input coordinates \"X\" and \"Y\" for vector 1: ";
    Vect a;
    cin >> a.x >> a.y;
    double len = sqrt(pow(a.x, 2) + pow(a.y, 2));
    a.x /= len;
    a.y /= len;
    cout << "Normal vector = a{" << a.x << "; " << a.y << "}\n";
}

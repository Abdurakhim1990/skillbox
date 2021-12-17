#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Vect{
    double x = 0;
    double y = 0;
};

Vect adding(Vect a, Vect b);
Vect subtracting(Vect a, Vect b);
Vect vectScale(Vect a, double b);
double lengthing(Vect a);
Vect normalizing(Vect a);

int main()
{
    Vect a, b, c;
    cout << "Task 3. Implementation of the mathematical vector." << endl;
    string command;
    cout << "Input command: add/subtract/scale/length/normalize: ";
    cin >> command;
    cout << "Input coordinates \"X\" and \"Y\" for vector a: ";
    cin >> a.x >> a.y;
    if(command == "length"){
        cout << "Length for vector = " << lengthing(a) << endl;
    } else{
        if(command == "add"){
            cout << "Input coordinates \"X\" and \"Y\" for vector b: ";
            cin >> b.x >> b.y;
            c = adding(a, b);
        } else if(command == "subtract"){
            cout << "Input coordinates \"X\" and \"Y\" for vector b: ";
            cin >> b.x >> b.y;
            c = subtracting(a, b);
        } else if(command == "scale"){
            cout << "Input scalar number: ";
            double b;
            cin >> b;
            c = vectScale(a, b);
        } else if(command == "normalize"){
            c = normalizing(a);
        }
        cout << "c{" << c.x << "; " << c.y << "}\n";
    }
    return 0;
}

Vect adding(Vect a, Vect b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vect subtracting(Vect a, Vect b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

Vect vectScale(Vect a, double b)
{
    a.x = a.x * b;
    a.y = a.y * b;
    return a;
}

double lengthing(Vect a)
{
    double len = sqrt(pow(a.x, 2) + pow(a.y, 2));
    return len;
}

Vect normalizing(Vect a)
{
    double len = sqrt(pow(a.x, 2) + pow(a.y, 2));
    a.x /= len;
    a.y /= len;
    return a;
}

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;


enum class Colors{
    NONE,
    RED,
    GREEN,
    YELLOW
};

class Coord
{
    int x = 0;
    int y = 0;

public:
    Coord (){}
    void setCoord(void);
};


class Shape : public Coord
{
private:
    vector<string> txtColor = {"NONE", "RED", "GREEN", "YELLOW"};
    Colors color;

public:
    Shape(){}
    void setColor(void);
    string getColor(void);
    void overShape(int length, int width);
    void displayColor(void);
};

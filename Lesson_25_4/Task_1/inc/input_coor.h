#pragma once
#include <iostream>

using namespace std;

struct Input{
    double x = 0;
    double y = 0;
};

struct Line{
    Input Start;
    Input End;
};

void inputCoord(Input& Coord);

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "monitor.h"

using namespace std;

class Window
{
private:
    vector <int> v_coord = {1, 1};
    vector <int> v_length_width = {4, 4};

    bool setCoord(vector<int> v_c);
    bool setSize(vector<int> l_w);
    vector <int> getCoordWindow();
    vector <int> getSizeWindow();

public:
    void Move();
    void Resize();
    static void controlMonitor();
};

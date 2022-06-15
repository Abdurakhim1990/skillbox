#pragma once

#include <iostream>
#include <vector>
#include "window.h"

using namespace std;

class Monitor
{
    vector <vector<int>> vec_monitor;

    void initMonitor();
    void outMonitor();
    void openWindow(vector <int> vec_win_coor, vector <int> vec_win_size);

public:
    static void display(vector <int> vec_win_coor, vector <int> vec_win_size);
};

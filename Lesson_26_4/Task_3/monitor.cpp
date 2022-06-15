#include "monitor.h"

void Monitor::display(vector <int> vec_win_coor, vector <int> vec_win_size)
{
    Monitor *monitor = new Monitor();
    monitor->initMonitor();
    monitor->openWindow(vec_win_coor, vec_win_size);
    monitor->outMonitor();
    delete monitor;
}

void Monitor::initMonitor()
{
    vector <vector <int>> vec(80);
    for(int i = 0; i < 80; ++i)
    {
        vec[i].resize(50);
        for(int j = 0; j < 50; ++j)
        {
            vec[i][j] = 0;
        }
    }
    vec_monitor = vec;
}

void Monitor::openWindow(vector <int> vec_win_coor, vector <int> vec_win_size)
{
    for(int i = vec_win_coor[0]; i < 80 && i < vec_win_coor[0] + vec_win_size[0]; ++i)
    {
        for(int j = vec_win_coor[1]; j < 50 && j < vec_win_coor[1] + vec_win_size[1]; ++j)
        {
            vec_monitor[i][j] = 1;
        }
    }
}

void Monitor::outMonitor()
{
    for(int i = 0; i < 50; ++i)
    {
        for(int j = 0; j < 80; ++j)
        {
            cout << vec_monitor[j][i] << " ";
        }
        cout << endl;
    }
}

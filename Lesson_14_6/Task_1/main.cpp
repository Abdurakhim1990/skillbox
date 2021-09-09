#include <iostream>

using namespace std;

int main()
{
    cout << "Task 1. Banquet table." << endl;
    int appliances[12][4] = {{1, 1, 1, 1},
                            {1, 1, 1, 1},
                            {1, 1, 1, 0},
                            {1, 1, 1, 0},
                            {1, 1, 1, 0},
                            {1, 1, 1, 0},
                            {1, 1, 1, 0},
                            {1, 1, 1, 0},
                            {1, 1, 1, 0},
                            {1, 1, 1, 0},
                            {1, 1, 1, 0},
                            {1, 1, 1, 0}};
    int tableware[12][3] = {{1, 1, 1},
                           {1, 1, 1},
                           {1, 1, 0},
                           {1, 1, 0},
                           {1, 1, 0},
                           {1, 1, 0},
                           {1, 1, 0},
                           {1, 1, 0},
                           {1, 1, 0},
                           {1, 1, 0},
                           {1, 1, 0},
                           {1, 1, 0}};
    int chair[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    chair[8]++;
    appliances[5][1]--;
    appliances[5][1] = appliances[0][1];
    appliances[0][1]--;
    tableware[0][2]--;
    return 0;
}

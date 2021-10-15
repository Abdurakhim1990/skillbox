#include <iostream>
#include <cstdio>

using namespace std;

bool CompareNull(double value)
{
    return value < 0.01;
}

int main()
{
    double speed = 0;
    double dspeed;
    char text[25];
    cout << "Task 1. Speedometer.\n";
    bool start = false;
    do{
        cout << "Enter speed difference: ";
        cin >> dspeed;
        speed += dspeed;
        if(speed > 150.0){
            speed = 150;
        } else if(CompareNull(speed)){
            speed = 0;
        }
        start = speed != 0 || (start && speed == 0);
        sprintf(text, "Vehicle speed %.1f km/h.", speed);
        cout << text << endl;
    } while(speed > 0 || !start);
    return 0;
}

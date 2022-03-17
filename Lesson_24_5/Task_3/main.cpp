#include <iostream>
#include <ctime>
#include <iomanip>


using namespace std;

int main()
{
    tm time_timer;
    cout << "Input time for timer (MM:SS)" << endl;
    cin >> get_time(&time_timer, "%M:%S");
    time_t t = time(nullptr);
    tm end_time = *localtime(&t);
    end_time.tm_min += time_timer.tm_min;
    end_time.tm_sec += time_timer.tm_sec;
    cout << "Time left " << time_timer.tm_min << " min " << time_timer.tm_sec << "sec.\n";
    tm current_time = *localtime(&t);
    time_t prev_t = t;
    while(end_time.tm_min > current_time.tm_min || (end_time.tm_min == current_time.tm_min && end_time.tm_sec > current_time.tm_sec)){
        if(difftime(t, prev_t) >= 1){
            prev_t = t;
            if(time_timer.tm_sec){
                --time_timer.tm_sec;
            } else{
                time_timer.tm_sec = 59;
                --time_timer.tm_min;
            }
            system("cls");
            cout << "Time left " << time_timer.tm_min << " min " << time_timer.tm_sec << "sec.\n";
        }
        t = time(nullptr);
        current_time = *localtime(&t);
    }
    cout << "DING! DING! DING!" << endl;
    return 0;
}

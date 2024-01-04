#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <vector>

using namespace std;

mutex station_access;

void train_travel_time(string name_train, int time)
{
    this_thread::sleep_for(chrono::seconds(time));
    station_access.lock();
    cout << name_train << " arrived!" << endl;
    string command;
    do{
        cout << "Input command \"depart\" for departure " << endl;
        cin >> command;
    } while (command != "depart");
    station_access.unlock();
}

int main()
{
    vector<int> travels_time;
    int time;
    cout << "Input the arrival time of train A" << endl;
    cin >> time;
    travels_time.push_back(time);
    cout << "Input the arrival time of train B" << endl;
    cin >> time;
    travels_time.push_back(time);
    cout << "Input the arrival time of train C" << endl;
    cin >> time;
    travels_time.push_back(time);

    thread train_a(train_travel_time, "TRAIN A", travels_time[0]);
    thread train_b(train_travel_time, "TRAIN B", travels_time[1]);
    thread train_c(train_travel_time, "TRAIN C", travels_time[2]);

    train_a.join();
    train_b.join();
    train_c.join();
    return 0;
}

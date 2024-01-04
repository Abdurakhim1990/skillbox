#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <map>
#include <vector>

using namespace std;

mutex cout_access;
multimap<int, string> finish;
int real_time = 0;

void swimmers_race(string name, int speed)
{
    int distance = 0, time = 0;
    while(distance < 100){
        this_thread::sleep_for(chrono::seconds(1));
        distance += speed;
        if(distance >= 100){
            distance = 100;
        }
        ++time;
        cout_access.lock();
        if(real_time != time){
            real_time = time;
            cout << "\nTime: " << time << " seconds" << endl;
        }
        cout << "Swimmer \"" << name << "\" - distance: " << distance << " meters." << endl;
        cout_access.unlock();
    }
    finish.insert(pair<int, string> (time, name));
}

int main()
{
    map<string, int> swimmers;
    string name;
    int speed;

    for(int i = 0; i < 6; ++i){
        cout << "Input swimmer's name " << endl;
        cin >> name;
        cout << "Input swimmer's speed " << endl;
        cin >> speed;
        swimmers.insert(pair<string, int> (name, speed));
    }
    auto it_swimmer = swimmers.begin();
    thread swimmer1(swimmers_race, it_swimmer->first, it_swimmer->second);
    ++it_swimmer;
    thread swimmer2(swimmers_race, it_swimmer->first, it_swimmer->second);
    ++it_swimmer;
    thread swimmer3(swimmers_race, it_swimmer->first, it_swimmer->second);
    ++it_swimmer;
    thread swimmer4(swimmers_race, it_swimmer->first, it_swimmer->second);
    ++it_swimmer;
    thread swimmer5(swimmers_race, it_swimmer->first, it_swimmer->second);
    ++it_swimmer;
    thread swimmer6(swimmers_race, it_swimmer->first, it_swimmer->second);
    int time = 0;
    while(finish.size() != 6){
    }
    cout_access.lock();
    cout << "\nFinished swimmers" << endl;
    int number = 1;
    for(auto it_finish = finish.begin(); it_finish != end(finish); ++it_finish, ++number){
        cout << number << ". \"" << it_finish->second <<  " - "<< it_finish->first << " seconds" << endl;
    }
    cout_access.unlock();
    swimmer1.join();
    swimmer2.join();
    swimmer3.join();
    swimmer4.join();
    swimmer5.join();
    swimmer6.join();
    return 0;
}

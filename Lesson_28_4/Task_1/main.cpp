#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

mutex cout_access;
mutex result_access;
vector<pair<string, int>> result;
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
    result_access.lock();
    result.push_back(pair<string, int>(name, time));
    result_access.unlock();
}

int main()
{
    vector<pair<string, int>> swim;
    string name;
    int speed;

    for(int i = 0; i < 6; ++i){
        cout << "Input swimmer's name " << endl;
        cin >> name;
        cout << "Input swimmer's speed " << endl;
        cin >> speed;
        swim.push_back(pair<string, int>(name, speed));
    }

    vector<thread> swimmer;
    for(int i = 0; i < swim.size(); ++i){
        swimmer.push_back(thread(swimmers_race, swim[i].first, swim[i].second));
    }

    for(thread& t : swimmer){
        t.join();
    }

    cout << "\nFinished swimmers" << endl;
    int number = 1;
    for(auto& v : swim){
        cout << number << ". \"" << v.second <<  " - "<< v.first << " seconds" << endl;
        ++number;
    }
    return 0;
}

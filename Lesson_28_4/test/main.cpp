#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

vector<string> history;
mutex history_access;

void wait_for_car(int time, string name)
{
    this_thread::sleep_for(chrono::seconds(time));
    cout << "Id: " << this_thread::get_id() << endl;
    cout << "RING (" << name << ")" << endl;
    history_access.lock();
    history.push_back(name);
    history_access.unlock();
}

int main()
{
    std::cout << "2³ 2² 2¹ 2⁰ \n";
    int time;
    cin >> time;
    string name;
    cin >> name;
    cout << "Id: " << this_thread::get_id() << endl;
    thread call(wait_for_car, time, name);
    thread call2(wait_for_car, 4, "SKILLBOX");
    call.detach();
    call2.detach();
    this_thread::sleep_for(chrono::seconds(5));
    if(call.joinable())call.join();
    if(call2.joinable())call2.join();

    history_access.lock();
    cout << "Missed calls" << endl;
    for(int i = 0; i < history.size(); ++i){
        cout << history[i] << endl;
    }
    history_access.unlock();
    return 0;
}

//void wait_for_car(int time, string name)
//{
//    this_thread::sleep_for(chrono::seconds(time));
//    cout << "Id: " << this_thread::get_id() << endl;
//    cout << "RING (" << name << ")" << endl;
//}

//int main()
//{
//    int time;
//    cin >> time;
//    string name;
//    cin >> name;
//    cout << "Id: " << this_thread::get_id() << endl;
//    thread call(wait_for_car, time, name);
//    thread call2(wait_for_car, 4, "SKILLBOX");
//    call.detach();
//    call2.detach();
//    this_thread::sleep_for(chrono::seconds(5));
//    cout << "RING (FRIEND)" << endl;

//    if(call.joinable())call.join();
//    if(call2.joinable())call2.join();
//    return 0;
//}

//thread call2(wait_for_car, 4, "SKILLBOX");
//this_thread::sleep_for(chrono::seconds(5));
//cout << "RING (FRIEND)" << endl;

//call.join();
//call2.join();
//return 0;

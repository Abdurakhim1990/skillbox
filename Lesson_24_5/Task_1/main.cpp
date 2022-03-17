#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main()
{
    string com;
    time_t time_start;
    time_t time_stop;
    string name_task = "";
    double time_task;
    bool task_start = false;
    map<string, double> taskMap;

    do{
        cout << "Input command" << endl;
        cin >> com;
        if(com == "begin"){
            if(task_start == true){
                time_stop = time(nullptr);
                time_task = difftime(time_stop, time_start);
                time_task /= 3600;
                taskMap.insert(pair<string, double> (name_task, time_task));
                task_start = false;
            }
            cout << "Input Name task" << endl;
            time_start = time(nullptr);
            cin >> name_task;
            task_start = true;
        } else if(com == "end"){
            if(task_start == true){
                time_stop = time(nullptr);
                time_task = difftime(time_stop, time_start);
                time_task /= 3600;
                taskMap.insert(pair<string, double> (name_task, time_task));
                task_start = false;
            }
        } else if(com == "status"){
            cout << "Closes tasks:" << endl;
            for(map<string, double>::iterator it = taskMap.begin();
                it != taskMap.end(); ++it){
                cout << "\t-" << it->first << " - " << it->second << endl;
            }
            if(task_start == true){
                cout << "Current task:" << endl;
                cout << "\t-" << name_task << endl;
            }
        }
    } while(com != "exit");

    return 0;
}

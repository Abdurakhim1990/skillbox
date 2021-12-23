#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    cout << "Task 2. Reception" << endl;
    map<string, int> queue;
    string com;
    do{
        cout << "Input <Next> or Last name: ";
        cin >> com;
        if(com == "Next"){
            map<string, int>::iterator it = queue.begin();
            if(it != queue.end()){
                string str = it->first;
                cout << str << endl;
                int count = it->second;
                queue.erase(it);
                if(--count > 0){
                    queue.insert(pair<string, int> (str, count));
                }
            }
        } else{
            map<string, int>::iterator it = queue.find(com);
            if(it != queue.end()){
                int count = it->second;
                queue.erase(it);
                ++count;
                queue.insert(pair<string, int> (com, count));
            } else{
                queue.insert(pair<string, int> (com, 1));
            }
        }
    } while (queue.begin() != queue.end());


    return 0;
}

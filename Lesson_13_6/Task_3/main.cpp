#include <iostream>
#include <vector>

using namespace std;

vector<int> ShiftVector(vector<int> vec)
{
    for(int i = 0; i < vec.size() - 1; i++){
        vec[i] = vec[i + 1];
    }
    vec.pop_back();
    return vec;
}

int main()
{
    cout << "Task_3" << endl;
    vector<int> database;
    int in;
    cin >> in;
    while(in != -1){
        if(database.size() == 20){
            database = ShiftVector(database);
        }
        database.push_back(in);
        cin >> in;
    }
    cout << "Database list: ";
    for(int i = 0; i < database.size(); i++){
        cout << database[i] << " ";
    }
    return 0;
}

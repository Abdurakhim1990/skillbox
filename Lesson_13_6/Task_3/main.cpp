#include <iostream>
#include <vector>

using namespace std;

vector<int> ShiftVector(vector<int> vec)
{
    for(int i = 0; i < vec.size() - 1; i++){
        vec[i] = vec[i + 1];
    }
    return vec;
}

int main()
{
    cout << "Task_3" << endl;
    vector<int> database(20);
    int in;
    cin >> in;
    int count = 0;
    bool overflow = false;
    while(in != -1){
        database[count] = in;
        count++;
        if(count == 20){
            count = 0;
            overflow = true;
        }
        cin >> in;
    }
    cout << "Database list: ";
    if(overflow){
        for(int i = 0; i < 20; i++){
            cout << database[(i + count) % 20] << " ";

        }
    } else{
        for(int i = 0; i < count; i++){
            cout << database[i] << " ";
        }
    }


    return 0;
}

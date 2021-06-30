#include <iostream>
#include <vector>

using namespace std;

vector<int> addVec(vector<int> vec, int val, int pos)
{
    vector<int> newVec(vec.size() + 1);
    if(pos > vec.size()){
        for(int i = 0; i < vec.size(); i++){
            newVec[i] = vec[i];
        }
        newVec[vec.size()] = val;
    } else{
        for(int i = 0; i < newVec.size(); i++){
            if(i < (pos - 1)){
                newVec[i] = vec[i];
            } else if(i >= pos){
                newVec[i] = vec[i-1];
            } else{
                newVec[i] = val;
            }
        }
    }
    return newVec;
}

int main()
{
    vector<int> vec = {10, 65, 98, 75, 12, 35, 54, 95, 55, 33};
    int value = 0;
    int turn = 0;
    while(turn >= 0){
        cout << "Input value: ";
        cin >> value;
        cout << "Input turn: ";
        cin >> turn;
        vec = addVec(vec, value, turn);
    }
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    return 0;
}

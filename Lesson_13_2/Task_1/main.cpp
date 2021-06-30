#include <iostream>
#include <vector>

using namespace std;

vector<int> vectorAdd(vector<int> vec, int val)
{
    vector<int> newVec(vec.size() + 1);

    for(int i = 0; i < vec.size(); i++){
        newVec[i] = vec[i];
    }
    newVec[vec.size()] = val;
    return newVec;
}

int main()
{
    int n = 0;
    vector<int> vec(0);
    while(n != -1){
        cout << "Input ID for robot: ";
        cin >> n;
        vec = vectorAdd(vec, n);
    }

    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }

    return 0;
}

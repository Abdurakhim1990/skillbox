#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Task 4" << endl;
    //vector<int> vec = {-100,-50, -5, 1, 10, 15};
    //vector<int> vec = {-100,-50, -40, -25, -15, -5, 0};
    vector<int> vec = {-1, 2, 10, 35, 51, 110, 150};
    vector<int> mass(vec.size());
    int start = 0, end = vec.size() - 1;
    for(int i = vec.size() - 1; i >= 0; i--){
        if(abs(vec[start]) > abs(vec[end])) {
            mass[i] = vec[start];
            start++;
        } else{
            mass[i] = vec[end];
            end--;
        }
    }
    for(int i = 0; i < vec.size(); i++){
        cout << mass[i] << " ";
    }
    return 0;
}

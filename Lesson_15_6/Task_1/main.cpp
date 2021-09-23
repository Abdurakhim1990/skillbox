#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Task 1" << endl;
    vector<int> mass = {-2, 1, -3, 4, -1, 2, 1, -5, 4, -2, 0, 3, -1, 4, 6};
    //vector<int> mass = {-2,1,-3,4,-1,2,1,-5,4};
    int max = mass[0] + mass[1];
    int ind_i = 0, ind_j = 1;
    int sum = 0;
    for(int i = 0; i < mass.size(); i++){
        sum += mass[i];
        if(sum > max){
            max = sum;
            ind_j = i;
        }
    }
    for(int i = 0; i < ind_j; i++){
        sum -= mass[i];
        if(sum > max){
            max = sum;
            ind_i = i + 1;
        }
    }
    cout << "From " << ind_i << " to " << ind_j << endl;
    return 0;
}

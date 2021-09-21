#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Task 1" << endl;
    vector<int> mass = {-2, 1, -3, 4, -1, 2, 1, -5, 4, -2, 0, 3, -1, 4, 6};
    int max = mass[0] + mass[1];
    int ind_i = 0, ind_j = 1;
    for(int i = 0; i < mass.size() - 1; i++){
        int sum = mass[i];
        for(int j = i + 1; j < mass.size(); j++){
            sum += mass[j];
            if(sum > max){
                max = sum;
                ind_i = i;
                ind_j = j;
            }
        }
    }
    cout << "From " << ind_i << " to " << ind_j << endl;
    return 0;
}

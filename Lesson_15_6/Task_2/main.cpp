#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Task 2" << endl;
    vector<int> mass = {2, 7, 11, 15};
    int res;
    cout << "Input result: ";
    cin >> res;
    for(int i = 0; i < mass.size() - 1; i++){
        for(int j = i + 1; j < mass.size(); j++){
            if(res == mass[i] + mass[j]){
                cout << mass[i] << " and " << mass[j] << endl;
                return 0;
            }
        }
    }
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Task 3" << endl;
    vector<int> vec;
    int num;
    while (1) {
        cout << "Input number" << endl;
        cin >> num;
        if(num == -1){
            cout << vec[4] << endl;
        } else if(num == -2){
            return 0;
        } else{
            vec.push_back(num);
            for(int i = vec.size() - 1; i > 0; i--){
                if(vec[i] < vec[i - 1]){
                    int tmp = vec[i];
                    vec[i] = vec[i - 1];
                    vec[i - 1] = tmp;
                } else {
                    break;
                }
            }
        }
    }
    return 0;
}

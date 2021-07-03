#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    vector<int> vec;
    while(n != -1){
        cout << "Input number: ";
        cin >> n;
        while (vec.size() != 0 && vec[vec.size() - 1] < n) {
            vec.pop_back();
        }
        vec.push_back(n);
    }
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }

    return 0;
}

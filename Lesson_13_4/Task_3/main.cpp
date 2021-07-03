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
        vec.push_back(n);
        if(vec.size() == vec.capacity() - 2){
            for(int i = 0; i < vec.size(); i++){
                cout << vec[i] << " ";
            }
            cout << "Size = " << vec.size() << " Capacity = " << vec.capacity() << endl;
        }
    }
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }

    return 0;
}

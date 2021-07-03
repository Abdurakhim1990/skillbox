#include <iostream>
#include <vector>

using namespace std;

vector<int> OutVec(vector<int> vec, int index)
{
    for(int i = index; i < vec.size() - 1; i++){
        vec[i] = vec[i + 1];
    }
    vec.resize(vec.size() - 1);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    return vec;
}


int main()
{
    int K, n, m;
    vector<int> vec = {50, 65, 150, 700};
    int real_size = 0;
    while(1){
        real_size = vec.size();
        cout << "Input counter: ";
        cin >> K;
        vec.resize(vec.size() + K);
        for(int i = real_size; i < vec.size(); i++){
            cout << "Input 1n = ";
            cin >> n;
            vec[i] = n;
        }
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < K; i++){
            cout << "input index: ";
            cin >> m;
            vec = OutVec(vec, m);
        }
    }
    return 0;
}

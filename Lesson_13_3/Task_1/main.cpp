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
    int n;
    int m;
    vector<int> vec;
    cout << "input count: ";
    cin >> n;
    vec.resize(vec.size() + n);
    for(int i = 0; i < vec.size(); i++){
        cout << "input number: ";
        cin >> vec[i];
    }
    while(vec.size() > 0){
        cout << "input index: ";
        cin >> m;
        vec = OutVec(vec, m);
    }
    return 0;
}

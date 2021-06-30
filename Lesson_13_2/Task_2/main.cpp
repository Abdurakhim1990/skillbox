#include <iostream>
#include <vector>

using namespace std;

vector<int> addVec(vector<int> vec, int val)
{
    vec.resize(vec.size() + 1);
    vec[vec.size()-1] = val;
    return vec;
}

int main()
{
    vector<int> vec;
    int n = 0;
    int summ = 0;
    while (n != -1){
        cout << "Input number: ";
        cin >> n;
        vec = addVec(vec, n);
        if(n != -1)
            summ += n;
    }
    cout << (summ / (vec.size() - 1));
    return 0;
}

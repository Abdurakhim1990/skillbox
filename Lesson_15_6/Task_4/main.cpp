#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Task 4" << endl;
    vector<int> vec = {-91, -56, -25, -9, -1, 2, 10, 35, 51, 110, 150};
    vector<int> mass(vec.size());
    int start = 0;
    for(; start < vec.size() && vec[start] < 0; start++){}
    int end = start--;
    while(start >= 0 || end < vec.size()){
        cout << (start >= 0 && (end == vec.size() || vec[end] > -vec[start]) ? vec[start--] : vec[end++]) << " ";
    }
    cout << endl;
    return 0;
}

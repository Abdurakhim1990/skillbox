#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Task 6. Multiplication of a matrix by a vector" << endl;
    int M[4][4] = {{1, 2, 3, 4},{3, 4, 1, 2},{2, 4, 3, 3},{4, 1, 3, 2}};
    vector<int> V(4);// = {2, 3, 4, 5};
    vector<int> R(4);

    cout << "Input vector:" << endl;
    for(int i = 0; i < 4; ++i){
        cin >> V[i];
    }
    cout << "Input matrix:" << endl;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            cin >> M[i][j];
        }
    }

    for(int i = 0; i < 4; ++i){
        R[i] = 0;
        for(int j = 0; j < 4; ++j){
            R[i] += M[i][j] * V[j];
        }
        cout << R[i] << " ";
    }
    return 0;
}

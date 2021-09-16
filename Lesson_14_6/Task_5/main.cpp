#include <iostream>

using namespace std;

int main()
{
    cout << "Task 5. Diagonal matrix" << endl;
    float M[4][4];// = {{5.6, 8, 6, 4},{9, 4.1, 6, 7},{5, 8, 6, 4},{9, 4, 6, 7}};

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            cin >> M[i][j];
        }
    }

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            M[i][j] *= (i == j);
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    cout << "Task 4. Equality of matrices" << endl;
    int matr_a[4][4];
    int matr_b[4][4];

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            cin >> matr_a[i][j];
        }
    }
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            cin >> matr_b[i][j];
        }
    }

    bool equal = true;
    for(int i = 0; i < 4 && equal; ++i){
        for(int j = 0; j < 4 && equal; ++j){
            equal = (matr_a[i][j] == matr_b[i][j]);
        }
    }
    cout << (equal == true ? "Matrices are equal" : "Matrices are not equal");
    return 0;
}

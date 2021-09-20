#include <iostream>

using namespace std;

int main()
{
    cout << "Task 8. Almost-minecraft." << endl;
    bool space[5][5][10];
    int temp;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            do{
                cout << "Enter block size in sector [" << i << "] [" << j << "]: ";
                cin >> temp;
<<<<<<< HEAD
            } while (temp < 0 || temp > 10);
            for(int k = 0; k < 10; ++k){
                space[i][j][k] = (k >= temp ? false : true);
=======
            } while (temp < 0 || temp > 9);
            for(int k = 0; k < 10; ++k){
                space[i][j][k] = (k > temp ? false : true);
>>>>>>> 1728e13f789c7e7c76708c7d165806ea255a8129
            }
        }
    }
    while(1){
        do{
            cout << "Enter the cut level: ";
            cin >> temp;
        } while (temp < 0 || temp > 9);
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 5; ++j){
                cout << (space[i][j][temp] == true ? 1 : 0) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

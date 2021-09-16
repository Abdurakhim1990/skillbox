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
            } while (temp < 0 || temp > 10);
            for(int k = 0; k < 10; ++k){
                space[i][j][k] = (k >= temp ? false : true);
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

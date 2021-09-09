#include <iostream>

using namespace std;

int main()
{
    cout << "Task 3. Passage by a snake" << endl;
    int mass[5][5];
    int count = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mass[i][j] = count + (4 - 2 * j) * (i % 2);
            count++;
        }
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << mass[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}

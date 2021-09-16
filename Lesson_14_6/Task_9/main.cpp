#include <iostream>

using namespace std;

void InitPlayer(int mass[][10])
{
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            mass[i][j] = 0;
        }
    }
}

void OutputFields(int play_1[][10], int play_2[][10])
{
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            cout << (play_1[i][j] == -1 ? " " :(play_1[i][j] == 1 ? "x" : "o")) << " ";
        }
        cout << "\t\t";
        for(int j = 0; j < 10; ++j){
            cout << (play_2[i][j] == -1 ? " " :(play_2[i][j] == 1 ? "x" : "o")) << " ";
        }
        cout << endl;
    }
}

void PlacementShips(int play)
{

}

int main()
{
    cout << "Sea battle" << endl;
    int player_1[10][10];
    int player_2[10][10];
    InitPlayer(player_1);
    InitPlayer(player_2);

    OutputFields(player_1, player_2);
    return 0;
}

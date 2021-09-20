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
    cout << "     #Player 1\t\t\t     #Player 2 " << endl;
//    for(int i = 0; i < 10; ++i){
//        for(int j = 0; j < 10; ++j){
//            cout << (play_1[j][i] == -1 ? " " :(play_1[j][i] == 1 ? "x" : "o")) << " ";
//        }
//        cout << "\t\t";
//        for(int j = 0; j < 10; ++j){
//            cout << (play_2[j][i] == -1 ? " " :(play_2[j][i] == 1 ? "x" : "o")) << " ";
//        }
//        cout << endl;
//    }

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            cout << (play_1[j][i] == -1 ? " " :(play_1[j][i] == 1 ? "x" : (play_1[j][i] == 2 ? "o" : "."))) << " ";
        }
        cout << "\t\t";
        for(int j = 0; j < 10; ++j){
            cout << (play_2[j][i] == -1 ? " " :(play_2[j][i] == 1 ? "x" : (play_2[j][i] == 2 ? "o" : "."))) << " ";
        }
        cout << endl;
    }
}

void ContourReservation(int play[][10], int from_x, int from_y)
{
    if(from_x - 1 >= 0 && play[from_x - 1][from_y] != 1) play[from_x - 1][from_y] = 2;
    if(from_x + 1 < 10 && play[from_x + 1][from_y] != 1) play[from_x + 1][from_y] = 2;
    if(from_y - 1 >= 0 && play[from_x][from_y - 1] != 1) play[from_x][from_y - 1] = 2;
    if(from_y + 1 < 10 && play[from_x][from_y + 1] != 1) play[from_x][from_y + 1] = 2;
    if(from_x + 1 < 10 && from_y + 1 < 10) play[from_x + 1][from_y + 1] = 2;
    if(from_x - 1 >= 0 && from_y - 1 >= 0) play[from_x - 1][from_y - 1] = 2;
    if(from_x + 1 < 10 && from_y - 1 >= 0) play[from_x + 1][from_y - 1] = 2;
    if(from_x - 1 >= 0 && from_y + 1 < 10) play[from_x - 1][from_y + 1] = 2;
}

bool FreeFieldCheck(int play[][10], int from_x, int from_y, int to_x, int to_y, int size_ship)
{
    if(from_x > to_x){
        from_x += to_x;
        to_x = from_x - to_x;
        from_x -= to_x;
    }
    if(from_y > to_y){
        from_y += to_y;
        to_y = from_y - to_y;
        from_y -= to_y;
    }
    bool correct = true;
    if(from_x == to_x && ((from_y - to_y == size_ship - 1) || (to_y - from_y == size_ship - 1))){
        for(int i = from_y; i <= to_y && correct; ++i){
            correct = play[from_x][i] == 0;
        }
        for(int i = from_y; i <= to_y && correct; ++i){
            play[from_x][i] = 1;
            ContourReservation(play, from_x, i);
        }
    } else if(from_y == to_y && ((from_x - to_x == size_ship - 1) || (to_x - from_x == size_ship - 1))){
        for(int i = from_x; i <= to_x && correct; ++i){
            correct = play[i][from_y] == 0;
        }
        for(int i = from_x; i <= to_x && correct; ++i){
            play[i][from_y] = 1;
            ContourReservation(play, i, from_y);
        }
    } else  correct = false;
    if(!correct){
        cout << "Wrong coordinates!!!" << endl;
    }
    return correct;
}

void PlacementShips(int play[][10], int count_ship)
{
    int from_x, from_y, to_x, to_y;
    bool installed = true;
    do{
        do{
            cout << "Enter the coordinates of the start of the ship " << 11 - count_ship << ": ";
            cin >> from_x >> from_y;
            if(from_x >= 0 && from_x <= 9 && from_y >= 0 && from_y <= 9) break;
            cout << "Wrong coordinates!!!" << endl;
        } while(1);
        if(count_ship <= 6){
            do{
                cout << "Enter the coordinates of the end of the ship " << 11 - count_ship << ": ";
                cin >> to_x >> to_y;
                if(from_x >= 0 && from_x <= 9 && from_y >= 0 && from_y <= 9) break;
                cout << "Wrong coordinates!!!" << endl;
            } while(1);
        } else{
            to_x = from_x;
            to_y = from_y;
        }
        if(count_ship > 6){
            installed = FreeFieldCheck(play, from_x, from_y, to_x, to_y, 1);
        } else if(count_ship > 3){
            installed = FreeFieldCheck(play, from_x, from_y, to_x, to_y, 2);
        } else if(count_ship > 1){
            installed = FreeFieldCheck(play, from_x, from_y, to_x, to_y, 3);
        } else{
            installed = FreeFieldCheck(play, from_x, from_y, to_x, to_y, 4);
        }
    }
    while(!installed);
}

int main()
{
    cout << "Sea battle" << endl;
    int player_1[10][10];
    int player_2[10][10];
    InitPlayer(player_1);
    InitPlayer(player_2);
    OutputFields(player_1, player_2);
    for(int i = 10; i > 0; --i){
        PlacementShips(player_1, i);
        OutputFields(player_1, player_2);
    }
    for(int i = 10; i > 0; --i){
        PlacementShips(player_2, i);
        OutputFields(player_1, player_2);
    }
    return 0;
}

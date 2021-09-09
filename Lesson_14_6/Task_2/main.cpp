#include <iostream>

using namespace std;

void FieldOutput(char * mass)
{
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << *(mass + i * 3 + j);
        }
        cout << endl;
    }
}

bool CheckingCoord(char * mass, int coord_x, int coord_y, int player)
{
    if((coord_x >= 0 && coord_x < 3) && (coord_y >= 0 && coord_y < 3)){
        if(*(mass + coord_y * 3 + coord_x) == ' '){
            *(mass + coord_y * 3 + coord_x) = player == 0 ? 'X' : 'O';
            return true;
        } else{
            return false;
        }
    } else{
        return false;
    }
}

int WinCheck(char * mass, char symbol)
{
    bool win = false;
    for(int i = 0; i < 3 && win == false; i++){
        win = true;
        for (int j = 0; j < 3 && win; j++){
            win = *(mass + i * 3 + j) == symbol;
        }
    }
    for(int i = 0; i < 3 && win == false; i++){
        win = true;
        for (int j = 0; j < 3 && win; j++){
            win = *(mass + j * 3 + i) == symbol;
        }
    }
    return win;
}

int main()
{
    cout << "Task 2. Tic-tac-toe" << endl;
    char field[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            field[i][j] = ' ';
        }
    }
    int player = 0;
    int coor_x = 5, coor_y = 5;
    int count = 0;
    bool winner = false;

    while(!winner && count < 9){
        cout << "Enter coordinates X (0 - 2) of " << player + 1 << " player: ";
        cin >> coor_x;
        cout << "Enter coordinates Y (0 - 2) of " << player + 1 << " player: ";
        cin >> coor_y;
        if(CheckingCoord(field[0], coor_x, coor_y, player)){
            player++;
            player %= 2;
            count++;
        } else{
            cout << "Wrong coordinates" << endl;
        }
        FieldOutput(field[0]);
        if(WinCheck(field[0], 'X')){
            cout << "Player X - WINNER!!!";
            winner = true;
        }
        if(WinCheck(field[0], 'O')){
            cout << "Player O - WINNER!!!";
            winner = true;
        }
    }
    if(!winner && count == 9){
        cout << "Draw!!!";
    }
    return 0;
}

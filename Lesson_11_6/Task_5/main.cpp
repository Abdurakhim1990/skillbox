#include <iostream>

using namespace std;

bool CorrektLine(string line)
{
  bool real = line.length() == 3;
  for(int i = 0; real == true && i < line.length(); i++)
  {
    if(!(line[i] == 'O' || line[i] == 'X' || line[i] == '.')){
      real = false;
      break;
    }
  }
  return real;
}

char Coord(string line, int column)
{
    return line[column];
}

bool StringValidation(string line, char symbol)
{
    bool won = true;
    for(int i = 0; i < 3 && won; i++){
        if(Coord(line, i) != symbol){ won = false;}
    }
    return won;
}

int main()
{
    string line_1, line_2, line_3;
    cout << "Task 5. Analysis of the results of the game of tic-tac-toe.\n";
    cout << "Input tree lines: ";
    cin >> line_1 >> line_2 >> line_3;

    if(CorrektLine(line_1) && CorrektLine(line_2) && CorrektLine(line_3)){
        int count_won_X = 0, count_won_O = 0;

        StringValidation(line_1, 'X') == true ? count_won_X++ : (count_won_O += StringValidation(line_1, 'O'));
        StringValidation(line_2, 'X') == true ? count_won_X++ : (count_won_O += StringValidation(line_2, 'O'));
        StringValidation(line_3, 'X') == true ? count_won_X++ : (count_won_O += StringValidation(line_3, 'O'));

        for(int i = 0; i < 3; i++){
            (Coord(line_1, i) == 'X' && Coord(line_2, i) == 'X' && Coord(line_3, i) == 'X') == true ? count_won_X++ :
                    (count_won_O += (Coord(line_1, i) == 'O' && Coord(line_2, i) == 'O' && Coord(line_3, i) == 'O'));
        }

        (Coord(line_1, 0) == 'X' && Coord(line_2, 1) == 'X' && Coord(line_3, 2) == 'X') == true ? count_won_X++ :
                (count_won_O += (Coord(line_1, 0) == 'O' && Coord(line_2, 1) == 'O' && Coord(line_3, 2) == 'O'));

        (Coord(line_1, 2) == 'X' && Coord(line_2, 1) == 'X' && Coord(line_3, 0) == 'X') == true ? count_won_X++ :
                (count_won_O += (Coord(line_1, 2) == 'O' && Coord(line_2, 1) == 'O' && Coord(line_3, 0) == 'O'));

        if((count_won_X == 1 && count_won_O == 0) || (count_won_X == 0 && count_won_O == 1) || (count_won_X == 0 && count_won_O == 0)){
            int count_X = 0, count_O = 0;

            for(int i = 0; i < 3; i++){
                Coord(line_1, i) == 'X' ? count_X++ : (count_O += Coord(line_1, i) == 'O');
                Coord(line_2, i) == 'X' ? count_X++ : (count_O += Coord(line_2, i) == 'O');
                Coord(line_3, i) == 'X' ? count_X++ : (count_O += Coord(line_3, i) == 'O');
            }
            if(count_won_X && count_X == count_O + 1){
                cout << "Petya won" << endl;
            } else if(count_won_O && count_X == count_O){
                cout << "Vanya won" << endl;
            } else if(count_won_X == 0 && count_won_O == 0 && (count_X == count_O || count_X == count_O + 1)){
                cout << "Nobody" << endl;
            } else{
                cout << "Incorrect\n";
            }
        } else{
            cout << "Incorrect\n";
        }
    } else{
        cout << "Incorrect\n";
    }
    return 0;
}

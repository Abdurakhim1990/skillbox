#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Task 1. Development of a program for finding words in a file" << endl;
    ifstream colors;
    colors.open("../Task_1_Lesson_19_5/words.txt");
    string col;
    string search_col = "red";
    int count = 0;
    colors >> col;
    if(colors.is_open())
    {
        while(!colors.eof()){
            if(col == search_col){
                ++count;
            }
            colors >> col;
        }
        colors.close();
    }else
    {
        cout << "The file cannot be opened!" << endl;
    }

    cout << search_col << " = " << count << endl;
    return 0;
}

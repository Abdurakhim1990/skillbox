#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream colors;
    colors.open("D:\\Programs\\QtCreator\\skillbox\\Lesson_19_5\\Task_1_Lesson_19_5\\words.txt");
    string col;
    string search_col = "green";
    int count = 0;
    colors >> col;
    while(!colors.eof()){
        if(col == search_col){
            ++count;
        }
        colors >> col;
    }
    colors.close();
    cout << search_col << " = " << count << endl;
    return 0;
}

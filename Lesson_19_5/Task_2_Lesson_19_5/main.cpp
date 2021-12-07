#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Task 2. Development of a text file viewer" << endl;
    cout << "Input name file: ";
    string path_to_file = "../Task_2_Lesson_19_5/";
    string str;
    char buffer[50];
    cin >> str;
    path_to_file += str;
    ifstream file_txt;
    file_txt.open(path_to_file, ios::binary);
    if(!file_txt.is_open()){
        cout << "The file cannot be opened!" << endl;
    } else{
        while(!file_txt.eof()){
            file_txt.read(buffer, sizeof(buffer)-1);
            buffer[file_txt.gcount()] = '\0';
            cout << buffer;
        }
        cout << endl;
    }
    file_txt.close();
    return 0;
}

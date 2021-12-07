#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Task 4. Development of a PNG file detector" << endl;
    cout << "Input name file: ";
    string name_file;
    cin >> name_file;
    string extension = name_file.substr(name_file.length() - 4);
    if(name_file.length() >= 4 && (extension == ".PNG" || extension == ".png")){
        string path = "../Task_4_Lesson_19_5/";
        path += name_file;
        ifstream file_png (path, ios::binary);
        char buff[4];
        if(file_png.is_open()){
            file_png.read(buff, 4);
            if((int)buff[0] == -119 && buff[1] == 'P' && buff[2] == 'N' && buff[3] == 'G'){
                cout << "This file is PNG." << endl;
            } else{
                cout << "This file is not PNG." << endl;
            }
        } else{
            cout << "The file cannot be opened!" << endl;
        }
    } else{
        cout << "This file is not PNG." << endl;
    }
    return 0;
}

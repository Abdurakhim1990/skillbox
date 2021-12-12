#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int height;
    int width;
    srand(time(nullptr));
    cout << "Task 2. Implementation of drawing random pictures." << endl;
    cout << "Input height painting: ";
    cin >> height;
    cout << "Input width painting: ";
    cin >> width;

    ofstream pic("../Task_2_Lesson_20_5/pic.txt");
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            int bit = rand() % 2;
            pic << bit;
        }
        pic << endl;
    }
    pic.close();
    return 0;
}

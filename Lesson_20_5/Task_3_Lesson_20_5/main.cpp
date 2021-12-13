#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cout << "Task 3. Implementation of the simulation of the game \"Fishing\"" << endl;
    ifstream river("../Task_3_Lesson_20_5/river.txt");
    int count = 0;
    if(!river.is_open()){
        cout << "The file cannot be opened!" << endl;
    } else{
        ofstream basket("../Task_3_Lesson_20_5/basket.txt", ios::app);
        while(!river.eof()){
            string fish_in;
            string fish_river;
            cout << "Input name fish: ";
            cin >> fish_in;
            river >> fish_river;
            if(fish_in == fish_river){
                basket << fish_in << endl;
                ++count;
            }
        }
        basket.close();
    }
    river.close();
    cout << count << " fish caught" << endl;
    return 0;
}

#include "disk.h"

using namespace std;

void save(void)
{
    ofstream file_num("../../Task_2/data.txt");
    for(int i = 0; i < 8; ++i){
        file_num << read(i) << endl;
    }
    file_num.close();
    cout << "Saved in file." << endl;
}

void load(void)
{
    ifstream numbers("../../Task_2/data.txt");
    int numb;
    if(numbers.is_open()){
        for(int i = 0; i < 8; ++i){
            numbers >> numb;
            write(numb, i);
        }
        numbers.close();
        cout << "Read from file." << endl;
    }else
    {
        cout << "The file cannot be opened!" << endl;
    }
}

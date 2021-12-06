#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream data_list;
    string first_name;
    string last_name;
    string first_name_max;
    string last_name_max;
    int money;
    int money_max = 0;
    int money_sum = 0;
    string date;
    data_list.open("../Task_3_Lesson_19_5/list.txt");
    if(!data_list.is_open()){
        cout << "The file cannot be opened!" << endl;
    } else{
        while(!data_list.eof()){
            data_list >> last_name >> first_name >> money >> date;
            money_sum += money;
            if(money_max < money){
                money_max = money;
                first_name_max = first_name;
                last_name_max = last_name;
            }
        }
        cout << "Total amount paid out = " << money_sum << endl;
        cout << "The person with the maximum payout " << last_name_max << " " << first_name_max << endl;
    }
    data_list.close();
    return 0;
}

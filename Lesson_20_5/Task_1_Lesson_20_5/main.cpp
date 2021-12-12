#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool CorrectData(string data);

int main()
{
    string first_name;
    string last_name;
    string date;
    int money;

    cout << "Task 1. Implementation of an entry in the accounting sheet" << endl;
    cout << "Input First name: ";
    cin >> first_name;
    cout << "Input Last name: ";
    cin >> last_name;
    bool correct = false;
    do{
        cout << "Input Data list: ";
        cin >> date;
        correct = CorrectData(date);
    } while(!correct);
    do{
        cout << "Input money: ";
        cin >> money;
    } while(money < 0);
    ofstream data_list("../Task_1_Lesson_20_5/list.txt", ios::app);
    data_list << first_name << " " << last_name << " " << date << " " << money << endl;
    data_list.close();
    return 0;
}

bool CorrectData(string data)
{
    int len = data.length();
    if(len < 8 || len > 10)
        return false;
    int point[2];
    int count = 0;
    for(int i = 0; i < len; ++i){
        if(!((data[i] >= '0' && data[i] <= '9') || data[i] == '.')){
            return false;
        } else{
            if(data[i] == '.'){
                point[count] = i;
                ++count;
            }
        }
    }
    if(count != 2 || point[0] < 1 || point[0] > 2 || point[1] < 3 || point[1] > 5 || point[1] - point[0] < 2 || point[1] - point[0] > 3)
        return false;

    int day = stoi(data.substr(0, point[0]));
    int month = stoi(data.substr(point[0] + 1, point[1] - point[0]));
    int year = stoi(data.substr(point[1] + 1, 4));

    if(month < 0 || month > 12)
        return false;
    if(year > 0 && year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)){
        if(month == 2 && (day < 0 || day > 29))
            return false;
    } else{
        if(month == 2 && (day < 0 || day > 28))
            return false;
    }
    if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 0 || day > 31)){
        return false;
    } else if((month == 4 || month == 6 || month == 9 || month == 11) && (day < 0 || day > 30)){
        return false;
    }
    return true;
}

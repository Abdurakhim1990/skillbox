#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct statement{
    string first_name = "";
    string last_name = "";
    string date = "";
    int money = 0;
};

void Adding(void);
void Reading(vector<statement>& person);
bool CorrectData(string data);

int main()
{
    cout << "Task 1. Implementation of the accounting statement." << endl;
    statement worker;
    vector<statement> person;
    string command;
    cout << "Input command: \"add\" or \"read\":" << endl;
    cin >> command;
    if(command == "add"){
        Adding();
    } else if(command == "read"){
        Reading(person);
        for(int i = 0; i < person.size(); ++i){
            cout << person[i].first_name << " " << person[i].last_name << " "
                    << person[i].date << " " << person[i].money << endl;
        }
    }
    return 0;
}

void Adding(void)
{
    statement worker;
    cout << "Input First name: ";
    cin >> worker.first_name;
    cout << "Input Last name: ";
    cin >> worker.last_name;
    bool correct = false;
    do{
        cout << "Input Data list: ";
        cin >> worker.date;
        correct = CorrectData(worker.date);
    } while(!correct);
    cout << "Input money: ";
    cin >> worker.money;
    ofstream data_list("../Task_1_Lesson_21_5/list.txt", ios::app);
    data_list << worker.first_name << " " << worker.last_name << " " << worker.date << " " << worker.money << endl;
    data_list.close();
}

void Reading(vector<statement>& person)
{
    ifstream data_list("../Task_1_Lesson_21_5/list.txt");
    if(data_list.is_open()){
        while(!data_list.eof()){
            statement worker;
            data_list >> worker.first_name >> worker.last_name >> worker.date >> worker.money;
            if(worker.first_name != "")
                person.push_back(worker);
        }
        data_list.close();
    } else{
        cout << "The file cannot be opened!" << endl;
    }
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

#include <iostream>
#include <map>

using namespace std;
#include <vector>

int main()
{
    cout << "Task 1. Phone book" << endl;
    map<string, string> book_num_name;
    map<string, vector<string>> book_name_num;
    string number, last_name;
    while(true){
        int request;
        cout << "Input request: 1(add), 2(last name) or 3(number): ";
        cin >> request;
        if(request == 1){
            cout << "Input number: ";
            cin >> number;
            cout << "Input last name: ";
            cin >> last_name;
            book_num_name[number] = last_name;
            book_name_num[last_name].push_back(number);
        } else if(request == 2){
            cout << "Input number: ";
            cin >> number;
            cout << book_num_name[number] << endl;
        } else if(request == 3){
            cout << "Input last name: ";
            cin >> last_name;
            for(int i = 0; i < book_name_num[last_name].size(); ++i)
                cout << book_name_num[last_name][i] << " ";
            cout << endl;
        }
    }
    return 0;
}

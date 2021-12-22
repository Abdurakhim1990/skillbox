#include <iostream>
#include <map>

using namespace std;

int main()
{
    cout << "Task 1. Phone book" << endl;
    map<string, string> book_num_name;
    map<string, string> book_name_num;
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
            book_num_name.insert(pair<string, string> (number, last_name));
            map<string, string>::iterator it = book_name_num.find(last_name);
            if(it != book_name_num.end()){
                number += " " + it->second;
                book_name_num.erase(it);
            }
            book_name_num.insert(pair<string, string> (last_name, number));

//            map<string, string>::iterator itf = book_name_num.find(last_name);
//            cout << itf->first << " : " << itf->second << endl;
        } else if(request == 2){
            cout << "Input number: ";
            cin >> number;
            map<string, string>::iterator it = book_num_name.find(number);
            if(it != book_name_num.end()){
                cout << it->second << endl;
            }
        } else if(request == 3){
            cout << "Input last name: ";
            cin >> last_name;
            map<string, string>::iterator it = book_name_num.find(last_name);
            if(it != book_name_num.end()){
                cout << it->second << endl;
            }
        }
    }
    return 0;
}

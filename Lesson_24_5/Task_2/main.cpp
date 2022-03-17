#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct BirthFriend{
    string name = "";
    tm birthday;
};

void addFriends(vector<BirthFriend> &birthdayFriends);
void earlyBirthday(vector<BirthFriend> &dataBirth);

int main()
{
    vector<BirthFriend> birthdayFriends;

    addFriends(birthdayFriends);
    earlyBirthday(birthdayFriends);
    return 0;
}

void addFriends(vector<BirthFriend> &birthdayFriends)
{
    BirthFriend friends;
    cout << "Input friend's name: ";
    getline(cin, friends.name);
    while(friends.name != "end"){
        time_t t = time(nullptr);
        friends.birthday = *localtime(&t);
        cout << "Input date of birth (DD/MM/YYYY): ";
        cin >> get_time(&friends.birthday, "%d/%m/%Y");
        cin.ignore(numeric_limits<int>::max(), '\n');
        birthdayFriends.push_back(friends);
        cout << "Input friend's name: ";
        getline(cin, friends.name);
    }
}

void earlyBirthday(vector<BirthFriend> &dataBirth)
{
    int number = 0;
    vector<int> next_birth;
    time_t t = time(nullptr);
    tm real_time = *localtime(&t);
    int day_early = 100, month_early = 100;
    for(int i = 0; i < dataBirth.size(); ++i){
        if(dataBirth[i].birthday.tm_mon > real_time.tm_mon || (dataBirth[i].birthday.tm_mon == real_time.tm_mon &&
                dataBirth[i].birthday.tm_mday >= real_time.tm_mday)){
            if(month_early > dataBirth[i].birthday.tm_mon ||
                    (month_early == dataBirth[i].birthday.tm_mon && day_early > dataBirth[i].birthday.tm_mday)){
                month_early = dataBirth[i].birthday.tm_mon;
                day_early = dataBirth[i].birthday.tm_mday;
                while(number > 0){
                    --number;
                    next_birth.pop_back();
                }
                    next_birth.push_back(i);
                    ++number;
            } else if(month_early == dataBirth[i].birthday.tm_mon && day_early == dataBirth[i].birthday.tm_mday){
                cout << "repetition" << endl;/////
                next_birth.push_back(i);
                ++number;
            }
        }
    }
    if(number > 0){
        for(int i = 0; i < next_birth.size(); ++i){
            if(real_time.tm_mday == day_early && real_time.tm_mon == month_early){
                cout << dataBirth[next_birth[i]].name << "'s birthday today" << endl;
            } else{
                cout << dataBirth[next_birth[i]].name << "'s next birthday" << endl;
            }
        }
    } else{
        cout << "No birthdays this year" << endl;
    }
}

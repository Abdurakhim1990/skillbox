#include <iostream>

using namespace std;

#define MONDAY      1
#define TUESDAY     2
#define WEDNESDAY   3
#define THURSDAY    4
#define FRIDAY      5
#define SATURDAY    6
#define SUNDAY      7

#define MONDAY_STR      "MONDAY"
#define TUESDAY_STR     "TUESDAY"
#define WEDNESDAY_STR   "WEDNESDAY"
#define THURSDAY_STR    "THURSDAY"
#define FRIDAY_STR      "FRIDAY"
#define SATURDAY_STR    "SATURDAY"
#define SUNDAY_STR      "SUNDAY"

int main()
{
    cout << "Task 1. Implementation of advanced input and output of days of the week" << endl;
    int day;
    cout << "Input number days for week: ";
    cin >> day;
    cout << (day == MONDAY ? MONDAY_STR : (day == TUESDAY ? TUESDAY_STR
        : (day == WEDNESDAY ? WEDNESDAY_STR : (day == THURSDAY ? THURSDAY_STR
        : (day == FRIDAY ? FRIDAY_STR : (day == SATURDAY ? SATURDAY_STR
        : (day == SUNDAY ? SUNDAY_STR : ""))))))) << endl;
    return 0;
}

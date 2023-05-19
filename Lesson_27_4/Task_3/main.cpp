#include <iostream>
#include <string>
#include <vector>
#include "company.h"

using namespace std;

int main()
{
    Company company;
    company.createCompany();
    while (company.taskSetting() == true) {

    }
    company.displayCompany();
    return 0;
}

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "team.h"


class Company// : public Team
{
    string nameHeadCompany;
    vector<Team*> team;


public:
    Company(){}
    void createCompany(void);
    int getNumberTeams(void);
    string getNameHeadCompany(void);
    void displayCompany(void);
    bool taskSetting(void);
};

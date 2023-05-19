#include "company.h"

void Company::createCompany(void)
{
    int numberTeams;
    cout << "Enter the name of the head of the company: ";
    cin >> nameHeadCompany;
    cout << "Enter the number of teams: ";
    cin >> numberTeams;
    team.resize(numberTeams);
    for(int i = 0; i < numberTeams; ++i){
        team[i] = new Team();
        team[i]->createTeam();
    }
}

int Company::getNumberTeams(void)
{
    return team.size();
}

string Company::getNameHeadCompany(void)
{
    return nameHeadCompany;
}

void Company::displayCompany(void)
{
    cout << "Head of the company " << this->getNameHeadCompany() << endl;
    for(int i = 0; i < this->getNumberTeams(); ++i){
        cout << "\tTeam --- " << i + 1 << endl;
        cout << "\tName of the manager of company - " << team[i]->getNameManager() << " and Workers = "
             << team[i]->getNumberWorkers() << endl;
        for(int j = 0; j < team[i]->getNumberWorkers(); ++j){
            cout << "\t\tWorkers --- " << j + 1 << endl;
            cout << "\t\tName worker - " << team[i]->getWorker(j)->getNameWorker()
                 << "\t\tType - " << team[i]->getWorker(j)->getTypeWork() << endl;
        }
    }
}

bool Company::taskSetting(void)
{
    int valTask, typeTask;
    cout << "Set task scope: ";
    cin >> valTask;
    cout << "Set the task type:\n" << "\t\t1 - A\n\t\t2 - B\n\t\t3 - C\n";
    cin >> typeTask;
    bool freePerson = true;
    while(valTask > 0){
        freePerson = false;
        for(int i = 0; i < this->getNumberTeams(); ++i){
            srand(i + valTask + typeTask);
            cout << "\tManager " << team[i]->getNameManager() << " was instructed" << endl;
            freePerson |= team[i]->distributeTaskTeam(valTask, typeTask);
        }
    }

    return freePerson;
}

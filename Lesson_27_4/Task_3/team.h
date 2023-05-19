#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Worker
{
    string nameWorker;
    string task = "";
    string typeWork = "";

public:
    Worker(){};;
    void createWorker(void);
    string getNameWorker(void);
    void setTypeWork(int typeWork);
    string getTypeWork(void);
};

class Team : public Worker
{
    string nameManager;
    vector<Worker*> worker;


public:
    Team(){}

    void createTeam(void);;
    string getNameManager(void);
    int getNumberWorkers(void);
    Worker* getWorker(int num);
    bool distributeTaskTeam(int& countTask, int typeWork);
};


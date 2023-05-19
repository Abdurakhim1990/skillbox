#include "team.h"

void Worker::createWorker(void)
{
    cout << "\t\tEnter employee name: ";
    cin >> nameWorker;
}

string Worker::getNameWorker(void)
{
    return nameWorker;
}

void Worker::setTypeWork(int typeWork)
{
    vector<string> allTypeWork = {"Type_A", "Type_B", "Type_C"};
    if(typeWork > 0 && typeWork <= 3){
        this->typeWork = allTypeWork[--typeWork];
    }
}

string Worker::getTypeWork(void)
{
    return this->typeWork;
}

void Team::createTeam(void)
{
    int numberWorkers;
    cout << "\tEnter manager name: ";
    cin >> nameManager;
    cout << "\tEnter the number of employees in the team: ";
    cin >> numberWorkers;
    worker.resize(numberWorkers);
    for(int j = 0; j < numberWorkers; ++j){
        worker[j] = new Worker();
        worker[j]->createWorker();
    }
}

string Team::getNameManager(void)
{
    return nameManager;
}

int Team::getNumberWorkers(void)
{
    return worker.size();
}

Worker* Team::getWorker(int num)
{
    return worker[num];
}

bool Team::distributeTaskTeam(int& countTask, int typeWork)
{
    int tasksTeam = rand() % getNumberWorkers() + 1;
    for(int i = 0; tasksTeam > 0 && countTask > 0 && i < getNumberWorkers(); ++i){
        if(worker[i]->getTypeWork() == ""){
            worker[i]->setTypeWork(typeWork);
            --countTask;
            --tasksTeam;
            cout << "\t\tWorker " << worker[i]->getNameWorker() << " received a task: " << worker[i]->getTypeWork() << endl;
        }
        if(i == getNumberWorkers() - 1) return false;
    }
    return true;
}


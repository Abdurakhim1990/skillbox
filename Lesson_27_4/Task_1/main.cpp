#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Tree
{
private:
    string name = "";
    Tree* parent;
    int numberBranch = 0;
    vector<Tree*> branch;
public:
    Tree (Tree* parent)
    {
        this->parent = parent;
    }

    void createBranchs(int begin, int ending)
    {
        srand(time(nullptr));
        this->numberBranch = rand() % (ending - begin + 1) + begin;
        branch.resize(numberBranch);
        for(int i = 0; i < numberBranch; ++i){
            branch[i] = new Tree(this);
            cout << "Input name for elf : " << endl;
            string name;
            cin >> name;
            branch[i]->name = (name == "None" ? "" :  name);
        }
    }

    Tree* getBranch(int num)
    {
        if(num >= 0 && num <= numberBranch) return branch[num];
        else return nullptr;
    }

    int getNumberBranch()
    {
        return numberBranch;
    }

    Tree* searchElf(string nameElf)
    {
        for(int i = 0; i < numberBranch; ++i){
            if(branch[i]->name == nameElf){
                return branch[i]->parent;
            }
            for(int j = 0; j < branch[i]->numberBranch; ++j){
                if(branch[i]->branch[j]->name == nameElf){
                    return branch[i]->branch[j]->parent;
                }
            }
        }
        return nullptr;
    }

    int getNeighborsNumber(string nameElf)
    {
        Tree* parentBranch = searchElf(nameElf);
        if(parentBranch == nullptr) return -1;
        int neighbors = 0;
        for(int i = 0; i < parentBranch->getNumberBranch(); ++i){
            if(!(parentBranch->branch[i]->name == "" || parentBranch->branch[i]->name == nameElf))
                ++neighbors;
        }
        return neighbors;
    }
};

int main()
{
    vector<Tree*> tree(5);
    for(int i = 0; i < tree.size(); ++i){
        tree[i] = new Tree(nullptr);
        tree[i]->createBranchs(3, 5);
        for(int j = 0; j < tree[i]->getNumberBranch(); ++j){
            tree[i]->getBranch(j)->createBranchs(2, 3);
        }
    }
    cout << "\n*********************************************" << endl;

    string nameElf;
    cout << "Enter elf name" << endl;
    cin >> nameElf;
    int numNeighbors = 0;
    for(int k = 0; k < tree.size(); ++k){
        numNeighbors = tree[k]->getNeighborsNumber(nameElf);
        if(numNeighbors > 0) break;
    }
    if(numNeighbors != -1)
        cout << numNeighbors << (" neighbors of this elf") << endl;
    else
        cout << "There is no such elf" << endl;
    return 0;
}

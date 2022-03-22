#include "main.h"

using namespace std;

int main()
{
    cout << "Task 2. Computer simulator project." << endl;
    string com;
    cout << "Input command" << endl;
    cin >> com;
    while(com != "exit"){
        if(com == "sum"){
            compute();
        }else if (com == "save"){
            save();
        }else if (com == "load"){
            load();
        }else if (com == "input"){
            inputNumbers();
        }else if (com == "display"){
            consoleOutput();
        }
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "\nInput command" << endl;
        cin >> com;
    }
    return 0;
}

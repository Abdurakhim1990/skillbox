#include <iostream>
#include <string>
#include <sstream>

using namespace std;

enum notes{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LYA = 32,
    SI = 64
};

string NoteIdentifier(int nota)
{
    switch (nota) {
        case DO: return "do";
        case RE: return "re";
        case MI: return "mi";
        case FA: return "fa";
        case SOL: return "sol";
        case LYA: return "lya";
        case SI: return "si";
    }
    return "";
}

int main()
{
    cout << "Task 4. Mechanical piano" << endl;
    stringstream melody;
    for(int i = 0; i < 12; i++){
        string combin;
        cout << "Input combination " << i + 1 << " : ";

        cin >> combin;
        for(int j = 0; j < combin.size(); j++){
            int num;
            string ch_num;
            ch_num = combin[j];
            num = stoi(ch_num);
            melody << NoteIdentifier(1 << num) << " ";
        }
        melody << endl;
    }
    cout << melody.str() << endl;
    return 0;
}

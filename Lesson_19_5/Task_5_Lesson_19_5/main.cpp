#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void SectorSelection(int & position, bool * sector);
void Game(int & position, int & viewer, int & player);

int main()
{
    cout << "Task 5. Implementation of the game \"What? Where? When?\"" << endl;
    int arrow_position = 0;
    bool sector[]{true, true, true, true, true, true, true, true, true, true, true, true, true};
    int viewer = 0;
    int player = 0;
    cout << "Arrow on " << arrow_position + 1 << " sector." << endl;
    while(viewer < 6 && player < 6){
        SectorSelection(arrow_position, sector);
        Game(arrow_position, viewer, player);
    }
    cout << (viewer < player ? "--- Players WON! ---" : "--- Viewers WON! ---") << endl;
    return 0;
}

void SectorSelection(int & position, bool * sector)
{
    cout << "Enter offset: ";
    int offset = 0;
    cin >> offset;
    offset %= 13;
    position += offset;
    position %= 13;
    while(!sector[position]){
        ++position;
        position %= 13;
    }
    sector[position] = false;
    cout << "Arrow on " << position + 1 << " sector." << endl;
}

void Game(int & position, int & viewer, int & player)
{
    string path = "../Task_5_Lesson_19_5/Questions/sector_qst_" + to_string(position + 1) + ".txt";
    ifstream question(path, ios::binary);
    if(question.is_open()){
        char buffer[50];
        while(!question.eof()){
            question.read(buffer, sizeof (buffer) - 1);
            buffer[question.gcount()] = '\0';
            cout << buffer;
        }
        question.close();

        string path = "../Task_5_Lesson_19_5/Answers/sector_ans_" + to_string(position + 1) + ".txt";
        ifstream answer(path, ios::binary);
        if(answer.is_open()){
            string answer_viewer;
            string answer_player;
            answer >> answer_viewer;
            cout << "\n/************************\nInput Answer: ";
            cin >> answer_player;
            if(answer_player == answer_viewer){
                cout << "The answer is correct!" << endl;
                ++player;
            } else{
                cout << "The answer is not correct!!!" << endl;
                cout << "Correct answer " << answer_viewer << "!\n\n";
                ++viewer;
            }
            cout << "Current account :\n\t\tPlayers - " << player;
            cout << "\n\t\tViewers - " << viewer << endl;
            cout << "/************************\n\n";
        } else{
            cout << "Answer file not found" << endl;
        }
    } else{
        cout << "Question file not found" << endl;
    }
}

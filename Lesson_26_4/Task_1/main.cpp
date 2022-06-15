#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;


class Track
{
    string name = "";
    tm* time_creat;
    int duration = 0;

    void writeNameTrack()
    {
        name = "";
        int count = 0;
        count = rand() % 7 + 3;
        for(int i = 0; i < count; ++i){
            char c;
            c = 'a' + rand() % ('z' - 'a' + 1);
            name += c;
        }
    }
    void dateCreated(time_t *t)
    {
        time_creat = localtime(t);
    }
    void setDuration()
    {
        duration = rand() % 100;
//        cout << "Input duration: " << endl;
//        cin >> duration;
    }

    static void writeAudio(Track* track)
    {
        time_t t = time(nullptr);
        track->writeNameTrack();
        track->dateCreated(&t);
        track->setDuration();
    }

public:
    static void showTrack(Track& track)
    {
        cout << "File is " << track.name << " " << put_time(track.time_creat, "%y/%m/%d %H:%M:%S") <<
             " --- " << track.duration << " sec" << endl;
    }

    static vector <Track> writeList(vector <Track> list)
    {
        Track* track = new Track();
        for(int i = 0; i < 5; i++){
            writeAudio(track);
            list.push_back(*track);
        }
        delete track;
        return list;
    }
};

class Player
{
    int num_play_list = 0;
    string mode_player = "stop";

    void setNumPlayList(int num)
    {
        num_play_list = num;
    }

    void setModePlayer(string com)
    {
        mode_player = com;
    }

    int getNumPlayList()
    {
        return num_play_list;
    }

    string getModePlayer()
    {
        return mode_player;
    }

public:
    static void playAudio(vector <Track> play_list)
    {
        Player* player = new Player();
        string com = "";
        cout << "Input player command (\"play\", \"pause\", \"next\", \"stop\" or \"exit\") : ";
        cin >> com;
        while (com != "exit"){
            if(com == "play"){
                if(player->getModePlayer() != "play"){
                    player->setModePlayer("play");
                    cout << "Playing. File is ";
                    Track::showTrack(play_list[player->getNumPlayList()]);
                }
            } else if(com == "pause"){
                if(player->getModePlayer() != "pause"){
                    player->setModePlayer("pause");
                    cout << "Pause. File is ";
                    Track::showTrack(play_list[player->getNumPlayList()]);
                }
            } else if(com == "next"){
                player->setNumPlayList(rand() % play_list.size());
                player->setModePlayer("play");
                cout << "Playing. File is ";
                Track::showTrack(play_list[player->getNumPlayList()]);
            } else if(com == "stop"){
                if(player->getModePlayer() != "stop"){
                    player->setModePlayer("stop");
                    cout << "Stop play." << endl;
                }
            }
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\n\nInput player command (\"play\", \"pause\", \"next\", \"stop\" or \"exit\") : ";
            cin >> com;
        }
        delete player;
    }
};

int main()
{
    vector <Track> list_track;
    list_track = Track::writeList(list_track);

    for(int i = 0; i < list_track.size(); ++i){
        Track::showTrack(list_track[i]);
    }

    Player::playAudio(list_track);
    return 0;
}

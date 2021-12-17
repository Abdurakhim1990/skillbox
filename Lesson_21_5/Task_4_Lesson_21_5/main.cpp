#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

struct Player{
    string name = "";
    int x = 0;
    int y = 0;
    int live = 0;
    int armor = 0;
    int damage = 0;
    bool alive = false;
};

void fillingFieldDefault(char* field);
void outField(char* field, Player& player, vector<Player>& enemy);
void placementEnemy(char* map, vector<Player>& enemy);
void placementPlayer(char* map, Player& player);
void walingEnemy(char* map, vector<Player>& enemy, Player& player);
void walingPlayer(char* map, Player& player, vector<Player>& enemy);
void attack(Player& play_1, Player& play_2);
void loadSettings(string name_file, vector<Player>& enemy, Player& player);
void saveSettings(string name_file, vector<Player>& enemy, Player& player);

int main()
{
    char map[40][40];
    vector<Player> enemy(5);
    Player player;
    srand(time(nullptr));
    fillingFieldDefault(map[0]);
    placementEnemy(map[0], enemy);
    placementPlayer(map[0], player);
    outField(map[0], player, enemy);
    while(player.alive && (enemy[0].alive || enemy[1].alive || enemy[2].alive
                           || enemy[3].alive || enemy[4].alive)){
        walingPlayer(map[0], player, enemy);
        walingEnemy(map[0], enemy, player);
        outField(map[0], player, enemy);
    }
    if(player.alive){
        cout << "\nWin!!!" << endl;
    } else{
        cout << "\nDefeat!" << endl;
    }
    return 0;
}

void fillingFieldDefault(char* field)
{
    for(int i = 0; i < 40; ++i){
        for(int j = 0; j < 40; ++j){
            *(field + 40 * i + j) = '.';
        }
    }
}

void outField(char* field, Player& player, vector<Player>& enemy)
{
    cout << "\n============================================\n";
    for(int i = 0; i < 40; ++i){
        cout << "| ";
        for(int j = 0; j < 40; ++j){
            cout << *(field + 40 * i + j);
        }
        cout << " |" << endl;
    }
    cout << "============================================\n" << endl;
    cout << player.name << ": Live = " << player.live << ", Armor = " << player.armor
         << ", Damage = " << player.damage << endl;
    for(int i = 0; i < 5; ++i){
        cout << enemy[i].name << ": Live = " << enemy[i].live << ", Armor = " << enemy[i].armor
             << ", Damage = " << enemy[i].damage << endl;
    }
    cout << endl;
}

void placementEnemy(char* map, vector<Player>& enemy)
{
    for(int i = 0; i < 5; ++i){
        enemy[i].name = "Enemy_#" + to_string(i + 1);
        do{
            enemy[i].x = rand() % 40;
            enemy[i].y = rand() % 40;
        } while(*(map + 40 * enemy[i].y + enemy[i].x) == 'E');
        *(map + 40 * enemy[i].y + enemy[i].x) = 'E';
        enemy[i].live = rand() % 101 + 50;
        enemy[i].armor = rand() % 51;
        enemy[i].damage = rand() % 16 + 15;
        enemy[i].alive = true;
    }
}

void placementPlayer(char* map, Player& player)
{
    cout << "Input name your Player: ";
    cin >> player.name;
    cout << "Input coordinates Player (0-40) \"X\" and \"Y\": ";
    cin >> player.x >> player.y;
    player.x %= 40;
    player.y %= 40;
    *(map + 40 * player.y + player.x) = 'P';
    cout << "Input Live: ";
    cin >> player.live;
    cout << "Input Armor: ";
    cin >> player.armor;
    cout << "Input Damage: ";
    cin >> player.damage;
    player.alive = true;
}

void walingEnemy(char* map, vector<Player>& enemy, Player& player)
{
    for(int i = 0; i < 5; ++i){
        if(enemy[i].alive)
        {
            int move = rand() % 4;
            if(move == 0){
                if(enemy[i].x > 0 && *(map + 40 * enemy[i].y + enemy[i].x - 1) != 'E'){
                    *(map + 40 * enemy[i].y + enemy[i].x) = '.';
                    --enemy[i].x;
                    *(map + 40 * enemy[i].y + enemy[i].x) = 'E';
                }
            } else if(move == 1){
                if(enemy[i].y > 0 && *(map + 40 * (enemy[i].y - 1) + enemy[i].x) != 'E'){
                    *(map + 40 * enemy[i].y + enemy[i].x) = '.';
                    --enemy[i].y;
                    *(map + 40 * enemy[i].y + enemy[i].x) = 'E';
                }
            } else if(move == 2){
                if(enemy[i].x < 39 && *(map + 40 * (enemy[i].y) + enemy[i].x + 1) != 'E'){
                    *(map + 40 * enemy[i].y + enemy[i].x) = '.';
                    ++enemy[i].x;
                    *(map + 40 * enemy[i].y + enemy[i].x) = 'E';
                }
            } else if(move == 3){
                if(enemy[i].y < 39 && *(map + 40 * (enemy[i].y + 1) + enemy[i].x) != 'E'){
                    *(map + 40 * enemy[i].y + enemy[i].x) = '.';
                    ++enemy[i].y;
                    *(map + 40 * enemy[i].y + enemy[i].x) = 'E';
                }
            }
            attack(enemy[i], player);
        }
    }
}

void walingPlayer(char* map, Player& player, vector<Player>& enemy)
{
    cout << "Input command: 'load', 'save', 'left', 'right', 'top', 'bottom': ";
    string command;
    cin >> command;
    string name_file = "../Task_4_Lesson_21_5/game settings.txt";
    if(command == "load"){
        loadSettings(name_file, enemy, player);
        fillingFieldDefault(map);
        *(map + 40 * player.y + player.x) = 'P';
    } else if(command == "save"){
        saveSettings(name_file, enemy, player);
    } else if(command == "l" || command == "left"){
        if(player.x > 0){
            if(*(map + 40 * player.y + player.x) != 'E')
                *(map + 40 * player.y + player.x) = '.';
            --player.x;
            *(map + 40 * player.y + player.x) = 'P';
        }
    } else if(command == "r" || command == "right"){
        if(player.x < 39){
            if(*(map + 40 * player.y + player.x) != 'E')
                *(map + 40 * player.y + player.x) = '.';
            ++player.x;
            *(map + 40 * player.y + player.x) = 'P';
        }
    } else if(command == "t" || command == "top"){
        if(player.y > 0){
            if(*(map + 40 * player.y + player.x) != 'E')
                *(map + 40 * player.y + player.x) = '.';
            --player.y;
            *(map + 40 * player.y + player.x) = 'P';
        }
    } else if(command == "b" || command == "bottom"){
        if(player.y < 39){
            if(*(map + 40 * player.y + player.x) != 'E')
                *(map + 40 * player.y + player.x) = '.';
            ++player.y;
            *(map + 40 * player.y + player.x) = 'P';
        }
    }
    for(int i = 0; i < 5; ++i){
        if((enemy[i].alive)){
            attack(player, enemy[i]);
            if(enemy[i].alive == false)
                *(map + 40 * enemy[i].y + enemy[i].x) = 'P';
        }
    }
}

void attack(Player& play_1, Player& play_2)
{
    if(play_1.x == play_2.x && play_1.y == play_2.y){
        play_2.armor -= play_1.damage;
        if(play_2.armor < 0){
            play_2.live += play_2.armor;
            play_2.armor = 0;
            if(play_2.live <= 0)
                play_2.alive = false;
        }
    }
}

void loadSettings(string name_file, vector<Player>& enemy, Player& player)
{
    ifstream file(name_file);
    if(file.is_open()){
        file >> player.name >> player.x >> player.y >> player.live
                >> player.armor >> player.damage >> player.alive;
        for(int i = 0; i < 5; ++i){
            file >> enemy[i].name >> enemy[i].x >> enemy[i].y >> enemy[i].live
                    >> enemy[i].armor >> enemy[i].damage >> enemy[i].alive;
        }
        file.close();
    } else{
        cout << "File not found!" << endl;
    }
}

void saveSettings(string name_file, vector<Player>& enemy, Player& player)
{
    ofstream file(name_file);
    file << player.name << " " << player.x << " " << player.y << " " << player.live << " "
            << player.armor << " " << player.damage << " " << player.alive << endl;
    for(int i = 0; i < 5; ++i){
        file << enemy[i].name << " " << enemy[i].x << " " << enemy[i].y << " " << enemy[i].live << " "
                << enemy[i].armor << " " << enemy[i].damage << " " << enemy[i].alive << endl;
    }
    file.close();
}

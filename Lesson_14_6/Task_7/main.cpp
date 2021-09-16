#include <iostream>

using namespace std;

void InitBubble(bool mass[][12])
{
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            mass[i][j] = true;
        }
    }
}

bool ValidityCheck(int coor_x, int coor_y)
{
    if(coor_x >= 0 && coor_x < 12 && coor_y >= 0 && coor_y < 12){
        return false;
    } else{
        cout << "Wrong point!" << endl;
        return true;
    }
}

bool OutBubble(bool mass[][12])
{
    bool remain = false;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            if(mass[i][j]){
                remain = true;
                cout << "o ";
            } else{
                cout << "x ";
            }
        }
        cout << endl;
    }
    return remain;
}

void BurstingBubble(bool mass[][12], int start_x, int start_y, int end_x, int end_y)
{
    if(start_x > end_x){
        start_x += end_x;
        end_x = start_x - end_x;
        start_x -= end_x;
    }
    if(start_y > end_y){
        start_y += end_y;
        end_y = start_y - end_y;
        start_y -= end_y;
    }
    for(int i = start_y; i <= end_y; ++i){
        for(int j = start_x; j <= end_x; ++j){
            if(mass[i][j]){
                mass[i][j] = false;
                cout << "Pop" << endl;
            }
        }
    }
}

int main()
{
    cout << "Task 7. Bubble" << endl;
    bool bubble[12][12];
    InitBubble(bubble);
    bool whole = OutBubble(bubble);
    int start_x, start_y;
    int end_x, end_y;
    while(whole){
        do {
            cout << "Enter the coordinates of the start of the region: ";
            cin >> start_x >> start_y;
        } while(ValidityCheck(start_x, start_y));
        do {
            cout << "Enter the coordinates of the start of the region: ";
            cin >> end_x >> end_y;
        } while(ValidityCheck(end_x, end_y));
        BurstingBubble(bubble, start_x, start_y, end_x, end_y);
        whole = OutBubble(bubble);
    }
    return 0;
}

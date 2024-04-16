#include <iostream>
#include <vector>
#include <ctime>
#include <exception>

using namespace std;

class SuccessfulFishing: public exception
{
public:
    const char* what() const noexcept override
    {
        return "Fish caught.";
    }
};

class UnsuccessfulFishing: public exception
{
public:
    const char* what() const noexcept override
    {
        return "The game is lost.";
    }
};

void FieldOut(vector<string> &field)
{
    for(int i = 0; i < field.size(); ++i){
        cout << field[i] << " ";
    }
    cout << endl << endl;
}

void FieldFill(vector<string> &field)
{
    for(int i = 0; i < field.size(); ++i){
        field[i] = "empty";
    }
}

void FieldPreparation(vector<string> &field)
{
    srand(time(nullptr));
    field[rand() % 9] = "fish";

    int count_boot = 3;
    int boot = rand() % 9;
    while (count_boot){
        if(field[boot] == "empty"){
            field[boot] = "boot";
            --count_boot;
        }
        boot = rand() % 9;
    }
}

void Fishing(vector<string> &field)
{
    bool play = true;
    int take;
    int count = 0;
    while(play){
        cout << "Enter the sector number (1 - 9)" << endl;
        cin >> take;
        try {
            if(take < 1 || take > 9){
                throw invalid_argument("Invalid sector number");
            } else if(field[take - 1] == "fish"){
                ++count;
                throw SuccessfulFishing();
            } else if(field[take - 1] == "boot"){
                throw UnsuccessfulFishing();
            } else {
                ++count;
                cout << "Number of attempts " << count << endl;
            }
        }
        catch (const SuccessfulFishing &x) {
            cerr << x.what() << " Number of attempts " << count << endl;
            play = false;
        }
        catch (const UnsuccessfulFishing &x) {
            cerr << x.what() << endl;
            play = false;
        }
        catch (const invalid_argument &x) {
            cerr << x.what() << endl;
        }
    }
}

int main()
{
    vector<string> field(9);
    FieldFill(field);
    FieldPreparation(field);
    FieldOut(field);
    Fishing(field);
    return 0;
}

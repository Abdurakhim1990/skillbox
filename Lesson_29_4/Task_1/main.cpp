#include <iostream>
#include <vector>

using namespace std;

class Talent
{
public:
    virtual void show_talent() = 0;
};

class Dance :public Talent
{
public:
    virtual void show_talent() override
    {
        cout << "\tIt can DANCE" << endl;
    }
};

class Swim :public Talent
{
public:
    virtual void show_talent() override
    {
        cout << "\tIt can SWIM" << endl;
    }
};

class Play :public Talent
{
public:
    virtual void show_talent() override
    {
        cout << "\tIt can PLAY" << endl;
    }
};

class Count :public Talent
{
public:
    virtual void show_talent() override
    {
        cout << "\tIt can COUNT" << endl;
    }
};

class Dog
{
private:
    string name;
    vector<Talent*> talents;
public:
    Dog(){};
    Dog(string _name)
    {
        name = _name;
    };

    void show_talents()
    {
        cout << "This is " << name << " and it has some talents:" << endl;
        for(int i = 0; i < talents.size(); ++i){
            talents[i]->show_talent();
        }
        cout << endl;
    }

    void add_talent(Talent* tal)
    {
        talents.push_back(tal);
    }
};


int main()
{
    Play tal_play;
    Swim tal_swim;
    Dance tal_dance;
    Count tal_count;

    Dog dog1("Steve");
    Dog dog2("Rex");
    Dog dog3("Sharik");

    dog1.add_talent(&tal_dance);
    dog1.add_talent(&tal_swim);
    dog2.add_talent(&tal_dance);
    dog2.add_talent(&tal_play);
    dog3.add_talent(&tal_count);
    dog3.add_talent(&tal_swim);
    dog3.add_talent(&tal_play);


    dog1.show_talents();
    dog2.show_talents();
    dog3.show_talents();
    return 0;
}

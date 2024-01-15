#include <iostream>
#include <vector>

using namespace std;

class Animal
{
public:
    virtual void voice() = 0;
    string name;
};

class Talent
{
public:
    virtual void show_talents() = 0;
};

class Dog :public Animal, public Talent
{
private:
    vector<string> talents;
public:
    Dog(){};
    Dog(string _name)
    {
        name = _name;
    };

    virtual void voice() override
    {
        cout << "Bark!" << endl;
    }

    virtual void show_talents() override
    {
        cout << "This is " << name << " and it has some talents:" << endl;
        for(int i = 0; i < talents.size(); ++i){
            cout << "\tIt can \"" << talents[i] << "\"" << endl;
        }
        cout << endl;
    }

    void add_talent(string tal)
    {
        for(int i = 0; i < talents.size(); ++i){
            if(talents[i] == tal)
                return;
        }
        talents.push_back(tal);
    }
};

class Cat : virtual public Animal
{
public:
    virtual void voice()
    {
        cout << "Meow!" << endl;
    }
};

int main()
{
    Talent* dog;// = new Dog("Steve");
    Dog dog1("Steve");
    Dog dog2("Rex");
    Dog dog3("Sharik");

    dog1.add_talent("dance");
    dog1.add_talent("swim");
    dog2.add_talent("dance");
    dog2.add_talent("play");
    dog3.add_talent("count");
    dog3.add_talent("swim");
    dog3.add_talent("play");


    dog = &dog1;
    dog->show_talents();

    dog = &dog2;
    dog->show_talents();

    dog = &dog3;
    dog->show_talents();
    return 0;
}

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
    virtual void add_dancing() = 0;
    virtual void add_swiming() = 0;
    virtual void add_counting() = 0;
    virtual void add_playing() = 0;
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

    virtual void add_dancing() override
    {
        for(int i = 0; i < talents.size(); ++i){
            if(talents[i] == "Dance")
                return;
        }
        talents.push_back("Dance");
    }

    virtual void add_swiming() override
    {
        for(int i = 0; i < talents.size(); ++i){
            if(talents[i] == "Swim")
                return;
        }
        talents.push_back("Swim");
    }

    virtual void add_counting() override
    {
        for(int i = 0; i < talents.size(); ++i){
            if(talents[i] == "Count")
                return;
        }
        talents.push_back("Count");
    }

    virtual void add_playing() override
    {
        for(int i = 0; i < talents.size(); ++i){
            if(talents[i] == "Play")
                return;
        }
        talents.push_back("Play");
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

class CatDot : virtual public Cat, virtual public Dog
{
public:
    virtual void voice()
    {
        cout << "BarkMeow!" << endl;
    }

};

int main()
{
    Talent* dog;// = new Dog("Steve");
    Dog dog1("Steve");
    Dog dog2("Rex");
    Dog dog3("Sharik");

    dog = &dog1;
    dog->add_dancing();
    dog->add_swiming();
    dog->show_talents();

    dog = &dog2;
    dog->add_dancing();
    dog->add_playing();
    dog->show_talents();

    dog = &dog3;
    dog->add_counting();
    dog->add_swiming();
    dog->add_playing();
    dog->show_talents();
    return 0;
}

#include <iostream>
#include <memory>

using namespace std;


class Toy
{
public:
    Toy(const std::string& name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }
    ~Toy()
    {
        cout << "Toy " << this->name << " was dropped " << endl;
    }

private:
    string name;
};

class Dog
{
public:
    Dog(string _name) :name(_name){}

    void getToy(shared_ptr<Toy> toy)
    {
        if(lovelyToy != nullptr && toy == lovelyToy){
            cout << "I already have this toy." << endl;
        } else if(toy.use_count() > 2){
            cout << "Another dog is playing with this toy." << endl;
        } else {
            lovelyToy = toy;
            cout << "The dog " << this->name << " took the toy " << lovelyToy->getName() << endl;
        }
    }
    void dropToy()
    {
        if(lovelyToy == nullptr){
            cout << "Nothing to drop." << endl;
        } else {
            cout << "The dog " << this->name << " threw out the toy " << lovelyToy->getName() << endl;
            lovelyToy.reset();
        }
    }
private:
shared_ptr<Toy> lovelyToy;
string name;
};

int main() {
    shared_ptr<Toy> toy_1 = make_shared<Toy>("Toy_1");
    shared_ptr<Toy> toy_2 = make_shared<Toy>("Toy_2");

    shared_ptr<Dog> dog_1 = make_shared<Dog>("Dog_1");
    shared_ptr<Dog> dog_2 = make_shared<Dog>("Dog_2");
    shared_ptr<Dog> dog_3 = make_shared<Dog>("Dog_3");

    dog_1->getToy(toy_1);
    dog_2->getToy(toy_2);
    dog_3->getToy(toy_2);
    dog_1->getToy(toy_1);

    dog_3->dropToy();
    dog_1->dropToy();
    dog_3->getToy(toy_1);
    dog_2->dropToy();
    dog_3->getToy(toy_2);


    return 0;
}

#include <iostream>

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

class shared_ptr_toy
{
private:
    Toy* toy = nullptr;
    int* count = nullptr;
public:
    shared_ptr_toy (string _name){
        toy = new Toy(_name);
        count = new int(1);
    }

    shared_ptr_toy (const shared_ptr_toy& other)
    {
        toy = other.toy;
        this->count = other.count;
        ++*count;
    }

    ~shared_ptr_toy (){
        if(toy != nullptr){
            --(*count);
            if(!*count){
                delete  toy;
                delete count;
            }
        }
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other)
    {
        if(this == &other){
            return *this;
        }
        if(toy != nullptr){
            --*this->count;
        }
        toy = other.toy;
        count = other.count;
        ++*count;
        return *this;
    }

    void reset()
    {
        if(toy != nullptr){
            --(*count);
            if(!*count){
                delete  toy;
                delete count;
                toy = nullptr;
                count = nullptr;
            }
        }
    }

    int use_count() const
    {
        if(toy != nullptr)
            return *count;
        return 0;
    }

    Toy* get() const
    {
        return toy;
    }

    string getToyName()
    {
        if(toy != nullptr){
            return this->toy->getName();
        }
        return "Nothing";
    }

    friend shared_ptr_toy& make_shared_toy(string name_toy);
};

shared_ptr_toy& make_shared_toy(string name_toy)
{
    shared_ptr_toy* toy = new shared_ptr_toy(name_toy);
    --*toy->count;
    return *toy;
}

int main()
{
    shared_ptr_toy toy_01 = make_shared_toy("ball");
    shared_ptr_toy toy_02(toy_01);
    shared_ptr_toy toy_03("duck");
    std::cout << "=================================================" << std::endl;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;
    toy_02 = toy_03;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;
    toy_01.reset();
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;
    return 0;
}

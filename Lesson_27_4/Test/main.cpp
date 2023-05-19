#include <iostream>
#include <cassert>

using namespace std;

class TrainCar
{
    int passengers_max = 0;
    int passengers = 0;

    class Train* train = nullptr;

public:
    void load(int value)
    {
        passengers += value;
        if(passengers > passengers_max)
        {
            passengers = passengers_max;
        }
    }

    int getPassergers()
    {
        return passengers;
    }

    TrainCar(class Train* inTrain, int passengersMax)
    {
        assert(inTrain != nullptr);
        assert(passengersMax >= 0);
        this->passengers_max = passengersMax;
    }

    int getNumber();
};

class Train
{
    int count = 0;
    TrainCar ** cars = nullptr;

public:
    TrainCar* getCarAt(int index)
    {
        if(this == nullptr) return nullptr;
        if(index < 0) return nullptr;
        if(index >= this->count) return nullptr;
        return this->cars[index];
    }

    int getCount()
    {
        return count;
    }

    Train(int inCount, int inPassengersMax): count(inCount)
    {
        assert(inCount >= 0);
        cars = new TrainCar*[inCount];
        for(int i = 0; i < count; ++i)
        {
            cars[i] = new TrainCar(this, inPassengersMax);
        }
    }
};

int TrainCar::getNumber()
{
    for(int i = 0; i < train->getCount(); ++i)
    {
        TrainCar* car = train->getCarAt(i);
        if(car == this) return i;
    }
    assert(false);
}

int main()
{
    Train* train = nullptr;
    train->getCarAt(2);
    train = new Train(10, 30);
    for(int i = 0; i < train->getCount(); ++i)
    {
        int passengers = 0;
        cin >> passengers;
        train->getCarAt(i)->load(passengers);
    }
    TrainCar* car3 = train->getCarAt(2);
    cout << car3->getNumber() << ": " << car3->getPassergers() << endl;
    delete train;
    return 0;
}

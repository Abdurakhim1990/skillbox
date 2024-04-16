#include <iostream>
#include <exception>

using namespace std;

class DivisionByZeroException: public exception
{
    const char* what() const noexcept override
    {
        return "Division by zero";
    }
};

int divide(int dividend, int divisior)
{
    if(divisior == 0){
        throw  DivisionByZeroException();
    }
    return dividend/divisior;
}

int distribute(int apples, int count)
{
    if(apples < 0 || count < 0){
        throw invalid_argument(apples < 0 ? "apples" : "count");
    }
    if(apples > 100){
        throw apples;
    }
    return divide(apples, count);
}

int main()
{
    int apples;
    int count;
    bool input = true;
    while(input){
        cin >> apples >> count;
        try {
            cout << "Apples: " << distribute(apples, count) << endl;
            input = false;
        }  catch (const DivisionByZeroException &x) {
            input = false;
        }
        catch (const invalid_argument &x) {
            cerr << "invalid argument supplied: " << x.what() << endl;
        }
        catch(...){
            cerr << "Some kind of exception has happened..." << endl;
        }

//    }  catch (const exception& x) {
//        cerr << "Caught exception: " << x.what() << endl;
//    }
    }
    return 0;
}

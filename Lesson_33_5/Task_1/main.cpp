#include <iostream>
#include <map>
#include <exception>

using namespace std;

class IncorrectCommand: public exception
{
    const char* what() const noexcept override
    {
        return "runtime_error";
    }
};

void Add(map<string, int> &product)
{
    string article;
    int quantity;
    cout << "Enter the Article and Quantity of the product" << endl;
    cin >> article >> quantity;
    if(cin.fail()){
        cin.clear();
        throw quantity;
    }
    product.insert(pair<string,int> (article, quantity));
}

void Remove(map<string, int> &product)
{
    string article;
    int quantity;
    cout << "Enter the Article and Quantity of the product" << endl;
    cin >> article >> quantity;
    if(cin.fail()){
        cin.clear();
        throw quantity;
    }
    auto search = product.find(article);
    if(search == product.end()){
        throw invalid_argument("article");
    }
    if(search->second < quantity){
        throw invalid_argument("quantity");
    }
    search->second -= quantity;
    if(search->second == 0){
        product.erase(search);
    }
}

void ListOut(map<string, int> &product)
{
    for(auto it = product.begin(); it != product.end(); ++it){
        cout << "Article: " << it->first << "\t--- " << it->second << " pieces" <<  endl;
    }
}

int main()
{
    map<string, int> product;

    while(true){
        string command;
        cout << "Input \"add\" or \"remove\": ";
        cin >> command;

        try {
            if(command == "add"){
                Add(product);
            } else if(command == "remove"){
                Remove(product);
            } else {
                throw  IncorrectCommand();
            }
            ListOut(product);
        } catch (const invalid_argument &x) {
            cerr << "runtime error " << x.what() << endl;
        } catch (const IncorrectCommand &x) {
            cerr << "Invalid command" << endl;
        } catch (...){
            cerr << "Some kind of exception has happened..." << endl;
        }
    }
    cout << "Hello World!" << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"


using namespace std;


int main()
{
    ifstream file_list("../Task_2/movielist.json");
    if(file_list.is_open()){
        cout << "Input actor's name: ";
        string actor_name;
        getline(cin, actor_name);
        nlohmann::json json_movie;
        file_list >> json_movie;
        for(auto movie = json_movie.begin(); movie != json_movie.end(); ++movie){
            for(auto cast = json_movie[movie.key()]["cast"].begin(); cast != json_movie[movie.key()]["cast"].end(); ++cast){
                if(cast.key() == actor_name){
                    cout << endl << "Movie title: " << movie.key() << endl;
                    cout << "Actor name: " << cast.key() << endl;
                    cout << "Actor's role: " << cast.value() << endl;
                }
            }
        }
    }
    return 0;
}

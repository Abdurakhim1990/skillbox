#include <iostream>
#include <filesystem>
#include <string>

using namespace std;

auto recursiveGetFileNamesByExtension = [](std::filesystem::path path, const std::string extension)
{
    filesystem::path p(path);

    return p.extension().compare(extension);
};

int main()
{
    string ext_file = ".txt";
    //string ext_file = ".torrent";
    for(auto& p : filesystem::recursive_directory_iterator("D:\\dir")){
        if(p.is_regular_file())
            if(!recursiveGetFileNamesByExtension(p.path(), ext_file))
                cout << p.path() << endl;
    }
    return 0;
}

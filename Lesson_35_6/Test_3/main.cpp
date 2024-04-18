#include <iostream>
#include <filesystem>

using namespace std;



int main()
{
    filesystem::path p("/home/user/file.txt");
    p.end();
    filesystem::exists(p); // определяет существует ли такой путь
    filesystem::is_regular_file(p); // определяет является ли файлом,а не каталогом
    filesystem::space(p); // определяет свободное пространство на диске и емкость
    filesystem::path ourLink("/home/user/file2.txt");
    filesystem::create_symlink(filesystem::absolute ("/home/user/file.txt"), ourLink); // создать ссылку

    return 0;
}

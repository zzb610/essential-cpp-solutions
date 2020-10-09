// 1. 取消string的引用
// 其实注释掉string头文件的引用此程序依然可以正确编译运行
// 因为iostream已经 隐式地 引用了string
// ostream 用到 ios_base这个类，而它的成员函数 ios_base::getloc 返回一个 std::locale类型, 
// 然后std::locale的成员函数 locale::name 又返回std::string类型，所以就需要string类型的定义。

// 2，注释掉其他using则无法通过编译


#include <iostream>

// #include <string>

using std::cin;
using std::cout;
using std::string;

using namespace std;

int main(int argc, char const *argv[])
{
    string userName;
    cout << "Please enter your first name: ";
    cin >> userName;
    cout << '\n'
         << "Hello, " << userName << "... and goodbye!\n";

    return 0;
}

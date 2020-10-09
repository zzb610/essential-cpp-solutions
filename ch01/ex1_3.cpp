// 修改主函数的名字
// 能通过编译 g++ -c ex1_3.cpp
// 链接时报错 g++ ex1_3.o
// undefined reference to `WinMain'

// Windows窗口程序里，入口就是WinMain，Windows的DLL程序
// 具体的讨论见
// https://www.zhihu.com/question/27695036

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int my_main(int argc, char const *argv[])
{
    string userName;
    cout << "Please enter your first name: ";
    cin >> userName;
    cout << '\n'<<"Hello, " << userName << "... and goodbye!\n";
    
    return 0;
}

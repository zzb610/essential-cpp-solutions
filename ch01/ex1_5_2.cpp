#include <cstring>
#include <iomanip>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main(int argc, char const *argv[])
{
    const int nameSize = 128;
    char userName[nameSize];
    cout << "Please enter your name" << endl;
    cin >> std::setw(nameSize) >> userName;
    switch (strlen(userName))
    {
    case 0:
        cout << "no name" << endl;
        break;
    case 1:
        cout << "1-character name" << endl;
    case 127:
        cout << "big name! It will be shorten" << endl;
    default:
        cout << "hello, " << userName << endl;
        break;
    }
    return 0;
}

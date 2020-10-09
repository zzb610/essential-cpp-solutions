#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    string userName;
    cout << "Please enter your name: ";
    cin >> userName;
    switch (userName.size())
    {
    case 0:
        cout << "no name" << endl;
        break;
    case 1:
        cout << "A 1-character name" << endl;
        break;
    default:
        cout << "hello," << userName << endl;
    }
    return 0;
}

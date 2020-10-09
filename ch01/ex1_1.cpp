#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main(int argc, char const *argv[])
{
    string userName;
    cout << "Please enter your first name: ";
    cin >> userName;
    cout << '\n'<<"Hello, " << userName << "... and goodbye!\n";
    
    return 0;
}

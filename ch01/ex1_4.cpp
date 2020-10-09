#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main(int argc, char const *argv[])
{
    string firstName, lastName;
    cout << "Please enter your first name: ";
    cin >> firstName;
    cout << "Hi, " << firstName << " Please enter your lasr name: ";
    cin >> lastName;
    cout << '\n'<<"Hello, " << firstName << " "<<lastName << "... and goodbye!\n";
    
    return 0;
}

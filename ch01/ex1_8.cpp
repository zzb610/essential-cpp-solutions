#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

const string msgToUser(int numTries)
{
    const int rspCount = 5;
    static const vector<string> usrMsgs{
        "0 try",
        "1 try",
        "2 tries",
        "3 tries",
        "4 tries"};
    if (numTries < 0)
    {
        numTries = 0;
    }
    else
    {
        if (numTries >= rspCount)
        {
            numTries = rspCount - 1;
        }
    }
    return usrMsgs[numTries];
}
int main(int argc, char const *argv[])
{
    cout << msgToUser(0) << endl;
    cout << msgToUser(1) << endl;
    cout << msgToUser(2) << endl;
    cout << msgToUser(3) << endl;
    cout << msgToUser(4) << endl;
    cout << msgToUser(5) << endl;
    return 0;
}

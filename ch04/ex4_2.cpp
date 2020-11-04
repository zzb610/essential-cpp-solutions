#include "stack.h"

#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    Stack st;
    string str;
    while (cin >> str && !st.Full())
    {
        st.Push(str);
    }
    cout << "\n"
         << "Read in" << st.Size() << "strings!\n";
    cin.clear();

    cout << "what word to search for?";
    
    cin >> str;


    bool found = st.Find(str);
    int count = found ? st.Count(str) : 0;
    cout << str << (found ? " is " : "isn\'t") << "in the stack.";
    if (found)
    {
        cout << "It occurs" << count << " times\n";
    }
    return 0;
}

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

    if (st.Empty())
    {
        cout << '\n'
             << "Oops: no strings were read -- bailing out\n";
        return 0;
    }
    st.Peek(str);
    if (st.Size() == 1 && str.empty())
    {
        cout << '\n'
             << "Oops: no strings were read -- bailing out\n";
        return 0;
    }

    cout << '\n'
         << "Read in " << st.Size() << " strings!\n"
         << "The strings, in reverse order: \n";
    while (st.Size())
    {
        if (st.Pop(str))
        {
            cout << str << ' ';
        }
    }
    cout << '\n'
         << "There are now " << st.Size() << " elements in the stack!\n";
    return 0;
}

#include "stack.h"
#include "lifo_stack.h"
#include "peekback_stack.h"

#include <iostream>
#include <string>
using namespace std;

void peek(Stack &st, int index)
{
    cout << endl;
    string t;
    if (st.peek(index, t))
    {
        cout << "peek: " << t;
    }
    else
    {
        cout << "peek failed!";
    }
    cout << endl;
}
ostream &operator<<(ostream &os, Stack &st)
{
    st.print(os);
    return os;
}

int main(int argc, char const *argv[])
{
    LIFOStack st;
    string str;
    while (cin >> str && !st.full())
    {
        st.push(str);
    }
    cout << "\n"
         << "About to call peek() with LIFOStack" << endl;
    peek(st, st.top() - 1);
    cout << st << endl;

    PeekbackStack pst;
    while(!st.empty())
    {
        string t;
        if(st.pop(t))
        {
            pst.push(t);
        }
        cout << "About to call peek() with Peekback_Stack" << endl;
        peek(pst, pst.top() - 1);
        cout << pst;
    }
    return 0;
}

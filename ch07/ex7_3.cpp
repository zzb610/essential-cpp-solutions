#include "stack.h"
#include <iostream>
#include <exception>
#include <string>
using std::logic_error;
using std::string;

class StackException : public logic_error
{
public:
    StackException(const char *what) : logic_error(what)
    {
    }
};
class PopOnEmpty : public StackException
{
public:
    PopOnEmpty() : StackException("Pop On Empty Stack") {}
};
class PushOnFull : public StackException
{
public:
    PushOnFull() : StackException("Push On Full Stack") {}
};

void Stack::print(ostream &os) const
{
    vector<ElemType>::const_reverse_iterator crit = stack_.rbegin(), crend = stack_.rend();
    os << "\n\t";
    while (crit != crend)
    {
        os << *crit++ << "\n\t";
    }
    os << std::endl;
}

bool Stack::pop(ElemType &elem)
{
    if (empty())
    {
        throw PopOnEmpty();
        return false;
    }
    elem = stack_[--top_];
    stack_.pop_back();
    return true;
}
bool Stack::push(const ElemType &elem)
{
    if (full())
    {
        throw PushOnFull();
        return false;
    }
    stack_.push_back(elem);
    ++top_;
    return true;
}
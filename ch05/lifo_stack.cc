#include "lifo_stack.h"

void LIFOStack::print(ostream &os) const
{
    vector<ElemType>::const_reverse_iterator crit = stack_.rbegin(), crend = stack_.rend();
    os << "\n\t";
    while (crit != crend)
    {
        os << *crit++ << "\n\t";
    }
    os << std::endl;
}

bool LIFOStack::pop(ElemType &elem)
{
    if (empty())
    {
        return false;
    }
    elem = stack_[--top_];
    stack_.pop_back();
    return true;
}
bool LIFOStack::push(const ElemType &elem)
{
    if (full())
    {
        return false;
    }
    stack_.push_back(elem);
    ++top_;
    return true;
}
bool LIFOStack::peek(int index, ElemType &elem)
{
    return false;
}
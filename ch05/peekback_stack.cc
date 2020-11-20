#include "peekback_stack.h"

bool PeekbackStack::pop(ElemType &elem)
{
    if (empty())
    {
        return false;
    }
    elem = stack_[--top_];
    stack_.pop_back();
    return true;
}

bool PeekbackStack::push(const ElemType &elem)
{
    if (full())
    {
        return false;
    }
    stack_.push_back(elem);
    ++top_;
    return true;
}

bool PeekbackStack::peek(int index, ElemType &elem)
{
    if (empty())
    {
        return false;
    }

    if (index < 0 && index >= size())
    {
        return false;
    }
    elem = stack_[index];
    return true;
}

void PeekbackStack::print(ostream &os) const
{
    vector<ElemType>::const_reverse_iterator rit = stack_.crbegin(), rend = stack_.crend();
    os << "\n\t";
    while (rit != rend)
    {
        os << *rit++ << "\n\t";
    }
    os << std::endl;
}

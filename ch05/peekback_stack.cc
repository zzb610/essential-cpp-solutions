#include "peekback_stack.h"

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

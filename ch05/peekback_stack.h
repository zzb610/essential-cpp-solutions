#ifndef __PEEKBACK_STACK_H__
#define __PEEKBACK_STACK_H__

#include "stack.h"
#include <vector>
using std::vector;

class PeekbackStack : public Stack
{
public:
    PeekbackStack(int capacity = 0) : Stack(capacity){};

    virtual bool peek(int index, ElemType &elem);
};

#endif // __PEEKBACK_STACK_H__
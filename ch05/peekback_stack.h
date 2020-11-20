#ifndef __PEEKBACK_STACK_H__
#define __PEEKBACK_STACK_H__

#include "stack.h"
#include <vector>
using std::vector;

class PeekbackStack : public Stack
{
public:
    PeekbackStack(int capacity = 0) : top_(0)
    {
        if (capacity)
        {
            stack_.reserve(capacity);
        }
    }
    bool pop(ElemType &elem);
    bool push(const ElemType &elem);
    bool peek(int index, ElemType &elem);

    int top() const { return top_; };
    int size() const { return stack_.size(); };

    bool empty() const { return stack_.empty(); };
    bool full() const { return size() >= stack_.max_size(); };
    void print(ostream &os) const;

private:
    int top_;
    vector<ElemType> stack_;
};

#endif // __PEEKBACK_STACK_H__
#ifndef __LIFO_STACK_H__
#define __LIFO_STACK_H__

#include "stack.h"

#include <vector>
using std::vector;
class LIFOStack : public Stack
{
public:
    LIFOStack(int capacity = 0) : top_(0)
    {
        if (capacity)
        {
            stack_.reserve(capacity);
        }
    }

    int size() const { return stack_.size(); }
    bool empty() const { return !top_; }
    bool full() const { return size() > stack_.max_size(); }
    int top() const { return top_; }

    void print(ostream &os = cout) const;
    bool pop(ElemType &elem);
    bool push(const ElemType &elem);
    bool peek(int index, ElemType &elem);

private:
    vector<ElemType> stack_;
    int top_;
};

#endif // __LIFO_STACK_H__
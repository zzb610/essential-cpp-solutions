#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <string>
using std::cout;
using std::ostream;

typedef std::string ElemType;

class Stack
{
public:
    virtual ~Stack() {}

    virtual bool pop(ElemType &elem) = 0;
    virtual bool push(const ElemType &elem) = 0;
    virtual bool peek(int index, ElemType &elem) = 0;

    virtual int top() = 0;
    virtual int size() = 0;

    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual void print(ostream &os = cout) const = 0;
};

#endif // __STACK_H__
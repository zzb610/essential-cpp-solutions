#include "stack.h"

#include <algorithm>

bool Stack::Push(const string &elem)
{
    if (Full())
    {
        return false;
    }
    stack_.push_back(elem);
    return true;
}
bool Stack::Pop(string &elem)
{
    if (Empty())
    {
        return false;
    }
    elem = stack_.back();
    stack_.pop_back();
    return true;
}
bool Stack::Peek(string &elem) const
{
    if (Empty())
    {
        return false;
    }
    elem = stack_.back();
    return true;
}
bool Stack::Empty() const
{
    return stack_.empty();
}
bool Stack::Full() const
{
    return stack_.size() == stack_.max_size();
}
int Stack::Size() const
{
    return stack_.size();
}

bool Stack::Find(const string &str) const
{
    return std::find(stack_.cbegin(), stack_.cend(), str) == stack_.cend();
}
int Stack::Count(const string &str) const
{
    return std::count(stack_.cbegin(), stack_.cend(), str);
}
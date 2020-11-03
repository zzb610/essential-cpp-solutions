#include <string>
#include <vector>
using std::string;
using std::vector;
class Stack
{
public:
    bool Push(const string &str);
    bool Pop(string &elem);
    bool Peek(string &elem) const;
    bool Empty() const;
    bool Full() const;
    int Size() const;
    bool Find(const string &str) const;
    int Count(const string &str) const;

private:
    vector<string> stack_;
};
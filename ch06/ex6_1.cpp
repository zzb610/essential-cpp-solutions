#include <iostream>

template <typename ValType>
class Example
{
public:
    Example(const ValType &min, const ValType &max);
    Example(const ValType *array, int size);

    ValType &operator[](int index);
    bool operator==(const Example &rhs) const;

    bool insert(const ValType *val, int index);
    bool insert(const ValType &elem);

    ValType min() const { return _min; }
    ValType max() const { return _max; }

    void min(const ValType &);
    void max(const ValType &);

    int count(const ValType &value) const;

private:
    int size;
    ValType *parray;
    ValType _min;
    ValType _max;
};
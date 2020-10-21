#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

bool check_size(int size);

const vector<int> *penta_seq(int size);

bool penta_value(int pos, int &elem);

int main(int argc, char const *argv[])
{
    int elem;
    if (penta_value(0, elem))
    {
        cout << "0# " << elem << endl;
    }
    if (penta_value(8, elem))
    {
        cout << "8# " << elem << endl;
    }
    if (penta_value(64, elem))
    {
        cout << "64# " << elem << endl;
    }
    if (penta_value(12, elem))
    {
        cout << "12# " << elem << endl;
    }
    if (penta_value(9999999, elem))
    {
        cout << "9999999# " << elem << endl;
    }
    return 0;
}

bool check_size(int size)
{
    return (size > 0 && size <= 1024);
}
const vector<int> *penta_seq(int size)
{
    static vector<int> _seq;
    if (check_size(size) && size > _seq.size())
    {
        for (size_t i = _seq.size() + 1; i < size + 1; i++)
        {
            _seq.push_back(i * (3 * i - 1) / 2);
        }
    }
    return &_seq;
}

bool penta_value(int pos, int &elem)
{
    if (!check_size(pos))
    {
        elem = 0;
        return false;
    }
    const vector<int> *p_seq = penta_seq(pos);
    elem = (*p_seq)[pos - 1];
    return true;
}
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool fibon_elem(int, int &);

int main(int argc, char const *argv[])
{
    int pos = 0;
    while (cin >> pos)
    {
        int elem;
        if (fibon_elem(pos, elem))
        {
            cout << "element# " << pos << "is" << elem << endl;
        }
        else
        {
            cout << "sorry" << endl;
        }
    }
    return 0;
}

bool fibon_elem(int pos, int &elem)
{
    if (pos <= 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }

    elem = 1;
    int n1 = 1, n2 = 1;
    for (size_t i = 3; i < pos + 1; i++)
    {
        elem = n1 + n2;
        n1 = n2;
        n2 = elem;
    }
    return true;
}

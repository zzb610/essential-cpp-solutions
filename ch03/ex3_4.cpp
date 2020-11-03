#include <iterator>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

class elem_even
{
public:
    bool operator()(int num)
    {
        return num % 2 == 0 ? true : false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> input;
    istream_iterator<int> in(cin), eof;

    copy(in, eof, back_inserter(input));

    vector<int>::iterator division = stable_partition(input.begin(), input.end(), elem_even());

    ofstream even_file("even.txt"), odd_file("odd.txt");

    ostream_iterator<int> even_iter(even_file, " "), odd_iter(odd_file, "\n");

    copy(input.begin(), division, even_iter);
    copy(division, input.end(), odd_iter);
    return 0;
}

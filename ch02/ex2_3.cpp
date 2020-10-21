#include <iostream>
#include <vector>
#include <ostream>
#include <string>
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;

bool check_size(int size);
bool penta_seq(int size, vector<int> &seq);
void print_vector(const vector<int> &vec, const string &messge, ostream &os = cout);
void really_cal_penta_seq(int size, vector<int> &seq);

int main(int argc, char const *argv[])
{
    vector<int> pent;
    const string title("PNS");
    if (penta_seq(0, pent))
    {
        print_vector(pent, title);
    }
    if (penta_seq(8, pent))
    {
        print_vector(pent, title);
    }
    if (penta_seq(14, pent))
    {
        print_vector(pent, title);
    }
    if (penta_seq(10000, pent))
    {
        print_vector(pent, title);
    }
    return 0;
}

inline bool penta_seq(int size, vector<int> &seq)
{
    if (size <= 0 || size > 1024)
    {
        return false;
    }

    if (seq.size() < size)
    {
        really_cal_penta_seq(size, seq);
    }
    return true;
}

void really_cal_penta_seq(int size, vector<int> &seq)
{
    for (size_t i = 1; i <= size; i++)
    {
        seq.push_back(i * (3 * i - 1) / 2);
    }
}
void print_vector(const vector<int> &vec, const string &message, ostream &os)
{
    os << message << endl;
    for (size_t i = 0, len = vec.size(); i < len; i++)
    {
        os << vec[i] << " ";
    }
    os << endl;
}
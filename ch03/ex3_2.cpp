#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class LessThan;

template <typename Iterator>
void display_container(Iterator first, Iterator last, ostream &out = cout);

class LessThan
{
public:
    bool operator()(const string &s1, const string &s2)
    {
        return s1.size() < s2.size();
    }
};

int main(int argc, char const *argv[])
{
    ifstream ifile("in.txt");
    ofstream ofile("out.txt");
    if (!ifile || !ofile)
    {
        cerr << "Un able to open file -- bailing out!\n"
             << endl;
        return -1;
    }

    vector<string> text;
    string word;
    while (ifile >> word)
    {
        text.push_back(word);
    }

    sort(text.begin(), text.end(), LessThan());

    display_container(text.begin(), text.end(), cout);
    return 0;
}

template <typename Iterator>
void display_container(Iterator first, Iterator last, ostream &out)
{
    for (auto it = first; it != last; ++it)
    {
        out << *it << " ";
    }
    out << endl;
}

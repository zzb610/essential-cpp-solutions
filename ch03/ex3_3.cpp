#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
using vstring = vector<string>;

// load data from files
void PopulateMap(ifstream &name_file, map<string, vstring> &families);

// print map
void DisplayMap(const map<string, vstring> &families, ostream &os);

// query
void QueryMap(const string &family, const map<string, vstring> &families);

int main(int argc, char const *argv[])
{
    map<string, vstring> families;
    ifstream name_file("families.txt");
    if (!name_file)
    {
        cerr << "Unable to find families.txt fille. bailing out!\n";
        return -1;
    }
    PopulateMap(name_file, families);
    string family_name;
    while (cin >> family_name && family_name != "q" && family_name != "Q")
    {
        QueryMap(family_name, families);
    }
    DisplayMap(families, cout);
    return 0;
}

// load data from files
void PopulateMap(ifstream &name_file, map<string, vstring> &families)
{
    string text_line;
    while (getline(name_file, text_line))
    {
        string family_name;
        vstring child;
        string::size_type pos = 0, prev_pos = 0;
        string::size_type text_size = text_line.size();
        char delima = ' ';
        while ((pos = text_line.find_first_of(delima, pos)) != string::npos)
        {
            // end of word
            string::size_type end_pos = pos - prev_pos;

            // first word
            if (!prev_pos)
            {
                family_name = text_line.substr(prev_pos, end_pos);
            }
            else
            {
                child.push_back(text_line.substr(prev_pos, end_pos));
            }
            ++pos;
            prev_pos = pos;
        }
        // last word
        if (prev_pos < text_size)
        {
            child.push_back(text_line.substr(prev_pos, pos - prev_pos));
        }
        if (!families.count(family_name))
        {
            families[family_name] = child;
        }
        else
        {
            cerr << "Ops! We already have a" << family_name << "in our map\n";
        }
    }
}

void DisplayMap(const map<string, vstring> &families, ostream &os)
{
    for (auto kv : families)
    {
        os << "***family:" << kv.first << "***" << endl;
        for (auto v : kv.second)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

#include <algorithm>
void QueryMap(const string &family, const map<string, vstring> &families)
{
    auto it = families.find(family);
    if (it != families.end())
    {
        for (auto name : it->second)
        {
            cout << name << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "not found!" << endl;
    }
}

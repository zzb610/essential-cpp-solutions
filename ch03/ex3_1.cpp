#include <set>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <iterator>
using namespace std;

void initialize_exclusion_set(set<string> &excude_set);
void process_file(map<string, int> &word_cnt, const set<string> &exclude_set, ifstream &ifile);
void user_query(const map<string, int> &word_cnt);
void display_word_count(const map<string, int> &word_cnt, ofstream &ofile);

int main()
{

    ifstream ifile("C:\\Users\\bwyuc\\projects\\essential-cpp-solutions\\ch03\\in.txt");
    ofstream ofile("C:\\Users\\bwyuc\\projects\\essential-cpp-solutions\\ch03\\out.txt");

    if (!ifile || !ofile)
    {
        cerr << "Unable to open file -- bailiing out!\n";
        return -1;
    }

    set<string> exclude_set;
    initialize_exclusion_set(exclude_set);

    map<string, int> word_count;
    process_file(word_count, exclude_set, ifile);

    user_query(word_count);
    display_word_count(word_count, ofile);
}

void initialize_exclusion_set(set<string> &exclude_set)
{
    ifstream exclude_word_file("./exclude_word.txt");
    istream_iterator<string> is(exclude_word_file);
    istream_iterator<string> eof;
    copy(is, eof, inserter(exclude_set, exclude_set.begin()));
}

void process_file(map<string, int> &word_cnt, const set<string> &exclude_set, ifstream &ifile)
{
    string word;
    while (ifile >> word)
    {
        if (exclude_set.find(word) == exclude_set.end())
        {
            ++word_cnt[word];
        }
    }
}

void user_query(const map<string, int> &word_cnt)
{
    string message;
    while (cin >> message && message != "q" && message != "Q")
    {
        auto it = word_cnt.find(message);
        if (it == word_cnt.end())
        {
            cout << "not found!" << endl;
        }
        else
        {
            cout << message << ":" << it->second << endl;
        }
    }
}

void display_word_count(const map<string, int> &word_cnt, ofstream &ofile)
{
    for (auto it : word_cnt)
    {
        ofile << it.first << ":" << it.second << endl;
    }
}

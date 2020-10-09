#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::sort;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    ifstream inFile("./input.txt");
    if (!inFile)
    {
        cerr << "can't open input file " << endl;
        return -1;
    }
    ofstream outFile("./output.txt");
    if (!outFile)
    {
        cerr << "can't open output file" << endl;
        return -2;
    }

    vector<string> content;
    string tempStr;
    while (inFile >> tempStr)
    {
        content.push_back(tempStr);
    }
    for (const auto &str : content)
    {
        cout << str << " ";
    }
    cout << endl;
    sort(content.begin(), content.end());
    for (const auto &str : content)
    {
        outFile << str << " ";
    }
    cout << endl;
    return 0;
}

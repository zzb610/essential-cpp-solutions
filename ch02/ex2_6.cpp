#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::max_element;
using std::string;
using std::vector;

template <typename T>
inline T max(T t1, T t2);

template <typename T>
inline T max(const vector<T> &vec);

template <typename T>
inline T max(T arr[], int size);

string max(const string &s1, const string &s2)
{
    return s1 > s2 ? s1 : s2;
}

int main(int argc, char const *argv[])
{
    string sarray[] = {"we", "were", "her", "pride", "of", "ten"};
    vector<string> svec(sarray, sarray + 6);

    int iarray[] = {12, 70, 2, 169, 1, 5, 29};
    vector<int> ivec(iarray, iarray + 7);

    float farray[] = {2.5, 24.8, 18.7, 4.1, 23.9};
    vector<float> fvec(farray, farray + 5);

    int imax = max(max(ivec), max(iarray, 7));
    float fmax = max(max(fvec), max(farray, 5));

    string smax = max(max(svec), max(sarray, 6));

    cout << imax << endl;
    cout << fmax << endl;
    cout << smax << endl;
    return 0;
}

template <typename T>
T max(T t1, T t2)
{
    return t1 > t2 ? t1 : t2;
}

template <typename T>
T max(const vector<T> &vec)
{
    return *std::max_element(vec.begin(), vec.end());
}

template <typename T>
T max(T arr[], int size)
{
    return *std::max_element(arr, arr + size);
}
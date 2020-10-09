#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main(int argc, char const *argv[])
{
    const int maxSize = 128;
    int nums[maxSize];
    int tempNum;
    int i = 0;
    cout << "Please enter your numbers" << endl;
    while (cin >> tempNum)
    {
        nums[i++] = tempNum;
    }
    int sum = 0;
    for (size_t ix = 0; ix < i; ix++)
    {
        sum += nums[ix];
    }
    double avg = (double)sum / i;
    cout << "Sum=" << sum << ",Avg=" << avg << endl;
    return 0;
}

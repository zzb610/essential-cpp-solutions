#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(int argc, char const *argv[])
{
    cout << "Please enter your numbers" << endl;
    vector<int> nums;
    int tempValue;
    while (cin >> tempValue)
    {
        nums.push_back(tempValue);
    }
    int sum = 0;
    for (auto num : nums)
    {
        sum += num;
    }
    double avg = (double)sum / nums.size();
    cout << "Sum=" << sum << ",Avg=" << avg << endl;
    return 0;
}

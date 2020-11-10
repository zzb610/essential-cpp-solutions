#include "user_profile.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    UserProfile anon;
    cout << anon << endl;

    UserProfile anon_too;
    cout << anon_too << endl;

    UserProfile anna("AnnaL", UserProfile::Guru);
    cout << anna << endl;

    anna.bump_guess_count(27);
    anna.bump_guess_correct(25);
    anna.bump_login_count();

    cout << anna << endl;

    cin >> anon;
    cout << anon << endl;

    return 0;
}
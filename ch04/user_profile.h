#ifndef __USER_PROFILE_H__
#define __USER_PROFILE_H__

#include <string>
#include <map>
#include <iostream>
using std::istream;
using std::map;
using std::ostream;
using std::string;

class UserProfile;

ostream &operator<<(ostream &os, const UserProfile &ths);
istream &operator>>(istream &is, UserProfile &rhs);

class UserProfile
{
public:
    enum kUserLevel
    {
        Beginner,
        Intermediate,
        Advanced,
        Guru
    };

    // ctor
    UserProfile();
    UserProfile(const string &login, kUserLevel user_level = Beginner);

    // operator == !=
    bool operator==(const UserProfile &rhs) const;
    bool operator!=(const UserProfile &rhs) const;

    // getter
    string login() const { return login_; };
    string user_name() const { return user_name_; };
    int time_logged() const { return time_logged_; };
    int guesses() const { return guesses_; };
    int correct_guesses() const { return correct_guesses_; };

    double guess_average() const;
    string level() const;

    // setter
    void login(const string &nl) { login_ = nl; };
    void user_name(const string &nun) { user_name_ = nun; };
    void time_logged(int ntl) { time_logged_ = ntl; };
    void guesses(int ng) { guesses_ = ng; };
    void correct_guesses(int ncg) { correct_guesses_ = ncg; };

    void user_level(kUserLevel nl) { user_level_ = nl; }

    void reset_level(const string &nl);

    // bump data
    void bump_login_count(int cnt = 1) { time_logged_ += cnt; }
    void bump_guess_count(int cnt = 1) { guesses_ += cnt; }
    void bump_guess_correct(int cnt = 1) { correct_guesses_ += cnt; }

private:
    string login_;
    string user_name_;
    int time_logged_;
    int guesses_;
    int correct_guesses_;
    kUserLevel user_level_;

    static map<string, kUserLevel> level_map_;
    static void init_level_map();
    static string guest_login();

    friend ostream &operator<<(ostream &os, const UserProfile &ths);
    friend istream &operator>>(istream &is, UserProfile &rhs);
};
#endif // __USER_PROFILE_H__
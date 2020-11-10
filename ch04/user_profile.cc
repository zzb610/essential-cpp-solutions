#include "user_profile.h"

#include <vector>
using std::vector;

// ctor
UserProfile::UserProfile(const string &login, kUserLevel user_level) : login_(login), user_level_(user_level), time_logged_(1), guesses_(0), correct_guesses_(0) {}

// #include <cstdlib>
UserProfile::UserProfile() : login_("guest"), user_level_(Beginner), time_logged_(1), guesses_(0), correct_guesses_(0)
{
    static int id = 0;

    string buffer(std::to_string(id++));
    // for guests add a unique buffer
    login_ += buffer;
}

// operator == !=
inline bool UserProfile::operator==(const UserProfile &rhs) const
{
    return (login_ == rhs.login_) && (user_name_ == rhs.user_name_);
}
bool UserProfile::operator!=(const UserProfile &rhs) const
{
    return !(*this == rhs);
}

inline double UserProfile::guess_average() const
{
    if (guesses_)
    {
        return double(correct_guesses_) / double(guesses_) * 100;
    }
    return 0.0;
}

inline string UserProfile::level() const
{
    static vector<string> level_table{"Beginner", "Intermediate", "Advanced", "Guru"};
    return level_table[user_level_];
}

map<string, UserProfile::kUserLevel> UserProfile::level_map_;

inline void UserProfile::init_level_map()
{
    level_map_["Beginner"] = Beginner;
    level_map_["Intermediate"] = Intermediate;
    level_map_["Advanced"] = Advanced;
    level_map_["Curu"] = Guru;
}

inline void UserProfile::reset_level(const string &nl)
{
    map<string, kUserLevel>::iterator it;
    if (level_map_.empty())
    {
        init_level_map();
    }
    it = level_map_.find(nl);
    if (it == level_map_.end())
    {
        user_level_ = Beginner;
    }
    else
    {

        user_level_ = it->second;
    }
}

ostream &operator<<(ostream &os, const UserProfile &rhs)
{
    os << rhs.login() << ' '
       << rhs.level() << ' '
       << rhs.time_logged() << ' '
       << rhs.guesses() << ' '
       << rhs.correct_guesses() << ' '
       << rhs.guess_average();
    return os;
}
istream &operator>>(istream &is, UserProfile &rhs)
{
    string login, level;
    is >> login >> level;

    int lcount, gcount, gcorrect;
    is >> lcount >> gcount >> gcorrect;
    rhs.login(login);
    rhs.reset_level(level);
    rhs.time_logged(lcount);
    rhs.guesses(gcount);
    rhs.correct_guesses(gcorrect);
    return is;
}

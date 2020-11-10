#ifndef GLOBAL_WRAPPER_H
#define GLOBAL_WRAAPER_H
#include <string>
using std::string;
class GlobalWrapper
{
public:
    static string program_name() { return program_name_; }
    static string version_stamp() { return version_stamp_; }
    static int version_number() { return version_number_; }
    static int test_run() { return test_run_; }
    static int test_passed() { return test_passed_; }
    
    static void program_name(const string &npn) { program_name_ = npn; }
    static void version_stamp(const string &nvs) { version_stamp_ = nvs; }
    static void version_number(int nvs) { version_number_ = nvs; }
    static void test_run(int ntr) { test_run_ = ntr; }
    static void test_passed(int ntp) { test_passed_ = ntp; }

private:
    static string program_name_;
    static string version_stamp_;
    static int version_number_;
    static int test_run_;
    static int test_passed_;
};
#endif // GLOBAL_WRAAPER_H
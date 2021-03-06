#include <fstream>
#include <string>
#include <iostream>
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;
int *allocate_array(int elem_cnt);
void sort_array(int *pi, int elem_cnt);
void register_data(int *pi);

int *alloc_and_init(string file_name)
{
    // 类型不符 ifstream 接受的参数类型是const char
    // ifstream infile(file_name);
    ifstream infile(file_name.c_str());

    // 文件有可能打开失败
    if(!infile)
    {
        cerr << "fail to open file " << file_name << endl;
        return 0;
    }
    int elem_cnt;
    infile >> elem_cnt;
    if(!infile)
    {
        cerr << "fail to write !" << endl;
        return 0;
    }
    int *pi = allocate_array(elem_cnt);

    if(!pi)
    {
        cerr << "fail to allocate" << endl;
        return 0;
    }
    int elem;
    int index = 0;
    while (infile >> elem)
    {
        pi[index++] = elem;
    }

    sort_array(pi, elem_cnt);
    register_data(pi);
    return pi;
}
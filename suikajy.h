//
// Created by admin on 2018/7/27.
//

#ifndef CPPNOTE_SUIKAJY_H
#define CPPNOTE_SUIKAJY_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <list>
#include <iomanip>
#include <fstream>

using namespace std;//没有这行就不能直接写cout而是要写std::cout

//抛出异常函数
void error(string msg);

//void error(string msg, string param);

//类型强转函数
template<typename R, typename A>
R narrow_cast(const A &a) {
    R r = R(a);
    if (A(r) != a) error(string("info loss"));
    return r;
}

void keep_window_open();

void keep_window_open(string s);

//打印向量, g++不支持模板函数的分离编译，所以有模板的函数最好在头文件写。
template<typename T>
void print_r(const vector<T> &v) {
    cout << "Vector : {" << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << "\t" << i << " => " << v[i] << endl;
    }
    cout << "}" << endl;
};

#endif //CPPNOTE_SUIKAJY_H

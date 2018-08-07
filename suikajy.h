//
// Created by admin on 2018/7/27.
//

#ifndef CPPNOTE_SUIKAJY_H
#define CPPNOTE_SUIKAJY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;//没有这行就不能直接写cout而是要写std::cout

//抛出异常函数
void error(string msg);

void error(string msg, string param);

//类型强转函数
template<typename R, typename A>
R narrow_cast(const A &a);

void keep_window_open();

void keep_window_open(string s);

#endif //CPPNOTE_SUIKAJY_H

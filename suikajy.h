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

//类型强转函数
template<typename R, typename A>
R narrow_cast(const A &a);

#endif //CPPNOTE_SUIKAJY_H

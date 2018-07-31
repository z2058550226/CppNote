//
// Created by admin on 2018/7/30.
//

#include "suikajy.h"

void error(string msg) {
    throw runtime_error(msg);
}

template<typename R, typename A>
R narrow_cast(const A &a) {
    R r = R(a);
    if (A(r) != a) error(string("info loss"));
    return r;
}

void keep_window_open() {
    getchar();
};

//
// Created by admin on 2018/8/1.
//

#ifndef CPPNOTE_VARIABLE_H
#define CPPNOTE_VARIABLE_H

#include "../suikajy.h"

class Variable {
public:
    string name;
    double value;

    explicit Variable(string n, double v) : name(n), value(v) {}
};

#endif //CPPNOTE_VARIABLE_H

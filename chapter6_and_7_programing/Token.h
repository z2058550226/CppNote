//
// Created by admin on 2018/7/31.
//

#ifndef CPPNOTE_TOKEN_H
#define CPPNOTE_TOKEN_H

#include "../suikajy.h"

class Token {
public:
    char kind;
    double value;
    string name;

    // 用冒号初始化成员变量叫成员初始化列表
    explicit Token(char ch) : kind(ch), value(0) {};

    Token(char ch, double val) : kind(ch), value(val) {};

    Token(char ch, string name) : kind(ch), name(name) {};
};

//Token get_token(); // function to read a token from cin

#endif //CPPNOTE_TOKEN_H

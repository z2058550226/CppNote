//
// Created by admin on 2018/7/31.
//

#ifndef CPPNOTE_TOKEN_STREAM_H
#define CPPNOTE_TOKEN_STREAM_H

#include "Token.h"

// 定义与实现分离，避免和类定义混在一起分散注意。
class Token_stream {
public:
    Token_stream();

    Token get();

    void putback(Token t);

private:
    bool full; // is there a Token in the buffer?
    Token buffer; // here is where we keep a Token put back using putback()
};

#endif //CPPNOTE_TOKEN_STREAM_H

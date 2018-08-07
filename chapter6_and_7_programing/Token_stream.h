//
// Created by admin on 2018/7/31.
//

#ifndef CPPNOTE_TOKEN_STREAM_H
#define CPPNOTE_TOKEN_STREAM_H

#include "Token.h"
#include "CalConfig.h"

// 定义与实现分离，避免和类定义混在一起分散注意。
class Token_stream {
public:
    // make a Token_stream that reads from cin
    Token_stream();
    // 取token
    Token get();
    // 缓存token
    void putback(Token t);
    // discard characters up to and including a c
    void ignore(char c);

private:
    bool full; // is there a Token in the buffer?
    Token buffer; // here is where we keep a Token put back using putback()
};

#endif //CPPNOTE_TOKEN_STREAM_H

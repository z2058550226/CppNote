//
// Created by admin on 2018/7/31.
//

#include "Token_stream.h"

// 用哑单词（dummy token）初始化默认值
Token_stream::Token_stream() : full(false), buffer(0) {

}

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch; // note that >> sikps whitespace(space, newline, tab, etc.)

    switch (ch) {
        case print: // for "print"
        case quit: // for "quit"
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case result:
            return Token(ch);//let each character represent itself
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
            // 如果是数字开头，就将这个字符放回输入流，然后再用一个double类型读取
            cin.putback(ch); // put digit back into the input stream
            double val;
            // 输入流能够识别C++文字常量，并能将其转换为double类型的数值
            // 所以这里不用考虑科学计数法(如12.34e5)这种输入，输入流会处理
            cin >> val; // read a floating-point number
            return Token('8', val); // let '8' represent "a number"
        }
        default:
            if (isalpha(ch)) {//检查ch是否是英文字母
                string s;
                s += ch;
                //输入流cin的get和>>的作用类似，只读一个字符，但不会根据空格停止。
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))s += ch;
                cin.putback(ch);
                if (s == declkey) return Token(let);// declaration keyword
                return Token(name, s);
            }
            error("Bad token");
    }

}

void Token_stream::putback(Token t) {
    if (full) error("putback() into a full buffer");
    buffer = t;
    full = true;
}

// c represents the kind of Token
void Token_stream::ignore(char c) {
    // first look in buffer:
    if (full && c == buffer.kind) {
        full = false;
        return;
    }

    full = false;

    // now search input:

    char ch = 0;
    while (cin >> ch)
        if (ch == c) return;
}

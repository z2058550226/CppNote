//
// Created by admin on 2018/7/30.
// 面向对线
//

#include "../suikajy.h"
#include "Token_stream.h"

Token_stream ts;

double primary();

double term();

double expression();

int main() {
    double val = 0;
    while (cin) {
        Token t = ts.get();
        if (t.kind == 'q')break;
        if (t.kind == ';')
            cout << "=" << val << endl;
        else
            ts.putback(t);
        val = expression();
    }

    keep_window_open();
}

double expression() {
    double left = term();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

double term() {
    double left = primary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/': {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '(': {
            double d = expression();
            t = ts.get();
            if (t.kind != ')')error("')'expected");
            return d;
        }
        case '8':
            return t.value;
        default:
            error("primary expected");
    }
}
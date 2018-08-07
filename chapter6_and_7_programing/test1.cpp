//
// Created by admin on 2018/7/30.
// 面向对线
//

#include "../suikajy.h"
#include "Token_stream.h"
#include "Variable.h"

Token_stream ts;

vector<Variable> var_table;

double primary();

double term();

double expression();

// return the value of the Variable named s
double get_value(string s);

// set the Variable named s to d
void set_value(string s, double d);

// 语句
double statement();

// 计算，主函数用
void calculate();

// 声明变量
double declaration();

// clear
void clean_up_mess();

// is var already in var_table?
bool is_declared(string var);

// add (var, val) to var_table
double define_name(string var, double val);

int main() {
    try {
        // predefine names;
        define_name("pi", 3.1415926535);
        define_name("e", 2.7182818284);

        calculate();
        keep_window_open();
        return 0;
    } catch (runtime_error &e) {
        cerr << e.what() << endl;
        keep_window_open("~~");
        return 1;
    } catch (...) {
        cerr << "exception \n";
        keep_window_open("~~");
        return 2;
    }
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
            case '%': {
                double d = term();
                auto i1 = int(left);
                if (i1 != left)error("left-hand operand of % not int");
                auto i2 = int(d);
                if (i2 != d)error("right-hand operand of % not int");
                if (i2 == 0)error("%: divide by zero");
                left = i1 % i2;
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
        case '-':
            return -primary();
        case '+':
            return primary();
        default:
            if (is_declared(t.name)) {
                return get_value(t.name);
            }
            error("primary expected");
    }
}

double get_value(string s) {
    for (int i = 0; i < var_table.size(); ++i) {
        if (var_table[i].name == s)return var_table[i].value;
    }
    error("get:undefined variable", s);
}

void set_value(string s, double d) {
    for (int i = 0; i < var_table.size(); ++i) {
        if (var_table[i].name == s) {
            var_table[i].value = d;
            return;
        }
    }
    error("set: undefined variable", s);
}

double statement() {
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

void calculate() {
    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get(); // first discard all "print"
            if (t.kind == quit) return;
            ts.putback(t);
            cout << result << statement() << endl;
        } catch (exception &e) {
            cerr << e.what() << endl;
            clean_up_mess();
        }
    }
};

bool is_declared(string var) {
    for (int i = 0; i < var_table.size(); ++i) {
        if (var_table[i].name == var) {
            return true;
        }
    }
    return false;
}

double define_name(string var, double val) {
    if (is_declared(var)) error(var, "declared twice");
    var_table.push_back(Variable(var, val));
    return val;
}

double declaration() {
    Token t = ts.get();
    if (t.kind != name) {
        error("name expected in declaration");
    }
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=')error("= missing in declaration of ", var_name);

    double d = expression();
    define_name(var_name, d);
    return d;
}

void clean_up_mess() {
    ts.ignore(print);
}


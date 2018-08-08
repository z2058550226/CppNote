//
// Created by admin on 2018/7/30.
//

#include "suikajy.h"

void error(string msg) {
    throw runtime_error(msg);
}

//void error(string msg, string param) {
//    string error_msg = msg + ": " + param;
//    throw runtime_error(error_msg);
//}

void keep_window_open() {
    cin.clear();
    cout << "Please enter a character to exit\n";
    char ch;
    cin >> ch;
    return;
}

void keep_window_open(string s) {
    if (s == "") return;
    cin.clear();
    cin.ignore(120, '\n');
    for (;;) {
        cout << "Please enter " << s << " to exit\n";
        string ss;
        while (cin >> ss && ss != s)
            cout << "Please enter " << s << " to exit\n";
        return;
    }
}


//
// Created by admin on 2018/8/8.
//

#ifndef CPPNOTE_READ_ONE_VAL_H
#define CPPNOTE_READ_ONE_VAL_H


#include "../suikajy.h"

void skip_to_int() {
    if (cin.fail()) { // we found something that wasn't an integer
        cin.clear(); // we'd like to look at the characters
        char ch;

        while (cin >> ch) { // throw away non-digits
            if (isdigit(ch)) {
                cin.unget(); // put the digit back,
                // so that we can read the number
                return;
            }
        }
    }
    error("no input"); // eof or bad: give up
}

// 不断读取用户输入Demo
int read_one_val() {
    cout << "Please enter an integer in the range 1 to 10 (inclusive):\n";
    int n = 0;
    while (true) {
        cin >> n;
        if (cin) { // we got an integer; now check it
            if (1 <= n && n <= 10)break;
            cout << "Sorry"
                 << n << "is not in the [1:10] range; please try again\n";
        } else {
            cout << "Sorry, that was not a number; please try again\n";
            skip_to_int();
        }
    }
    return 0;
}

#endif //CPPNOTE_READ_ONE_VAL_H

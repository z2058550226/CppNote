//
// Created by admin on 2018/7/30.
// 输入错误
//

#include "../suikajy.h"

double some_function() {
    cout << "in fun" << endl;
    double d = 0;
    cin >> d;
    if (!cin)error("couldn't read a double in 'some_function()'");
    // do something useful
}

int main() {
    try {
        some_function();
        return 0;
    } catch (runtime_error &e) {
        cerr << "runtime error: " << e.what() << endl;
        return 1;
    }
}
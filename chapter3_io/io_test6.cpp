//
// Created by admin on 2018/7/27.
//

#include <iostream>

int main() {
    int a = 20000;
    char c = a;
    int b = c;
    if (a != b)
        std::cout << "oops!:" << a << "!=" << b << '\n';
    else
        std::cout<<"Wow! We have large characters\n";
}

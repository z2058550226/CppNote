//
// Created by admin on 2018/7/27.
// 字符串比较操作符
//

#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "Please enter two names\n";
    std::string first;
    std::string second;
    std::cin >> first >> second; // read two string
    // c++的字符串比较用==就可以，这是一个重载的操作符，不像java中==是一个对象指针比较
    if (first == second) std::cout << "that's the same name twice\n";
    if (first < second)
        std::cout << first << " is alphabetically before" << second << '\n';
    if (first > second)
        std::cout << first << " is alphabetically after" << second << '\n';
    return 0;
}
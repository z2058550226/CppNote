//
// Created by admin on 2018/7/27.
//

#include <iostream>

int main() {
    std::cout << "Please enter your first and second names\n";
    std::string first;
    std::string second;
    std::cin >> first >> second;// read two strings;
    std::cout << "Hello," << first << ' ' << second << '\n';
    return 0;
}
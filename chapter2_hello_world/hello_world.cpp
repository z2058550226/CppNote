//
// Created by admin on 2018/7/25.
//

#include <iostream>

int main() {
    std::cout << "Please enter yout first name (followed by 'enter'):\n";
    std::string first_name;
    std::cin >> first_name;
    first_name = first_name + " sir";
    bool tap_on = true;
    if (tap_on) {
        std::cout << "Hello " << first_name << std::endl;
    }

    return 0;
}
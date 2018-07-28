//
// Created by admin on 2018/7/26.
//

#include <iostream>

int main() {
    std::cout << "Please enter your first name and age\n";
    std::string first_name;
    int age;
    std::cin >> first_name;
    std::cin >> age;
    std::cout << "Hello, " << first_name << "(age" << age << ")\n";

    return 0;
}


//
// Created by admin on 2018/7/27.
//

#include <iostream>

int main(int argc, char *argv[]) {
    std::string previous = " ";
    std::string current;
    while (std::cin >> current) { // 按ctrl+D即可结束程序
        if (previous == current)
            std::cout << "repeated word:" << current << '\n';
        previous = current;
    }

    return 0;
}
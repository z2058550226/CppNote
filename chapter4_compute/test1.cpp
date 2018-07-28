//
// Created by admin on 2018/7/27.
//


#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<int> v(6);
    v[0] = 5;
    v[1] = 7;
    v[2] = 9;
    v[3] = 4;
    v[4] = 5;
    v[5] = 8;

    std::cout << v[2] << std::endl;
    return 0;
}
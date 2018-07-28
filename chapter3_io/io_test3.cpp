//
// Created by admin on 2018/7/27.
//

#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {
    std::cout << "Please enter floating-point value:";
    double n;
    std::cin >> n;
    std::cout << "n == " << n
              << "\nn+1 == " << n + 1
              << "\nthree times n == " << 3 * n
              << "\nn squared == " << n * n
              << "\nhalf of n == " << n / 2
              << "\nsquare root of n == " << sqrt(n)
              << std::endl;
    return 0;
}

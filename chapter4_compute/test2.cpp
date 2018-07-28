//
// Created by admin on 2018/7/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
    std::vector<double> temps;
    double temp;
    while (std::cin >> temp) {
        temps.push_back(temp);
    }

    double sum = 0;
    for (int i = 0; i < temps.size(); ++i) {
        sum += temps[i];
    }
    std::cout << "Average temperature:" << sum / temps.size() << std::endl;

    std::sort(temps.begin(), temps.end());
    std::cout << "Median temperature:" << temps[temps.size() / 2] << std::endl;
    return 0;
}

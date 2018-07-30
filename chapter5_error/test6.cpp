//
// Created by admin on 2018/7/30.
//

#include "../suikajy.h"

double ctok(double c) {
    double k = c + 273.15;
    return k;
}

int main(int argc, char *argv[]) {
    double c = 0;
    cin >> c;
    double k = ctok(c);
    cout << k << endl;
    return 0;
}
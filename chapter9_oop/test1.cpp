//
// Created by admin on 2018/8/6.
//

#include "../suikajy.h"
#include "Date.h"

#define Month Date::Month

//操作符重载
Month operator++(Month &m) {
    m = (m == Month::dec) ? Month::jan : Month(m + 1);
    return m;
}

vector<string> month_tbl;

ostream &operator<<(ostream &os, Month m) {
    return os << month_tbl[m];
}

int main(int argc, char *argv[]) {
    cout << 0 << endl;
    Month m = Month::jan;
    cout << 1 << endl;
    ++m;
    int a = m;
    cout << 2 << endl;
    cout << a << endl;// 2
//    Month m2 = Month::dec;
//    cout << ++m2 << endl;
    cout << Year::max << endl;

    Date date1(Year(2000), Month::jan, 1);
    Date date2(Year(2000), Month::jan, 1);

    cout << (date1 == date2) << endl;// 1
    return 0;
}


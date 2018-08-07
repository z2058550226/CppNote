//
// Created by admin on 2018/8/7.
//

#ifndef CPPNOTE_DATE_H
#define CPPNOTE_DATE_H

#include "Year.h"

class Date {
public:
    enum Month {
        jan = 1, feb, mar, apr,
        may, jun, jul, aug,
        sep, oct, nov, dec
    };


    Date(Year year, Month mon, int day) : y(year), m(mon), d(day) {};

    // const 成员函数不能修改当前对象的属性，这可以保证对象的可变性。
    int day() const {
//        ++this->d; // error: attempt to change object from const member function.
        return d;
    }


    Month month() const;

    int year() const;

    // 重载==操作符相当于java中重写Object中的equals方法，注意要同时重载!=操作符
    bool operator==(const Date &b) {
        return this->d == b.d && this->m == b.m && this->y.year() == b.y.year();
    }

    // 注意这里是用成员函数来重载操作符，所以要考虑到隐藏参数this指针
    bool operator!=(const Date &b) {
        return !(*this == b);
    }

private:
    Year y;
    Month m;
    int d;
};


#endif //CPPNOTE_DATE_H

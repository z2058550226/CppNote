//
// Created by admin on 2018/8/7.
//

#ifndef CPPNOTE_CHRONO_H
#define CPPNOTE_CHRONO_H

#include "../suikajy.h"

namespace Chrono {

    class Date {
    public:
        enum Month {
            jan = 1, feb, mar, apr, may, jun,
            jul, aug, sep, oct, nov, dec
        };

        // to throw as exception
        class Invalid {
        };

        Date(int y, Month m, int d); // check for valid date and initialize
        Date(); //default constructor
        // the default copy operations are fine

        // non-modifying operations:
        int day() const { return this->d; }

        Month month() const { return this->m; }

        int year() const { return this->y; }

        // modifying operations:
        void add_day(int n);

        void add_month(int n);

        void add_year(int n);

    private:
        int y;
        Month m;
        int d;
    };

    bool is_date(int y, Date::Month m, int d); // true for valid date

    bool leap_year(int y); // true is the leap year

    bool operator==(const Date &a, const Date &b);// 相当于java的equals函数

    bool operator!=(const Date &a, const Date &b);

    ostream &operator<<(ostream &os, const Date &d);// 类似于java的toString函数

    istream &operator>>(istream &is, const Date &d);
}

#endif //CPPNOTE_CHRONO_H

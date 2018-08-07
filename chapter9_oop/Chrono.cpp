//
// Created by admin on 2018/8/7.
//

#include "Chrono.h"

namespace Chrono {

    Date::Date(int yy, Chrono::Date::Month mm, int dd)
            : y(yy), m(mm), d(dd) {
        if (!is_date(yy, mm, dd))throw Invalid();
    }

    Date &default_date() {
        // static 修饰保证只初始一次，并且只能被default_date()函数使用
        static Date dd(2001, Date::jan, 1);
        return dd;
    }

    Date::Date() : y(default_date().year()),
                   m(default_date().month()),
                   d(default_date().day()) {

    }


    void Date::add_day(int n) {
        // ...
    }

    void Date::add_month(int n) {
        // ...
    }

    void Date::add_year(int n) {
        // 闰年加一年等于
        if (m == feb && d == 29 && !leap_year(y + n)) {
            m = mar;
            d = 1;
        }
        y += n;
    }

    // helper functions:

    bool is_date(int y, Date::Month m, int d) {
        // assume that y is valid

        if (d <= 0) return false; // d must be positive

        int days_in_month = 31; // most months have 31 days

        switch (m) {
            case Date::feb:
                days_in_month = (leap_year(y)) ? 29 : 28;
                break;
            case Date::apr:
            case Date::jun:
            case Date::sep:
            case Date::nov:
                days_in_month = 30;
                break;
        }

        return days_in_month >= d;

    }

    bool leapyear(int y) {
        if (y % 400 == 0)return true;
        if (y % 100 == 0)return false;
        return y % 4 == 0;
    }

    bool operator==(const Date &a, const Date &b) {
        return a.year() == b.year() && a.month() == b.month() && a.day() == b.day();
    }

    bool operator!=(const Date &a, const Date &b) {
        return !(a == b);
    }

    ostream &operator<<(ostream &os, const Date &d) {
        return os << '(' << d.year()
                  << ',' << d.month()
                  << ',' << d.day() << ')';
    }

    istream &operator>>(istream &is, const Date &dd) {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;

        if (!is)return is;
        if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { // oops: format error
            is.clear(ios_base::failbit); // set the fail bit
            return is;
        }
    }

    enum Day {
        sunday, monday, tuesday, wednesday,
        thursday, friday, saturday
    };

    Day day_of_week(const Date &d) {
        // ...
    }

    Date next_Sunday(const Date &d) {
        // ...
    }

    Date next_weekday(const Date &d) {
        // ...
    }
}



//
// Created by admin on 2018/8/7.
//

#ifndef CPPNOTE_YEAR_H
#define CPPNOTE_YEAR_H
class Year {
public:
    static const int min = 1800;//类中的静态成员可以使所有类对象共用同一个变量，这和java一样
    static const int max = 2200;
public:
    class Invalid {
    };

    Year(int x) : y(x) {
        if (x < min || x > max) throw Invalid();
    }

    int year() const {
        return y;
    }

private:
    int y;
};
#endif //CPPNOTE_YEAR_H

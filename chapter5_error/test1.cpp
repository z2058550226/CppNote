//
// Created by 20585 on 2018/7/29.
//

#include "../suikajy.h"

// 第一种处理异常的方式是返回-1，这样做是一种将异常交给调用者处理的方式
int area1(int length, int width) {
    if (length <= 0 || width <= 0) return -1;
    return length * width;
}

// 第二种处理异常的方式是在内部处理，这种做法比较强制，
// 别人在调用这个函数时，有时为了防止出错还是会在外部处理
int area2(int length, int width) {
    if (length <= 0 || width <= 0) error("non-positive area() argument");
    return length * width;
}

// 第三种方式：抛出异常
class Bad_area : Exception {
};// 用于指明错误信息的类型

int area3(int length, int width) {
    if (length <= 0 || width <= 0)throw Bad_area();
    return width * length;
}

int main() {
    try {
        int x = -1;
        int y = 2;
        int z = 4;
        int area = area3(x, y);
    } catch (Bad_area) {
        cout << "Oops! bad arguments to area()\n";
    }
    return 0;
}
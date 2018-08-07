//
// Created by admin on 2018/8/2.
//

#include "../suikajy.h"

extern int suika_test2;

int my_find(string s, int);

int main(int argc, char *argv[]) {
    cout << suika_test2 << endl;
    return 0;
}

class C {// 普通类
public:
    void f();

    void g() {

    }

    struct M {// 成员类(内部类/嵌入类)
        void a();

        int b();
    };

    class MM {
    private:
        void c();
    };
};

void C::f() {
    my_find("a", 1);
    class L {// 局部类

    };
}

void C::M::a() {}

int C::M::b() {}

int my_find(string s, int) {// 保留参数，不指定名称，只是留给外部调用者，确保他们的老代码正确运行

}

// 改进版的my_find()，让它传递常量引用，这样既确保了传参的可变性最小，又跳过了拷贝复制对性能和空间的消耗
int my_find2(const string &s, int) {

}

void C::MM::c() {}

// 传引用可以减少存储空间复制成本，但最好加上const，这样可以防止函数内部改变引用空间中的内容。
void print(const vector<double> &v) {

}

//命名空间
namespace My_Graph_Lib {
    struct Color {/* ... */};
    struct Shape {/* ... */};
}

void testNameSpace() {
    My_Graph_Lib::Color c1();
    My_Graph_Lib::Color c2();
    My_Graph_Lib::Shape shape();
}

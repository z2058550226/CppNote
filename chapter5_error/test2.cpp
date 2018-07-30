//
// Created by admin on 2018/7/30.
// 数组越界错误
//

#include "../suikajy.h"

int main() {
    try {
        vector<int> v;
        int x;
        while (cin >> x)v.push_back(x);
        for (int i = 0; i <= v.size(); ++i) {
            cout << "v[" << i << "] == " << v[i] << endl;
        }
        getchar();
        return 0;
    } catch (out_of_range) {
        cerr << "Oops! Range error\n";
        return 1;
    } catch (...) {//捕捉所有异常
        cerr << "error aa" << endl;
        return 2;
    }

}


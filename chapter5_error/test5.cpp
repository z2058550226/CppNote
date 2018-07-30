//
// Created by admin on 2018/7/30.
//

#include "../suikajy.h"


int main() {

    vector<double> temps;// temperatures
    double temp = 0;
    double sum = 0;
    double high_temp = 0;
    double low_temp = 0;

    while (cin >> temp) {
        temps.push_back(temp);
    }

    for (int i = 0; i < temps.size(); ++i) {
        if (temps[i] > high_temp)high_temp = temps[i];
        if (temps[i] < low_temp)low_temp = temps[i];
        sum += temp;
    }

    cout << "High temperature: " << high_temp << endl;
    cout << "Low temperature: " << low_temp << endl;
    cout << "Average temperature: " << sum / temps.size() << endl;

    return 0;
}

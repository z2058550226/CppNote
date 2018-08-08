//
// Created by admin on 2018/8/8.
//

void num_output() {
    int num = 1234;
    cout << num << "\t(decimal)\n"
         << hex << num << "\t(hexadecimal)\n" // hex 用来通知后面的流用16进制输出
         << oct << num << "\t(octal)\n"; // oct 通知后面用8进制输出
}

void num_input() {
    int num;
    cin >> hex >> num;
}

void read_a_line() {
    string name;
    getline(cin, name); // input: Dennis Ritchie
    cout << name << endl; // output: Dennis Ritchie
}
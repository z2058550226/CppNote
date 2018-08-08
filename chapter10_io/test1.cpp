//
// Created by admin on 2018/8/7.
//

#include "../suikajy.h"
#include "Reading.h"
#include "read_one_val.h"

// 创建一个读文件流
int create_input_stream() {
    cout << "Please enter input file name:";
    string name;
    cin >> name;
    ifstream ist(name.c_str()); // ist is an input stream for the file named name
    if (!ist) return 1;
    cout << "create input stream success" << endl;
    string input;
    string buff;
    int pos;
    while (ist >> buff) { //之所以能这么写, 是因为>>的返回值是ist
        if ((pos = buff.find_first_of('\n')) != -1) {
            input.append("\r\n");
            cout << "pos : " << pos << endl;
        } else {
            input.append(" ");
            cout << "no end line." << endl;
        }
        input.append(buff);
    }
    cout << input << endl;
    ist.close();//用完记得关闭
    return 0;
}

// 创建一个写文件流
int create_output_stream() {
    cout << "Please enter name of output file:";
    string oname;
    cin >> oname;
    ofstream ost(oname.c_str());// ost is an output stream for a file named name
    if (!ost)return 1;
    cout << "create output stream success" << endl;
    return 0;
}

// 创建一个文件流
int create_file_stream() {
    fstream fs;
    fs.open("a.txt", ios_base::in);// ios_base::in是读取，ios_base::out是写入
    string buff;
    string input;
    if (!(fs >> input))return 1;
    while (fs >> buff) {
        input.append(" ");
        input.append(buff);
    }
    cout << "input is : " << input << endl;
    return 0;
}

// 读取温度
int read_temp() {
    ifstream ist("temp");
    vector<Reading> temps;
    int hour;
    double temperature;
    while (ist >> hour >> temperature) {
//        cout << "hour : " << hour << " temperature : " << temperature << endl;
        if (hour < 0 || hour > 23) return 1;
        temps.push_back(Reading(hour, temperature));
    }
    for (int i = 0; i < temps.size(); ++i) {
        cout << "hour : " << temps[i].hour << " temperature : " << temps[i].temperature << endl;
    }
    return 0;
}

// read integers from ist into v until we reach eof() or terminator
template<typename T>
int fill_vector(istream &ist, vector<T> &v, char terminator) {
    T i;
    while (ist >> i) {
        cout << "i : " << i << endl;
        v.push_back(i);
    }
    if (ist.eof()) {
        print_r(v);// 智能推断类型，这里完整写法是print_r<T>(v);
        return 0; // fine: we found the end of file
    }

    // 下面这句可以去掉，因为bad状态默认会抛出ios_base::failure
    if (ist.bad()) cout << "stream corrupted!" << endl; // stream corrupted; let's get out of here!
    if (ist.fail()) { // clean up the mess as best we can and report the problem
        ist.clear(); // clear stream state,
        // so that we can look for terminator
        char c;
        ist >> c; // read a character, hopefully terminator
        if (c != terminator) { // unexpected character
            ist.unget(); // put that character back
            // clear()函数具有设置流状态的功能。
            // 流状态有goodbit、failbit、badbit、eofbit和默认状态（无参数）
            ist.clear(ios_base::failbit); // set the state to fail()
            cout << "end with fail, c is : \"" << c << "\"" << endl;
            return 1;
        }
        cout << "end with terminator" << endl;
        print_r(v);
        return 0;
    }

    return 1;
}

int test_fill_vector() {
    // 这里CMake很坑，生成文件中没有num.txt，需要手动将num.txt移到生成文件目录中
    ifstream ist("num.txt");
    vector<string> v;
    char terminator = '*';
    return fill_vector<string>(ist, v, terminator);
}


int main(int argc, char *argv[]) {

    return read_one_val();
}
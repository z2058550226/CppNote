//
// Created by admin on 2018/8/8.
//

#include "Temperature.h"
#include "Punct_stream.h"

//用来将一个引用指向的内存表示成二进制形式
template<class T>
char *as_bytes(T &i) { //treat a T as a sequence of bytes
    void *addr = &i; // get the address of the first byte
    // of memory used to store the object
    return static_cast<char *>(addr); //  treat that memory as bytes
}

// if possible, convert characters in s to floating-point value
double str_to_double(string s);

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

int binary_io() {
    // open an istream for binary input from a file:
    cout << "Please enter input file name\n";
    string name;
    cin >> name;
    ifstream ifs(name.c_str(), ios_base::binary); // note: stream mode
    // "binary" tells the steam not to try anything clever with the bytes.
    if (!ifs)error("can't open input file " + name);

    // open an ostream for binary output to a file:
    cout << "Please enter output file name\n";
    cin >> name;
    ofstream ofs(name.c_str(), ios_base::binary); // note: stream mode
    // "binary" tels the stream not to try anything clever with the bytes
    if (!ofs) error("can't open output file " + name);

    vector<int> v;
    // read from binary file:
    int i;
    while (ifs.read(as_bytes(i), sizeof(int))) // note: reading bytes
        v.push_back(i);

    // ...do something with v...

    // write to binary file:
    for (i = 0; i < v.size(); ++i) {
        ofs.write(as_bytes(v[i]), sizeof(int)); // note: writing bytes
    }
    return 0;
}

// 文件定位
int file_locate() {
    cout << "Please enter input file name\n";
    string name;
    cin >> name;
    fstream fs(name.c_str());
    if (!fs)error("can't open " + name);

    fs.seekg(5); // move reading position("g" for "get") to 5 (the 6th character)
    char ch;
    fs >> ch; // read and increment reading position
    cout << "character[5] is " << ch << '(' << int(ch) << ")\n";

    fs.seekg(1); // move writing position ("p" for "put") to 1
    fs << 'y'; // write and increment writing position
    return 0;
}

// 字符串流
int string_stream() {
    try {
        double d1 = str_to_double("12.4"); //testing
        cout << d1 << endl;
        double d2 = str_to_double("1.34e-3");
        cout << d2 << endl;
        double d3 = str_to_double("twelve point three"); // will call error()
        cout << d3 << endl;
    } catch (runtime_error &e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}

double str_to_double(string s) {
    istringstream is(s); // make a stream so that we can read from s
    double d;
    is >> d;
    if (!is) error("double format error: " + s);
    return d;
}

// 格式化输出生成单一字符串, 相当于c中的springtf
void my_code(string label, Temperature temp) {
    ostringstream os;
    os << setw(8) << label << ": " <<
       fixed << setprecision(5) << temp.temp << temp.unit;
    cout << os.str().c_str() << endl;
}

int test_my_code() {
    Temperature temp;
    temp.unit = "c";
    temp.temp = 38.1;
    my_code("suika", temp);
    return 0;
}

// 字符分类
int char_divide() {
    char ch;
    while (cin.get(ch)) {
        if (isspace(ch)) { // if ch is whitespace
            // do something
        }
        if (isdigit(ch)) {
            // do something
        } else if (isalpha(ch)) { // 判断是否是英文字母
            // do something
        } else {

        }
    }
}

// 自定义流
int custom_stream() {
    // given text input, produce a sorted list of all words in that text
    // ignore punctuation and case differences
    // eliminate duplicates from the output

    Punct_stream ps(cin);
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~"); // note \" means " in string
    ps.case_sensitive(false);

    cout << "please enter words\n";
    vector<string> vs;
    string word;
    while (ps >> word) vs.push_back(word); // read words

    sort(vs.begin(), vs.end());
    for (int i = 0; i < vs.size(); ++i) {
        if (i == 0 || vs[i] != vs[i - 1]) cout << vs[i] << endl;
    }

    return 0;
}

//
// Created by 20585 on 2018/9/7.
// wifi连接手机，总共分为如下几步
// 1. 先用usb线连接手机
// 2. adb tcpip 41441 给手机指定一个端口号41441
// 3. adb shell ifconfig wlan0 查看手机wifi的ip，也可以直接在手机上看
// 4. adb connect 192.168.1.76:41441 连接手机即可。
//

#include <iostream>
#include <regex>
#include <string>
#include <unistd.h>

using namespace std;

//通过正则判断是否是ip
bool is_IPAddress_valid(const string &ipaddress) {
    const regex pattern(
            "(((\\d{1,2})|(1\\d{1,2})|(2[0-4]\\d)|(25[0-5]))\\.){3}((\\d{1,2})|(1\\d{1,2})|(2[0-4]\\d)|(25[0-5]))");
    //三位数的都可以，没有设置1-255 的条件
    match_results<string::const_iterator> result;
    bool valid = regex_match(ipaddress, result, pattern);
//    if (valid && (result.length() > 0)) {
//        for (int i = 0; i < result.length(); i++) {
//            cout << result[i] << endl;
//        }
//    }
    return valid;
}

int main(int argc, char *argv[]) {
    cout << "请输入要连接的手机的ip（要在相同局域网下）：";
    string phoneIP;
    phoneIP = "192.168.1.76";
    if (is_IPAddress_valid(phoneIP)) {
        string connectPort = "41441";

        string cChangePort = "adb tcpip " + connectPort;
        string cConnect = "adb connect " + phoneIP + ":" + connectPort;

        string finalCommand = cChangePort + " && " + cConnect;
        system(finalCommand.c_str());

        cout << "3秒内关闭" << endl;
        sleep(3);
        return 0;
    } else {
        cerr << "wrong ip " << phoneIP << endl;
        cout << "3秒内关闭" << endl;
        sleep(3);
        return 1;
    }

}
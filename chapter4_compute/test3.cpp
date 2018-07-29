//
// Created by admin on 2018/7/27.
//

#include "../suikajy.h"

int main(int argc, char *argv[]) {
    vector<string> words;
    string temp;
    while (cin >> temp)
        words.push_back(temp);
    cout << "\nNumber of words: " << words.size() << endl;
    sort(words.begin(), words.end());
    for (int i = 0; i < words.size(); ++i) {
        if (i == 0 || words[i - 1] != words[i])
            cout << words[i] << endl;
    }
    getchar();
    return 0;
}
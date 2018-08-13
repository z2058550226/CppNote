//
// Created by admin on 2018/8/9.
//

#ifndef CPPNOTE_PUNCT_STREAM_H
#define CPPNOTE_PUNCT_STREAM_H

#include "../suikajy.h"

// like an istream, but the user can add to the set of whitespace characters
class Punct_stream {
public:
    Punct_stream(istream &is) : source(is), sensitive(true) {};

    void whitespace(const string &s) {
        white = s; // make s the whitespace set
    }

    void add_white(char c) {
        white += c; // add to the whitespace set
    }

    bool is_whitespace(char c) {// is c in the whitespace set?
        for (int i = 0; i < white.size(); ++i) {
            if (c == white[i])return true;
        }
        return false;
    }

    void case_sensitive(bool b) {
        sensitive = b;
    }

    bool is_case_sensitive() {
        return sensitive;
    }

    Punct_stream &operator>>(string &s) {
        while (!(buffer >> s)) { // try to read from buffer
            if (buffer.bad() || !source.good())return *this;
            buffer.clear();

            string line;
            getline(source, line); // get a line from source
            // do character replacement as needed:
            for (int i = 0; i < line.size(); ++i) {
                if (is_whitespace(line[i])) {
                    line[i] = ' '; // to space
                } else if (!sensitive) {
                    line[i] = tolower(line[i]); // to lower case
                }
            }
            buffer.str(line); // put string into stream
        }
        return *this;
    }

    // 用于检验流状态，当调用if(ps >> str)时就会变成bool值
    explicit operator bool() {
        return !(source.fail() || source.bad()) && source.good();
    }

private:
    istream &source; // character source
    istringstream buffer; // we let buffer do our formatting
    string white; // characters considered "whitespace"
    bool sensitive; // is the stream case-sensitive?
};

#endif //CPPNOTE_PUNCT_STREAM_H

//
// Created by admin on 2018/8/7.
//

#ifndef CPPNOTE_READING_H
#define CPPNOTE_READING_H

struct Reading {
    int hour;
    double temperature;

    Reading(int h, double t) : hour(h), temperature(t) {}
};

#endif //CPPNOTE_READING_H

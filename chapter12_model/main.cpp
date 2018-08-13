//
// Created by admin on 2018/8/9.
//

#include "suikajy.h"
//#include "Fl.H"
//#include "Fl_Window.H"
//#include "Fl_Box.H"
//
//int fltk_test(int argc, char *argv[]) {
//    Fl_Window *window = new Fl_Window(300, 180);
//    Fl_Box *box = new Fl_Box(20, 40, 260, 100, "Hello, World!");
//    box->box(FL_UP_BOX);
//    box->labelsize(36);
//    box->labelfont(FL_BOLD + FL_ITALIC);
//    box->labeltype(FL_SHADOW_LABEL);
//    window->end();
//    window->show(argc, argv);
//    return Fl::run();
//}

int cout_test() {
    cout << "hello suikajy" << endl;
    keep_window_open();
    return 0;
}

int main(int argc, char *argv[]) {
    return cout_test();
}
//
// Created by Sergey Murtazin on 04/01/2020.
//

#include "stdlyb_common.h"
#include <fstream>
#include <sstream>

void stream_ex1() {
    cout << "text" << 42 << " " << true << " " << false << endl;
    cout << boolalpha;
    cout << true << " " << false << endl;
}

void stream_ex2() {
    int width;
    float height;

    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;

    auto area = width * height;
    cout << "Area is " << area << endl;

    ostringstream oss;
    oss << "Width is " << width << ", ";
    oss << "Height is " << height << ", ";
    oss << "Area is " << area;

    string text = oss.str();

    cout << text << endl;
}

void file_stream_ex3() {
    ofstream ofs("/Users/smurtazin/Programming/CLion_Projects/TestProj1/info.txt");
    string s;

    while((cin >> s) && (s != "Q")) {
        ofs << s << endl;
    }
}

// should work on linux only
// doesn't work on macos
//void file_system() {
//    #include <filesystem>
//    cout << "Current path is " << std::filesystem::current_path() << '\n';
//}


int main(int argc, char **argv) {
//    stream_ex1();
//    stream_ex2();
    file_stream_ex3();

    return EXIT_SUCCESS;
}
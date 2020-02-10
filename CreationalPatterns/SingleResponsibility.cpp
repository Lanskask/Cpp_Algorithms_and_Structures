//
// Created by Sergey Murtazin on 04/01/2020.
//


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Journal {
    string title;
    vector<string> entries;

    explicit Journal(const string &title) : title(title) {}

    void add(const string& entry) {
        entries.push_back(entry);
    }

    // moved to PersistentManager
//    void save(const string& filename) {
//        ofstream ofs(filename);
//        for (auto& s : entries)
//            ofs << s << endl;
//    }
};

struct PersistentManager{
    void save(const Journal& j, const string& filename) {
        ofstream ofs(filename);
        for (auto& s : j.entries)
            ofs << s << endl;
    }
};
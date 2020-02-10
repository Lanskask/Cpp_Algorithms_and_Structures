//
// Created by Sergey Murtazin on 04/01/2020.
//

#include "stdlyb_common.h"

template<int n>
int sum(array<int, n> arr) {
    int result = 0;
    for (int x : arr)
        result += x;
    return result;
}

template<typename T>
void print_collection(T collection) {
    for (typename decltype(collection)::value_type x : collection)
        cout << x << ", ";
    cout << endl;
}

template<typename T1, typename T2>
void print_map(map<T1, T2> map_to_print) {
    for (auto p : map_to_print)
        cout << p.first << ": " << p.second << ", ";
    cout << endl;
}

void arrays_ex1() {
    array<int, 5> numbers = {{1, 2, 3, 4, 5}};
    array<int, 3> less_numbers = {{1, 2, 3}};
    cout << sum<numbers.size()>(numbers) << endl;
    cout << sum<less_numbers.size()>(less_numbers) << endl;
}

void vector_ex2() {
    vector<float> values{1, 2, 3};
    values.push_back(4.5f);
    values.push_back(5);
    print_collection<decltype(values)>(values);

    values.pop_back();
    values.pop_back();

    print_collection<decltype(values)>(values);

    try {
        auto v = values.at(5);
    } catch (const out_of_range &ore) {
        cout << "It's a out_of_range exeption on `auto v = values.at(5);` "
             << ore.what() << endl;
    }
}

void set_ex3() {
    string s = "ow my God, I'm alive!";
    set<char> set1;
    for (char c: s)
        if (isalpha(c)) set1.insert(c);

    print_collection<decltype(set1)>(set1);

//    cout << sizeof(s) / get<0, decltype(set1)::value_type>(set1) << endl;
    cout << "chars in string: " << s.size() << endl;
    cout << "How much unique chars: " << set1.size() << endl;
}


void map_ex4() {
    string s = "ow my God, I'm alive!";

    map<char, int> histogram;
    for (char c : s)
        if (isalnum(c)) histogram[c]++;


//    print_map<
//        decltype(histogram)::value_type::first,
//        decltype(histogram)::value_type::second
//    >(histogram);
//    cout << decltype(histogram)::value_type(histogram.at(0).first) << endl;
    cout << "histogram.at(0): " << histogram.at('o') << endl;

    print_map<char, int>(histogram);
}

//template<typename T>
//void get_variable_type(T collection) {
//    #include <typeinfo>
//
//    map<int, char> variable_map;
////    cout << typeid(variable_int).name() << endl;
//
////    switch ((typeid(collection).name())) {
////        case typeid(variable_map):
////            break;
////        default:
////            print_collection<decltype(collection)>(collection);
////    }
//
//}


int main(int argc, char **argv) {
//    arrays_ex1();
//    vector_ex2();
//    set_ex3();
    map_ex4();

    return EXIT_SUCCESS;
}
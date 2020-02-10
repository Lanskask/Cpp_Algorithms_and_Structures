//
// Created by Sergey Murtazin on 03/01/2020.
//
#include "templates_common.h"


typedef pair<int, int> int_pair;
typedef tuple<int, int, int> trie;

pair<int, int> sum_and_product(int a, int b) {
    return pair<int, int>(a + b, a * b);
};

trie sum_product_avg(int a, int b, int c) {
    return trie{a + b + c, a * b * c, (a + b + c) / 3};
}

template<typename T1, typename T2, typename T3>
struct triple {
    typedef T1 result_type;

    T1 first;
    T2 second;
    T3 third;

    triple(const T1 &first, const T2 &second, const T3 &third)
            : first(first), second(second), third(third) {}
};

typedef triple<int, int, int> trie2;

trie2 sum_product_avg_trie2(int a, int b, int c) {
    return trie2{a + b + c, a * b * c, (a + b + c) / 3};
}

void consuming_templates() {
//    cout
//        << sum_and_product(3,4).first << " "
//        << sum_and_product(3,4).second << " "
//        << endl;
    auto result1 = sum_and_product(3, 4);
    cout
            << get<0>(result1) << " "
            << get<1>(result1) << " "
            << endl;

    auto result2 = sum_product_avg(1, 2, 3);
    cout << "sum_product_avg: "
         << get<0>(result2) << " "
         << get<1>(result2) << " "
         << get<2>(result2) << " "
         << endl;

    auto result3 = sum_product_avg_trie2(1, 2, 3);
    cout
            << result3.first << " "
            << result3.second << " "
            << result3.third << " "
            << endl;
}


// ---- for templating functions --------
template<typename T1, typename T2, typename T3>
triple<T1, T2, T3> sum_product_avg__triple_w_template(const T1 &a, const T2 &b, const T3 &c) {
    return triple<T1, T2, T3>{a + b + c, a * b * c,
                              (a + b + c) / typename triple<T1, T2, T3>::result_type(3)
    };
}

void template_functions() {
    auto a = 5;
    auto b = 2.0;
    auto c = -3.0f;

    auto result4 = sum_product_avg__triple_w_template(a, b, c);
    string text_str = "sum_product_avg__triple_w_template(" + to_string(a)
                      + "," + to_string(b) + ", " + to_string(c) + ")";
    cout << text_str << ": "
         << result4.first << " "
         << result4.second << " "
         << result4.third << " "
         << endl;
}

// ---- for templating specialization --------
typedef complex<double> cd;
typedef triple<cd, cd, cd> cdt;

template<>
cdt sum_product_avg__triple_w_template(const cd &a, const cd &b, const cd &c) {
    auto result = sum_product_avg__triple_w_template(a.real(), b.real(), c.real());
    return cdt(result.first, result.second, result.third);
}


void template_specialization() {
    cd a(2, 4), b(3, 4), c(4, 5);
    auto result = sum_product_avg__triple_w_template(a, b, c);
    string text_str = "sum_product_avg__triple_w_template(cd a(2,4), b(3,4), c(4,5))";
    cout << text_str << ": "
         << result.first << " "
         << result.second << " "
         << result.third << " "
         << endl;
}

// --- for variadic_templates ---
template<typename T>
T sum(T t) { return t; }

template<typename T, typename ...U>
auto sum(T t, U ...u) -> decltype(t + sum(u...)) {
    return t + sum(u...);
}

// ------------- from stackoverflow
template<typename T>
T adder(T first) {
    return first;
}

template<typename T, typename... Args>
//T adder(T first, Args... args) {
auto adder(T first, Args... args) {
//auto adder(T first, Args... args) -> decltype(sum(args)) {
    return first + adder(args...);
}
// ------------- end of from stackoverflow

void variadic_templates() {
//    cout << sum(1,2,3,4) << endl;
//    cout << adder(1,2,3,4) << endl;
//    cout << adder(1,2.4,3,4) << endl;
//    cout << adder("a") << endl;
//    cout << adder("a"s, "b"s) << endl;
    cout << adder(1, (2, 3, 4)) << endl;
}

// --------- metaprogramming ---
template <int n> struct Factorial {
    enum {value = n * Factorial<n-1>::value };
};

template <> struct Factorial<0> {
    enum {value = 1};
};

void metaprogramming() {
    cout << Factorial<5>::value << endl;
}
// --------- end of metaprogramming ---

int main(int argc, char **argv) {
//    consuming_templates();
//    template_functions();
//    template_specialization();
//    variadic_templates();
    metaprogramming();

    return EXIT_SUCCESS;
}
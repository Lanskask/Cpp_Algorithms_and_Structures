#include "common.h"
#include <typeinfo>
#include <vector>
#include "oop_classes/Person.h"

//#include "in_dir/Person.h"
//#include "in_dir/Person.cpp"

void edit_value(int &a, int new_val) {
    a = new_val;
}

//void compare_persons(Person &p, int i);

//Person p = {"Bob", "Dilan", 5};

inline int add(int a, int b) { return a + b; }

inline auto add2(const int a, const int b) -> int { return a + b; }

void inc(int &i) { i++; }

void ex0() {
    //    compare_persons(p, 8);
}

void ex1() {
    int a = 5;
    edit_value(a, 6);
    assert(a == 6);
    cout << "New a is: " << a << endl;
}

void ex2() {
    cout << add(2, 3) << endl;
    cout << add2(2, 3) << endl;
}

void ex3() {
    int init_i = 5;
    cout << "init_i Before inc: " << init_i << endl;
    inc(init_i);
    cout << "init_i After inc: " << init_i << endl;
}

void ex4() {
    std::string s("hello");
    auto t = new std::string("world");
    delete t;
    int *arr = new int[128];
    delete[] arr;
}

void ex5() {
    int x = 5;
    auto doubleFunc = [](int z) { return z * 2; };
    cout << x << " * 2 = " << doubleFunc(x) << endl;

    int y = 10;
//    auto increaseByY = [y](int z){ return y + z;};
//    auto increaseByY = [&y](int z){ return y + z;};
//    auto increaseByY = [=](int z){ return y + z;};
    auto increaseByY = [&](int z) { return y + z; };

    cout << "Y now is " << y << ".\n\t "
                                "And increaseByY(5): " << increaseByY(5) << endl;

    y = 100;

    cout << "Y now is " << y << ".\n\t "
                                "And increaseByY(5): " << increaseByY(5) << endl;

}

void enumerations_ex6() {
    cout << "Enumerations" << endl;

    enum Color {
        Red, Green, Blue
    };
    enum class GameState {
        Loose, Win
    };

    Color c_R = Color::Red;
    Color c_G = Color::Green;
    Color c_B = Color::Blue;
    Color colors[] = {c_G, c_R, c_B};
    int i = c_R;
    cout << "c_R indx: " << i << endl;
    cout << "c_R from global - should be 0: " << Red << endl;

//    for_each(colors[0], colors[2],
//            [&](Color c){ cout << c << endl;});
    for (Color c : colors) {
        cout << c << endl;
    }
}

void get_type_ex7() {
    enum En {
        One, Zero
    };
    enum class EnCl : short {
        Some, Other
    };
    int int1;

    En en = One;
    cout << typeid(en).name() << endl;

    EnCl enCl = EnCl::Some;
    cout << typeid(enCl).name() << endl;

    cout << typeid(int1).name() << endl;

//    cout << decltype(int1) i << endl; // doesn't work
    cout << "sizeof(en): " << sizeof(en) << endl;
    cout << "sizeof(enCl): " << sizeof(enCl) << endl;
}

void union_ex8() {
    union Data {
        int integer;
        float fpnumber;
        char *text;
    };

    Data d{};
    d.fpnumber = 0.5f;
//    __m128 // used for SIMD - simple instruction multiple data
    char word[] = {'A', 'S'};
    d.text = word;
    cout << d.integer << endl;
    cout << d.fpnumber << endl;
    cout << d.text << endl;
}

void struct_ex9() {
    struct Size {
        int height;
        int width;
    };
    Size s1{1, 2};
    Size s2{1, 2};

//    cout << s1.height << endl;
}

namespace life {
    int meaning = 42;
    int *meaning_p = &meaning;

    auto mean = 43;
    auto *mean_p = &mean;
    auto &rm = mean;
}

void namespaces_ex10() {
//    cout << meaning << endl;
    using namespace life;

//    cout << "meaning: " << meaning << endl;
//    cout << "sizeof(meaning): " << sizeof(meaning) << endl;
//
//    cout << "meaning_p: " << meaning_p << endl;
//    cout << "sizeof(meaning_p): " << sizeof(meaning_p) << endl;
//
//    cout << "mean: " << mean << endl;
//    cout << "mean_p: " << mean_p << endl;

    cout << "mean: " << mean << endl;
    *mean_p = 44;
    cout << "mean: " << mean << endl;
    rm = 45;
    cout << "mean: " << mean << endl;
}

void iteration_ex11() {
    int a[]{1, 2, 3, 4};

//    for (int j = 0; j < 4; ++j)
    cout << "sizeof(a): " << sizeof(a) << endl;
    cout << "sizeof(a[0]): " << sizeof(a[0]) << endl;
    cout << "num of elements in simp array: "
         << sizeof(a) / sizeof(a[0]) << endl;

    for (int j = 0; j < sizeof(a) / sizeof(a[0]); ++j)
        cout << a[j] << "\t";
    cout << endl;

    for (int i : a)
        cout << i << "\t";
    cout << endl;

    for (int *p = a, *e = a + 4; p != e; ++p)
        cout << *p << "\t";
    cout << endl;

    auto ba = begin(a);
    auto ea = end(a);
    for (; ba != ea; ba++)
        cout << *ba << "\t";
    cout << endl;

    // Use of vector
    vector<int> v{5, 6, 7, 8};
//    auto bv = begin(v);
    auto bv = v.begin();

    for(; bv != end(v); bv++)
        cout << *bv << "\t";
    //    for_each(begin(v), end(v), [&])

//    auto cbv = cbegin(v);
    auto cbv = v.cbegin();
    cout << endl;

    //    *cbv = 4; // error
//    for (auto p = v.rbegin(); p != v.crend(); p++)
    for (vector<int>::reverse_iterator p = v.rbegin();
            p != v.crend(); p++)
        cout << *p << "\t";
}

void switch_ex12() {
    int i = 1;

    switch(i) {
        case 0:
            cout << "Hello" << endl;
            break;
        case 1:
            cout << "World" << endl;
            break;
        default:
            cout << "!" << endl;
            break;
    }
}

void boolean_conversion_ex13() {
    char *s = "Pluralsight";

    while(*s) {
        putchar(*s);
        cout << endl;
        s++;
    }

    int *p = nullptr;
    if (p) {
        cout << "if nullptr" << endl;
    }
}


int main() {
//    ex0();
//    ex1();
//    ex2();
//    ex3();
//    ex4();
//    ex5();
//    enumerations_ex6();
//    get_type_ex7();
//    union_ex8();
//    struct_ex9();
//    namespaces_ex10();
//    iteration_ex11();
//    switch_ex12();
    boolean_conversion_ex13();

    return EXIT_SUCCESS;
}



//void compare_persons(Person &p, int i) {
//    auto ans = p < i;
//    cout << ans << endl;
//}
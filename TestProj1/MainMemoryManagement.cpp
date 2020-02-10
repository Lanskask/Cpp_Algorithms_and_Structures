//
// Created by Sergey Murtazin on 31/12/2019.
//

#include "common.h"

class Address {
public:
    string city;
    Address(){}
    Address(const string &city) : city(city) {
        cout << "Address with " << city << " as City created" << endl;
    }

    virtual ~Address() {
        cout << "Address with " << city << " as City destroyed" << endl;
    }
};

class Person {
public:
    Address *address;

    Person(string const& city) {
        address = new Address(city);
        cout << "Person is created" << endl;
    }

    virtual ~Person() {
        delete address;
        cout << "Person is destroyed" << endl;
    }
};

class Person2 {
    Person2(){}
    Person2(const Person2& _){}
    ~Person2(){}

    int ref_count;
public:
    // Person2Factory - Object created on the heap
    static Person2* create() {
        auto *p = new Person2;
        p->ref_count = 1;
        return p;
    }

    void add_ref() { this->ref_count++;}
    void release() {
        if (--ref_count == 0) {
            delete  this;
        }
    }
};

class Person3 {
public:
    shared_ptr<Address> address;

//    Person3(const shared_ptr<Address> &address)
//        : address(address) {}
    Person3(string const& city) {
        address = make_shared<Address>(city);
        cout << "Person is created" << endl;
    }

    virtual ~Person3() {
        cout << "Person is deleted" << endl;
    }
};

void func_check_decrement() {
    int init = 10;
    cout << init << endl;
    cout << init-- << endl;
    cout << --init << endl;
}

void inc(int& i) { i++;}
int meaningOfLive() { return 42;}

void move_rvalue() {
    int a = 0;
    inc(a);
//    inc(1);
//    int& x = meaningOfLive();
    const int& x = meaningOfLive();

    int&& y = meaningOfLive();
    cout << y << endl;

//    Address book[100];
//    book[55] = Address("Paris");

    Address* book[100];
//    Address& book[100]; // not allowed
    book[55] = move(new Address("Paris"));

    auto swap = [](int& a, int& b){
        int tmp{a};
        a = b;
        b = tmp;
    };

    auto betterSwap = [](int& a, int& b) {
        int tmp(move(a));
        a = move(b);
        b = move(tmp);
    };

    int x2 = 2, y2 = 5;
    swap(x2, y2);
}

// --- smart pointers ---
Address* create_address_simple(string const& city) {
//        Address a(city);
//        return a;
    auto *a = new Address(city); // returning not the same copied value, but just reference to created value on the heap
    return a;
}

unique_ptr<Address> create_address(string const& city) {
//    auto *a = new Address(city);
//    a->city = "New " + a->city;
//    return unique_ptr<Address>(a);
    return make_unique<Address>(city);
//    return unique_ptr<Address>(new Address(city));
}

void pointers() {
//    auto a = create_address("Paris");

    shared_ptr<Address> a;

    {
        Person3 p("Paris");
        a = p.address;
    }

    cout << a->city << endl;
}


int main(int argc, char **argv) {
//    Address *a;
//
//    {
//        Person p("Delaver");
//        a = p.address;
//    }
//
//    cout << a->city << endl;

//    func_check_decrement();
//    getchar();
//    move_rvalue();
    pointers();

    return EXIT_SUCCESS;
}
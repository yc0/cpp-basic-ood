//
// Created by Nelson Lin.
// The Dependency Inversion Principle

// 1) High-level modules (CoffeeMachine) should not depend on low-level modules. Both should depend on abstractions (e.g. interfaces).
// 2) Abstractions should not depend on details. Details (concrete implementations) should depend on abstractions. ( brew(Coffee) )
//
//
#include <iostream>
using namespace std;

struct Coffee {
    virtual string to_string() = 0;

    virtual ~Coffee() {

    }
};

struct Arabia : Coffee {
    string to_string() override {
        return "arabia";
    }
};

struct Rabusta  : Coffee {
    string to_string() override {
        return "rabusta";
    }
};

struct CoffeeMachine {
    virtual void brew(unique_ptr<Coffee> coffee) = 0;

    virtual ~CoffeeMachine() {

    }
};

struct BrewMachine  : CoffeeMachine {
    void brew(unique_ptr<Coffee> coffee) override {
        cout << "Brew: " << coffee->to_string() << endl;
    }
};
int main() {
    BrewMachine bm;

    bm.brew(make_unique<Arabia>());
    bm.brew(make_unique<Rabusta>());

    cout << endl;
    getchar();
    return 0;
}
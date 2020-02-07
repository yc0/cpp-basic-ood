//
// Created by Nelson Lin.
// The Open Closed Principle
//

#include <iostream>
#include <vector>

using namespace std;

struct canshoot {
    virtual void shoot() = 0;
    virtual ~canshoot() {}
};

struct laserbean  : canshoot {
    void shoot() override {
        cout << "Ziiip" << endl;
    }
};

struct cesiumBeam : canshoot {
    void shoot() override {
        cout << "Ciiiip" << endl;
    }
};

struct rocketLauncher : canshoot {
    void shoot() override {
        cout << "Woosh" << endl;
    }
};

struct weapon_composite {
    weapon_composite(vector<unique_ptr<canshoot>> &weapons) {
        for(auto& weapon : weapons)
            weapon->shoot();
    }
};

int main() {
    unique_ptr<canshoot> c = make_unique<laserbean>();
    vector<unique_ptr<canshoot>> data;
    data.emplace_back(move(c));
    weapon_composite wc{data};

    for(int i=0; i < 33; ++i)
        cout << "=";
    cout << "\n3 weapons fire" << endl;
    data.emplace_back(make_unique<rocketLauncher>());
    data.emplace_back(make_unique<cesiumBeam>());
    weapon_composite wc2{data};

    getchar();
    return 0;
}

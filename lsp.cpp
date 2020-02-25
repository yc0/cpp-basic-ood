/*
 * The Liskov Substitution Principle
 * FUNCTIONS THAT USE POINTERS OR REFERENCES TO BASE
CLASSES MUST BE ABLE TO USE OBJECTS OF DERIVED CLASSES
WITHOUT KNOWING IT.

 * In other word, the derive can substitute his parent and behaves the same.
 * 子類別必須能夠替換父類別，並且行為正常
 */
#include <cassert>
#include <iostream>
using namespace std;
struct Rectangle {
    virtual void setWidth(double w) {
        // Design by contract - precondition
        auto old = this->height;
        this->width = w;
        // Deisgn by Contract - postcondition
        assert(this->width == w && this->height == old);
    }
    virtual void setHeight(double h) {
        this->height = h;

    }
    double getHeight() const {return height;}
    double getWidth() const {return width;}
    double getArea() const {return height*width;}
private:
    double height, width;
};

struct Square : Rectangle {
    void setWidth(double w) override;
    void setHeight(double h) override;
};

void Square::setWidth(double w) {
    Rectangle::setWidth(w);
    Rectangle::setHeight(w);
}

void Square::setHeight(double h) {
    Rectangle::setHeight(h);
    Rectangle::setWidth(h);
}

void g(Rectangle& r) {
    r.setHeight(5);
    r.setWidth(4);
    cout << r.getArea() << endl;
    assert(20.0 == r.getArea());

}
int main() {
    Rectangle r;
    g(r);

    Square s;
    g(s);

}
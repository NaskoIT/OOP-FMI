#include <iostream>
#include <string>

using namespace std;

struct Circle {
private:
    double radius;

public:
    Circle(double radius) {
        this->setRadius(radius);
    }

    void setRadius(double radius) {
        if (radius <= 0) {
            cout << "Please enter valid radius" << endl;
            return;
        }

        this->radius = radius;
    }

    double getRadius() {
        return this->radius;
    }

    double getArea() {
        return this->radius * this->radius * 3.14;
    }

    string toString() {
        return to_string(radius) + " -> " + to_string(this->getArea());
    }
};

int main() {
    Circle circle(5);
    circle.print();
    cout << "The are is: " << circle.getArea() << endl;

    circle.setRadius(10);
    cout << circle.toString();
    cout << "The are is: " << circle.getArea() << endl;
}
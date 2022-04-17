#include <iostream>
#include "Balloon.h"

using namespace std;

Balloon::Balloon() {
    this->price = 0;
    this->color = Red;
}

Balloon::Balloon(double price, Color color)
        : price(price), color(color) {}

double Balloon::getPrice() const {
    return price;
}

Color Balloon::getColor() const {
    return color;
}

void Balloon::setPrice(double price) {
    this->price = price;
}

void Balloon::setColor(Color color) {
    this->color = color;
}

void Balloon::print() const {
    cout << "Balloon: " << this->getPrice() << " " << this->getColor() << endl;
}


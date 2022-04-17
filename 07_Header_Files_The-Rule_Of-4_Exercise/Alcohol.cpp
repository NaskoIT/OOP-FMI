#include <cstring>
#include <iostream>
#include "Alcohol.h"

using namespace std;

Alcohol::Alcohol() {
    this->price = 0;
    this->name = nullptr;
}

Alcohol::Alcohol(const double price, const char *name) {
    this->price = price;
    this->setName(name);
}

Alcohol::~Alcohol() {
    delete[] this->name;
}

Alcohol::Alcohol(const Alcohol &other) {
    this->setName(other.name);
    this->price = other.price;
}

Alcohol &Alcohol::operator=(const Alcohol &other) {
    if (this != &other) {
        if (this->name != nullptr) {
            delete[] this->name;
        }

        this->setName(other.name);
        this->price = other.price;
    }

    return *this;
}

void Alcohol::setName(const char *name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Alcohol::print() const {
    cout << "Alcohol: " << this->name << " " << this->price << endl;
}

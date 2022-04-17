#include <cstring>
#include <iostream>
#include "Shisha.h"

using namespace std;

void Shisha::copyFields(const Shisha &other) {
    this->setPrice(other.price);
    this->setBrand(other.brand);
    this->setTaste(other.taste);
}

Shisha::Shisha() {
    this->price = 0;
    this->brand = nullptr;
    this->taste = nullptr;
}

Shisha::Shisha(double price, const char *brand, const char *taste) : price(price) {
    this->setBrand(brand);
    this->setTaste(taste);
}

Shisha::Shisha(const Shisha &other) {
    this->copyFields(other);
}

Shisha& Shisha::operator=(const Shisha &other) {
    if (this != &other) {
        if (this->taste != nullptr) {
            delete[] this->taste;
        }
        if (this->brand != nullptr) {
            delete[] this->brand;
        }

        this->copyFields(other);
    }

    return *this;
}

Shisha::~Shisha() {
    delete[] this->brand;
    delete[] this->taste;
}

double Shisha::getPrice() const {
    return this->price;
}

char *Shisha::getBrand() const {
    return this->brand;
}

char *Shisha::getTaste() const {
    return this->taste;
}

void Shisha::setBrand(const char *brand) {
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
}

void Shisha::setTaste(const char *taste) {
    this->taste = new char[strlen(taste) + 1];
    strcpy(this->taste, taste);
}

void Shisha::setPrice(double price) {
    this->price = price;
}

void Shisha::print() const {
    cout << "Shisha: " << this->getPrice() << " " << this->getBrand() << " " << this->getTaste() << endl;
}

void Shisha::dealocate() {
    delete[] this->brand;
    delete[] this->taste;
}

void Shisha::increasePrice(double amount) {
    this->setPrice(this->price + amount);
}

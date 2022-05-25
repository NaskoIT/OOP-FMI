#ifndef EXAM_2020_PROTECTEDARRAY_H
#define EXAM_2020_PROTECTEDARRAY_H

#include <iostream>
#include "ProtectedValue.h"

using namespace std;

const int INITIAL_ARRAY_COUNT = 8;

template<typename T>
class ProtectedArray {
private:
    ProtectedValue<T> *values;
    int size;
    int capacity;

    void resize();

    void copyValues(const  ProtectedArray<T> &other);

public:
    ProtectedArray() : size(0), capacity(INITIAL_ARRAY_COUNT) {
        this->values = new ProtectedValue<T>[this->capacity];
    }

    ProtectedArray(const ProtectedArray<T> &other) : size(other.size), capacity(other.capacity) {
        this->values = new ProtectedValue<T>[other.capacity];
        copyValues(other);
    }

    ProtectedArray<T> &operator=(const ProtectedArray<T> &other) {
        if (this != &other) {
            this->size = other.size;
            this->capacity = other.capacity;

            delete[] this->values;
            this->values = new ProtectedValue<T>[other.capacity];
            copyValues(other);
        }

        return *this;
    }

    ~ProtectedArray() {
        delete[] this->values;
    }

    void add(const T &value, int code) {
        if (size == capacity) {
            resize();
        }

        values[this->size] = ProtectedValue<T>(value, code);
        this->size++;
    }

    T &get(const int index, const unsigned int code) {
        if (index < 0 || index >= size) {
            throw invalid_argument("Out of range exception!");
        }

        try {
            return values[index].getValue(code);
        } catch (const std::invalid_argument &ex) {
            cout << "Code was wrong !";
            return T();
        }
    }
};

template<typename T>
void ProtectedArray<T>::resize() {
    this->capacity *= 2;
    ProtectedArray<T> newValues = new ProtectedArray<T>[this->capacity];

    for (int i = 0; i < size; ++i) {
        newValues[i] = this->values[i];
    }

    delete[] this->values;
    this->values = newValues;
}

template<typename T>
void ProtectedArray<T>::copyValues(const ProtectedArray<T> &other) {
    for (int i = 0; i < other.size; ++i) {
        this->values[i] = other.values[i];
    }
}

#endif //EXAM_2020_PROTECTEDARRAY_H

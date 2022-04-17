#ifndef DEMOS_ALCOHOLSTORE_H
#define DEMOS_ALCOHOLSTORE_H

#include <iostream>
#include "Alcohol.h"
#include "global-constants.h"

using namespace std;

class AlcoholStore {
private:
    int count;
    int allocatedCellsCount;
    Alcohol *data;

    void resize() {
        this->allocatedCellsCount *= 2;
        Alcohol *newData = new Alcohol[this->allocatedCellsCount];

        for (int i = 0; i < this->count; ++i) {
            newData[i] = this->data[i];
        }

        delete[] this->data;
        this->data = newData;
    }

    void copy(const AlcoholStore &other) {
        this->allocatedCellsCount = other.allocatedCellsCount;
        this->count = other.count;
        this->data = new Alcohol[other.allocatedCellsCount];

        for (int i = 0; i < other.count; ++i) {
            this->data[i] = other.data[i];
        }
    }

public:
    AlcoholStore() {
        this->count = 0;
        this->allocatedCellsCount = DEFAULT_ALLOCATED_CELLS;
        this->data = new Alcohol[DEFAULT_ALLOCATED_CELLS];
    }

    AlcoholStore(const AlcoholStore &other) {
        copy(other);
    }

    AlcoholStore &operator=(const AlcoholStore &other) {
        if (this != &other) {
            if (this->data != nullptr) {
                delete[] this->data;
            }

            copy(other);
        }

        return *this;
    }

    ~AlcoholStore() {
        delete[] this->data;
    }

    void add(const Alcohol& value) {
        if (this->count == allocatedCellsCount) {
            this->resize();
        }

        this->data[count] = value;
        this->count++;
    }

    void print() {
        for (int i = 0; i < count; ++i) {
            this->data[i].print();
        }

        cout << endl;
    }

    int size() const {
        return this->count;
    }
};

#endif //DEMOS_ALCOHOLSTORE_H

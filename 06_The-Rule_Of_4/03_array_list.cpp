#include <iostream>

using namespace std;

const int DEFAULT_ALLOCATED_CELLS = 8;

class ArrayList {
private:
    int count;
    int allocatedCellsCount;
    int *data;

    void resize() {
        this->allocatedCellsCount *= 2;
        int *newData = new int[this->allocatedCellsCount];

        for (int i = 0; i < this->count; ++i) {
            newData[i] = this->data[i];
        }

        delete[] this->data;
        this->data = newData;
    }

    void copy(const ArrayList &other) {
        this->allocatedCellsCount = other.allocatedCellsCount;
        this->count = other.count;
        this->data = new int[other.allocatedCellsCount];

        for (int i = 0; i < other.count; ++i) {
            this->data[i] = other.data[i];
        }
    }

public:
    ArrayList() {
        this->count = 0;
        this->allocatedCellsCount = DEFAULT_ALLOCATED_CELLS;
        this->data = new int[DEFAULT_ALLOCATED_CELLS];
    }

    ArrayList(const ArrayList &other) {
        copy(other);
    }

    ArrayList &operator=(const ArrayList &other) {
        if (this != &other) {
            if (this->data != nullptr) {
                delete[] this->data;
            }

            copy(other);
        }

        return *this;
    }

    ~ArrayList() {
        delete[] this->data;
    }

    void push_back(const int value) {
        if (this->count == allocatedCellsCount) {
            this->resize();
        }

        this->data[count] = value;
        this->count++;
    }

    void print() {
        for (int i = 0; i < count; ++i) {
            cout << this->data[i] << " ";
        }

        cout << endl;
    }

    int size() const {
        this->count;
    }
};

int main() {
    ArrayList list;
    for (int i = 0; i < 10; ++i) {
        list.push_back(i * 2);
    }

    list.print();
}




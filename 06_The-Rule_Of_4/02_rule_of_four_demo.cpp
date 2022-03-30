#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Lecturer {
private:
    char *name;

public:
    // Default constructor
    Lecturer() {
        this->name = nullptr;
    }

    // Constructor with one argument
    Lecturer(char *newName) {
        this->setName(newName);
    }

    // Copy constructor
    Lecturer(const Lecturer &other) {
        // Allocate new memory for the name
        this->setName(other.name);
    }

    // Assignment operator=
    Lecturer &operator=(const Lecturer &other) {
        // Check of the instances are the same
        if (this != &other) {
            // Deallocate the current dynamic memory, if any
            if (this->name != nullptr) {
                delete[] this->name;
            }

            // Allocate new memory and set the name
            this->setName(other.name);
        }

        return *this;
    }

    // Destructor
    ~Lecturer() {
        delete[] this->name;
    }

    void setName(const char *newName) {
        if(newName == nullptr) {
            this->name = nullptr;
            return;
        }

        this->name = new char[strlen(newName) + 1];
        strcpy(this->name, newName);
    }

    void print() const {
        cout << "Lecturer: " << this->name << endl;
    }
};

int main() {
    // Invokes constructor with one argument
    Lecturer lecturer("Nasko");
    lecturer.print();

    // Invokes the copy constructor
    Lecturer copy = lecturer;
    copy.print();

    Lecturer second("New version");

    // Invokes operator=
    lecturer = second;
    lecturer.print();

    // Invokes the operator=, but the instances are the same => do nothing with the dynamic memory
    lecturer = lecturer;
    lecturer.print();

    // Invokes default constructor
    Lecturer defaultLecturer;

    defaultLecturer = lecturer;
}




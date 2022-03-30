#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Lecturer {
public:
    string name;
    static int instances;

    Lecturer() {
    }

    Lecturer(string newName) {
        this->name = newName;
        Lecturer::instances++;
        cout << "Constructor invoked for:" << this->name << endl;
    }

    ~Lecturer() {
        Lecturer::instances--;
        cout << "Destructor invoked for: " << this->name << endl;
    }
};

int Lecturer::instances = 0;

void test() {
    Lecturer first("Nasko"), second("Stoysho"), third("Nikola");

    vector<Lecturer> lecturers;
    lecturers.push_back(first);
    lecturers.push_back(second);
    lecturers.push_back(third);
}

int main() {
    test();

    cout << Lecturer::instances << endl;
}




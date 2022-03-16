#include <iostream>
#include <cstring>

using namespace std;

struct Person {
    char *name;
    int age;
    double weight;

    Person() {
        name = new char[1];
        strcpy(name, "");
        age = 0;
        weight = 0;
    }

    Person(char *name, int age, double newWeight)
            : age(age), weight(newWeight) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void print() {
        cout << this->name << " -> " << this->age << " -> " << this->weight << endl;
    }
};

int main() {
    Person defaultPerson;
    defaultPerson.print();

    Person person("Ivan", 10, 30);
    person.print();
}
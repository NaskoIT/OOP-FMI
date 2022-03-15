#include <iostream>
#include <cstring>

using namespace std;

const int MAX_NAME_SIZE = 50;

struct Person
{
    char name[MAX_NAME_SIZE];
    int age;
    double weight;
};

void printPerson(const Person& person)
{
    std::cout << "My name is " << person.name << ". I am " << person.age << 
                    " years old and I am " << person.weight << " kg." << std::endl;
}

int main ()
{
    Person* dynamicallyAllocatedPerson = new Person; // allocating memory for a Person instance

    // initialization, note the access operator for pointers!
    strcpy(dynamicallyAllocatedPerson->name, "Bat Ivan");

    (*dynamicallyAllocatedPerson).age = 20; // also a valid synta
    dynamicallyAllocatedPerson->age = 20; // clearer syntax
    dynamicallyAllocatedPerson->weight = 81.2;

    printPerson(*dynamicallyAllocatedPerson);

    delete dynamicallyAllocatedPerson; // do not forget to deallocate!
    
    return 0;
}
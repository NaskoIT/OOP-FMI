#include <iostream>
#include <cstring>

using namespace std;

const int MAX_NAME_SIZE = 50;
const int DEFAULT_NUMBER_OF_PEOPLE = 3;

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

void initialize(Person& person, const char* name, int age, double weight)
{
    strcpy(person.name, name);
    person.age = age;
    person.weight = weight;
}

int main ()
{
    Person people[DEFAULT_NUMBER_OF_PEOPLE]; // creating an array of Person instances

    // note that we can extract the initialization of the struct instance in a separate function
    initialize(people[0], "Ivan", 20, 82.4);
    initialize(people[1], "Georgi", 22, 73.4);
    initialize(people[2], "Atanas", 20, 68.2);

    // printing information
    for (int i = 0; i < DEFAULT_NUMBER_OF_PEOPLE; ++i)
    {
        printPerson(people[i]);
    }

    std::cout << std::endl;

    Person* dynamicallyAllocatedPeople = new Person[DEFAULT_NUMBER_OF_PEOPLE];
    // initialization
    initialize(dynamicallyAllocatedPeople[0], "Dynamic Ivan", 20, 82.4);
    initialize(dynamicallyAllocatedPeople[1], "Dynamic Georgi", 22, 73.4);
    initialize(dynamicallyAllocatedPeople[2], "Dynamic Atanas", 20, 68.2);

    for (std::size_t i = 0; i < DEFAULT_NUMBER_OF_PEOPLE; ++i)
    {
        printPerson(dynamicallyAllocatedPeople[i]);
    }

    delete[] dynamicallyAllocatedPeople; // do not forget to deallocate!

    return 0;
}
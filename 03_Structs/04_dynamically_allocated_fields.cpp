#include <iostream>
#include <cstring>

using namespace std;

struct Teacher
{
    char* name;
    char* subject;
};

void initialize(Teacher& teacher, const char* name, const char* subject)
{
    teacher.name = new char[strlen(name) + 1];
    strcpy(teacher.name, name);

    teacher.subject = new char[strlen(subject) + 1];
    strcpy(teacher.subject, subject);
}

void print(const Teacher& teacher)
{
    cout << "My name is " << teacher.name << " and I am teaching " << teacher.subject << "." << endl;
}

void deallocate(const Teacher& teacher)
{
    delete[] teacher.name;
    delete[] teacher.subject;
}

int main ()
{
    Teacher teacher;

    initialize(teacher, "Atanas Vasilev", "OOP");
    print(teacher);
    deallocate(teacher);

    Teacher* dynamicallyAllocatedTeacher = new Teacher;

    initialize(*dynamicallyAllocatedTeacher, "Babev", "DIS2");
    print(*dynamicallyAllocatedTeacher);

    // note that you should first deallocate the fields of the struct instance, 
    // and only then to deallocate the dynamically allocated struct instance itself
    deallocate(*dynamicallyAllocatedTeacher);
    delete dynamicallyAllocatedTeacher;

    return 0;
}
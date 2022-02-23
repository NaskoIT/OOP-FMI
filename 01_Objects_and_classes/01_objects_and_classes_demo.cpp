#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string NATIONALITIES_NAMES[4] = {"Bulgaria", "Germany", "Greece", "Serbia"};

enum Nationality {
    Bulgaria,
    Germany,
    Greece,
    Serbia
};

string getNationalityName(Nationality nationality) {
    return NATIONALITIES_NAMES[(int) nationality];
}

class Person {
public:
    string name;
    int year;
    Nationality nationality;

    void print() {
        cout << name << " " << year << " " << getNationalityName(nationality) << endl;
    }
};

// Sample input
// ivan
// 2000
// 2
// dragan
// 2001
// 3
// 2000
// Output:
// ivan 2000 Greece
int main() {
    int n;
    cin >> n;

    vector<Person> people;
    for (int i = 0; i < n; ++i) {
        Person person;
        cin >> person.name;
        cin >> person.year;
        int nationality;
        cin >> nationality;
        person.nationality = (Nationality) nationality;

        people.push_back(person);
    }

    int targetYear;
    cin >> targetYear;
    for (Person &person : people) {
        if (person.year == targetYear) {
            person.print();
        }
    }
}
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_PRODUCTS_COUNT = 1000;
const int NOT_FOUND = -1;

enum Color {
    Red,
    Green,
    Blue,
    Yellow,
    White,
    Black
};

class Baloon {
private:
    double price;
    Color color;

public:
    Baloon() {
        this->price = 0;
        this->color = Red;
    }

    Baloon(double price, Color color)
            : price(price), color(color) {}

    double getPrice() const {
        return price;
    }

    Color getColor() const {
        return color;
    }

    void setPrice(double price) {
        this->price = price;
    }

    void setColor(Color color) {
        this->color = color;
    }

    void print() const {
        cout << "Baloon: " << this->getPrice() << " " << this->getColor() << endl;
    }
};

class Shisha {
private:
    double price;
    char *brand;
    char *taste;

public:
    Shisha() {
        this->price = 0;
        this->brand = nullptr;
        this->taste = nullptr;
    }

    Shisha(double price, const char *brand, const char *taste)
            : price(price) {
        this->setBrand(brand);
        this->setTaste(taste);
    }

    ~Shisha() {
        delete[] this->brand;
        delete[] this->taste;
    }

    double getPrice() const {
        return this->price;
    }

    char *getBrand() const {
        return this->brand;
    }

    char *getTaste() const {
        return this->taste;
    }

    void setBrand(const char *brand) {
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
    }

    void setTaste(const char *taste) {
        this->taste = new char[strlen(taste) + 1];
        strcpy(this->taste, taste);
    }

    void setPrice(double price) {
        this->price = price;
    }

    void print() const {
        cout << "Shisha: " << this->getPrice() << " " << this->getBrand() << " " << this->getTaste() << endl;
    }

    void dealocate() {
        delete[] this->name;
    }

    void increasePrice(double amount);
};

void Shisha::increasePrice(double amount) {
    this->setPrice(this->price + amount);
}

class Alcohol {
private:
    double price;
    char *name;

public:
    Alcohol() {
        this->price = 0;
        this->name = nullptr;
    }

    Alcohol(const double price, const char *name) {
        this->price = price;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    ~Alcohol() {
        delete[] this->name;
    }

    void print() const {
        cout << "Alcohol: " << this->name << " " << this->price << endl;
    }
};

class NightClub {
private:
    char *name;
    int availableBaloons = 0;
    int availableShishas = 0;
    int availableAlcohols = 0;
    Baloon *ballons;
    Shisha *shishas;
    Alcohol *alcohols;

public:
    NightClub(const char *name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->ballons = new Baloon[MAX_PRODUCTS_COUNT];
        this->shishas = new Shisha[MAX_PRODUCTS_COUNT];
        this->alcohols = new Alcohol[MAX_PRODUCTS_COUNT];
    }

    void addBaloon(Baloon baloon) {
        this->ballons[availableBaloons++] = baloon;
    }

    void addShisha(Shisha shisha) {
        this->shishas[availableShishas++] = shisha;
    }

    void addAlcohol(Alcohol alcohol) {
        this->alcohols[availableAlcohols] = alcohol;
    }

    void removeBallon(Color color) {
        int index = NOT_FOUND;
        for (int i = 0; i < availableBaloons; ++i) {
            if (ballons[i].getColor() == color) {
                index = i;
            }
        }

        if (index == NOT_FOUND) {
            cout << "There is no such a baloon in the club" << endl;
            return;
        }

        for (int i = index; i < availableBaloons; ++i) {
            ballons[i] = ballons[i + 1];
        }

        availableBaloons--;
        ballons[availableBaloons] = Baloon();
    }
};

int main() {
//    Shisha shisha(30, "Narga", "chocolate");
//    shisha.print();
    Shisha *shisha = new Shisha(30, "Some_brand", "Some_taste");
    shisha->print();
    delete shisha;

    Baloon baloon(5, Red);
    baloon.print();
}




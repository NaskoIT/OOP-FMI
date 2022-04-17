#ifndef DEMOS_SHISHA_H
#define DEMOS_SHISHA_H

class Shisha {
private:
    double price;
    char* brand;
    char* taste;

    void copyFields(const Shisha &other);
public:
    Shisha();

    Shisha(double price, const char *brand, const char *taste);

    Shisha(const Shisha &other);

    Shisha &operator=(const Shisha &other);

    ~Shisha();

    double getPrice() const;

    char *getBrand() const;

    char *getTaste() const;

    void setBrand(const char *brand);

    void setTaste(const char *taste);

    void setPrice(double price);

    void print() const;

    void dealocate();

    void increasePrice(double amount);
};

#endif //DEMOS_SHISHA_H

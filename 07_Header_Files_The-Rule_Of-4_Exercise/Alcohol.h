#ifndef DEMOS_ALCOHOL_H
#define DEMOS_ALCOHOL_H

class Alcohol {
private:
    double price;
    char *name;

public:
    Alcohol();

    Alcohol(const double price, const char *name);

    ~Alcohol();

    Alcohol(const Alcohol &other);

    Alcohol &operator=(const Alcohol &other);

    void setName(const char *name);

    void print() const;
};

#endif //DEMOS_ALCOHOL_H

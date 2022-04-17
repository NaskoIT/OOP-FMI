#ifndef DEMOS_BALLOON_H
#define DEMOS_BALLOON_H

#include "Color.h"

class Balloon {
private:
    double price;
    Color color;

public:
    Balloon();

    Balloon(double price, Color color);

    double getPrice() const;

    Color getColor() const;

    void setPrice(double price);

    void setColor(Color color);

    void print() const;
};

#endif //DEMOS_BALLOON_H

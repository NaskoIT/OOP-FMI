#include <iostream>
#include <string>

using namespace std;

const int NOT_FOUND = -1;

struct Sale {
    string product;
    string town;
    double price;
    double quantity;
};

struct Profit {
    string town;
    double income;
};

int indexOf(const Profit *profits, int count, const string &town) {
    for (int i = 0; i < count; ++i) {
        if (profits[i].town == town) {
            return i;
        }
    }

    return NOT_FOUND;
}

void swap(Profit &a, Profit &b) {
    Profit tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(Profit *profits, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++)
            if (profits[j].town > profits[j + 1].town)
                swap(profits[j], profits[j + 1]);
    }
}

int main() {
    int n;
    cin >> n;

    Profit *profits = new Profit[n];
    int profitsCount = 0;

    for (int i = 0; i < n; ++i) {
        string town, product;
        double price;
        double quantity;
        cin >> town >> product >> price >> quantity;

        int index = indexOf(profits, profitsCount, town);
        if (index == NOT_FOUND) {
            Profit profit;
            profit.town = town;
            profit.income = price * quantity;
            profits[profitsCount++] = profit;
        } else {
            profits[index].income += price * quantity;
        }
    }


    bubbleSort(profits, profitsCount);

    cout.precision(2);
    for (int i = 0; i < profitsCount; ++i) {
        cout << profits[i].town << " -> " << fixed << profits[i].income << endl;
    }

    delete[] profits;
}

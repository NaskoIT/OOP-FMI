#include <iostream>
#include <string>
#include <vector>

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

int indexOf(vector<Profit> profits, const string &town) {
    for (int i = 0; i < profits.size(); ++i) {
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

void bubbleSort(vector<Profit>& profits) {
    for (int i = 0; i < profits.size() - 1; i++) {
        for (int j = 0; j < profits.size() - i - 1; j++)
            if (profits[j].town > profits[j + 1].town)
                swap(profits[j], profits[j + 1]);
    }
}

int main() {
    int n;
    cin >> n;

    vector<Profit> profits;

    for (int i = 0; i < n; ++i) {
        string town, product;
        double price;
        double quantity;
        cin >> town >> product >> price >> quantity;

        int index = indexOf(profits, town);
        if (index == NOT_FOUND) {
            Profit profit;
            profit.town = town;
            profit.income = price * quantity;
            profits.push_back(profit);
        } else {
            profits[index].income += price * quantity;
        }
    }


    bubbleSort(profits);

    cout.precision(2);
    for (int i = 0; i < profits.size(); ++i) {
        cout << profits[i].town << " -> " << fixed << profits[i].income << endl;
    }
}

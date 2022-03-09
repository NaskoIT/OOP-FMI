#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

//    bool operator<(const Profit& other) const {
//        return this->town < other.town;
//    }
};

int indexOf(vector<Profit> profits, const string &town) {
    for (int i = 0; i < profits.size(); ++i) {
        if (profits[i].town == town) {
            return i;
        }
    }

    return NOT_FOUND;
}

bool comparator(Profit& a, Profit& b) {
    return a.town < b.town;
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

    sort(profits.begin(), profits.end(), [](Profit& a, Profit& b) { return a.town < b.town; });
    // sort(profits.begin(), profits.end(), comparator);

    cout.precision(2);
    for (int i = 0; i < profits.size(); ++i) {
        cout << profits[i].town << " -> " << fixed << profits[i].income << endl;
    }
}

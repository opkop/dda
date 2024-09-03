#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int value, weight;
};

bool cmp(const Item& a, const Item& b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int W, Item items[], int n) {
    sort(items, items + n, cmp);
    
    double totalValue = 0.0;
    for (int i = 0; i < n; ++i) {
        if (W <= 0) break;
        if (items[i].weight <= W) {
            totalValue += items[i].value;
            W -= items[i].weight;
        } else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            W = 0;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: "; cin >> n;
    Item items[n];
    for (int i = 0; i < n; ++i) {
        int value, weight;
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> value >> weight;
        items[i].value = value;
        items[i].weight = weight;
    }
    cout << "Enter capacity of knapsack: "; cin >> W;

    double max_value = fractionalKnapsack(W, items, n);
    cout << "Maximum value in knapsack: " << max_value << endl;

    return 0;
}

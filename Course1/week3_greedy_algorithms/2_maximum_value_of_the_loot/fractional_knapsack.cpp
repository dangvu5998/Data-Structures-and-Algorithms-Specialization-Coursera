#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using std::vector;
using namespace std;

struct Item {
    float weight;
    float value;
};

bool compareItem(Item item1, Item item2) {
    return item1.value/item1.weight < item2.value/item2.weight;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    int n = weights.size();
    vector<Item> items(n);
    Item item;
    int i;
    for (i = 0; i < n; i++) {
        items[i].weight = weights[i];
        items[i].value = values[i];
    }
    sort(items.begin(), items.end(), compareItem);
    i = n - 1;
    while (capacity > 0 && i >= 0) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            value += items[i].value;
        }
        else {
            value += capacity * (items[i].value/items[i].weight);
            capacity = 0;
        }
        i -= 1;
    }
    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }
  
    double optimal_value = get_optimal_value(capacity, weights, values);
  
    std::cout.precision(10);
    std::cout << fixed << setprecision(4) << optimal_value << std::endl;
    return 0;
}

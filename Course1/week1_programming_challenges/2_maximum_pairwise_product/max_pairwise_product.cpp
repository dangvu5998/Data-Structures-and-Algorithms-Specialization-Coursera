#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    int h = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if(numbers[h] < numbers[i])
            h = i;
    }
    if(h == 0) k = 1;
    for (int i = 0; i < n; i++) {
        if(h != i && numbers[k] < numbers[i])
            k = i;
    }
    max_product =(((long long) (numbers[h])))*(((long long) (numbers[k])));

    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int i = 0;
  while (n > 0) {
      i++;
      if (n <= i*2) {
          summands.push_back(n);
          n = 0;
      } else {
          summands.push_back(i);
          n -= i;
      }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}

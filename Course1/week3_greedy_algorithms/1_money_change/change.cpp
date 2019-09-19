#include <iostream>

int get_change(int m) {
  //write your code here

    int c = 0;
    if (m >= 10) c += m / 10;
    m = m % 10;
    if (m >= 5) c += m / 5;
    m = m % 5;
    return c + m;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

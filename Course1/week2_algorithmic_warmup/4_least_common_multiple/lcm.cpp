#define ll long long
#include <iostream>


int gcd(int a, int b) {
    if(b == 0)
        return a;
    if(b > a)
        return gcd(b, a);
    return gcd(b, a % b);
}

ll lcm(int a, int b) {
    ll gcdResult = gcd(a, b);
    ll x = a;
    ll y = b;
    return x*y/gcdResult;

}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}

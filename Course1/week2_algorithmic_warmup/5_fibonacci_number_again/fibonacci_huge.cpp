#define ll long long
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

ll get_fibonacci_huge_naive(ll n, ll m) {
    if (n <= 1)
        return n;

    ll previous = 0;
    ll current  = 1;

    vector<ll> fib_mod;
    ll i;
    for (i = 0; i < n - 1; ++i) {
        fib_mod.push_back(previous);
        ll tmp_previous = previous;
        previous = current;
        current = (tmp_previous%m + current%m)%m;
        if(previous % m == 0 && current%m == 1)
            break;
    }
    if (i == n - 1)
        return current % m;
    return fib_mod[n%fib_mod.size()];
}

int main() {
    ll n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}

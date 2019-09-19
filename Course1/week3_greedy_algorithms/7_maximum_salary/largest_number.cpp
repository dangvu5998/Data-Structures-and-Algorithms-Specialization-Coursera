#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool stringCmp(string s1, string s2) {
    string c1 = s1 + s2;
    string c2 = s2 + s1;
    return c1 < c2;
}
        
string largest_number(vector<string> a) {
    sort(a.begin(), a.end(), stringCmp);
    std::stringstream ret;
    for (int i = a.size() - 1; i >= 0; i--) {
        ret << a[i];
    }
    string result;
    ret >> result;
    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
}

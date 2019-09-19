#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int i = 0, n = stops.size(), refills_count = 0;
    int current_stop = 0;
    while (i < n) {
        if (current_stop + tank >= dist) {
            current_stop = dist;
            break;
        }
        while (i < n - 1 && current_stop + tank >= stops[i + 1])
            i++;
        if (stops[i] != current_stop) {
            current_stop = stops[i];
            refills_count++;
        }
        else {
            break;
        }
    }
    if (current_stop < dist) 
        return -1;
    else
        return refills_count;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

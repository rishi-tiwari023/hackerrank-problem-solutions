#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> indices(100);
    int n, i, j, x, f;

    cin >> n;
    string ar[n];

    for (i = 0; i < n; i++) {
        cin >> x >> ar[i];
        indices[x].push_back(i);
    }

    j = n / 2;
    f = 1;
    for (i = 0; i < 100; i++) {
        for (vector<int>::iterator it = indices[i].begin(); it != indices[i].end(); it++) {
            x = *it;
            if (f == 1) {
                f = 0;
            } else {
                cout << ' ';
            }
            if (x < n / 2) {
                cout << '-';
            } else {
                cout << ar[x];
            }
        }
    }

    return 0;
}



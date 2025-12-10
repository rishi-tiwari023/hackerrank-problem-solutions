#include <bits/stdc++.h>
using namespace std;

int main() {
    long long q;
    cin >> q;
    for (long long a0 = 0; a0 < q; a0++) {
        long long x;
        cin >> x;
        long long length = 1;
        long long powerOf2 = 1;
        while (powerOf2 < x) {
            powerOf2 *= 2;
            length++;
        }
        powerOf2 = 1;
        long long numSatisfying = x - 1;
        for (long long i = 0; i < length; i++) {
            if (x & powerOf2) {
                numSatisfying -= min(powerOf2, x - powerOf2);
            }
            powerOf2 *= 2;
        }
        cout << numSatisfying << "\n";
    }
    return 0;
}


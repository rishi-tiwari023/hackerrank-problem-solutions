#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void solve() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N), B(N);
    for (int i=0; i<N; ++i)
        cin >> A[i];
    for (int i=0; i<N; ++i)
        cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    bool res=true;
    for (int i=0; i<N; ++i)
        res &= ((A[i]+B[i]) >= K);
    
    if (res)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    int T;
    cin >> T;
    
    while (T--)
        solve();
    
    return 0;
}

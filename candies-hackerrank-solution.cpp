#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, vector<int> arr) {
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    
    // Left to right pass - ensure each child has more candies than left neighbor if rating is higher
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
    }
    
    // Right to left pass - ensure each child has more candies than right neighbor if rating is higher
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
    }
    
    // Take maximum of both passes for each position
    long total = 0;
    for (int i = 0; i < n; i++) {
        total += max(left[i], right[i]);
    }
    
    return total;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        arr[i] = arr_item;
    }
    
    long result = candies(n, arr);
    
    fout << result << "\n";
    
    fout.close();
    
    return 0;
}

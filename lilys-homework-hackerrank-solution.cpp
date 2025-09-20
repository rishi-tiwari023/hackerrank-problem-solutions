#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> arr) {
    int n = arr.size();
    vector<int> sorted_asc = arr;
    vector<int> sorted_desc = arr;
    
    sort(sorted_asc.begin(), sorted_asc.end());
    sort(sorted_desc.begin(), sorted_desc.end(), greater<int>());
    
    // Function to count minimum swaps to transform arr to target
    auto countSwaps = [](vector<int> arr, vector<int> target) -> int {
        int n = arr.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[arr[i]] = i;
        }
        
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != target[i]) {
                int targetPos = pos[target[i]];
                swap(arr[i], arr[targetPos]);
                pos[arr[targetPos]] = targetPos;
                pos[arr[i]] = i;
                swaps++;
            }
        }
        return swaps;
    };
    
    // Count swaps for both ascending and descending order
    int swaps_asc = countSwaps(arr, sorted_asc);
    int swaps_desc = countSwaps(arr, sorted_desc);
    
    return min(swaps_asc, swaps_desc);
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
    
    int result = lilysHomework(arr);
    
    fout << result << "\n";
    
    fout.close();
    
    return 0;
}

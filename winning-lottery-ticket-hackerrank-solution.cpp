#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'winningLotteryTicket' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts STRING_ARRAY tickets as parameter.
 */

long winningLotteryTicket(vector<string> tickets) {
    int n = tickets.size();
    long count = 0;
    
    // For each pair of tickets, check if they contain all digits 0-9
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if tickets[i] and tickets[j] together contain all digits 0-9
            bool digits[10] = {false};
            
            // Mark digits present in first ticket
            for (char c : tickets[i]) {
                if (c >= '0' && c <= '9') {
                    digits[c - '0'] = true;
                }
            }
            
            // Mark digits present in second ticket
            for (char c : tickets[j]) {
                if (c >= '0' && c <= '9') {
                    digits[c - '0'] = true;
                }
            }
            
            // Check if all digits 0-9 are present
            bool allDigitsPresent = true;
            for (int k = 0; k < 10; k++) {
                if (!digits[k]) {
                    allDigitsPresent = false;
                    break;
                }
            }
            
            if (allDigitsPresent) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    vector<string> tickets(n);
    
    for (int i = 0; i < n; i++) {
        string tickets_item;
        getline(cin, tickets_item);
        tickets[i] = tickets_item;
    }
    
    long result = winningLotteryTicket(tickets);
    
    fout << result << "\n";
    
    fout.close();
    
    return 0;
}

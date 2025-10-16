#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, i, a[100][26] = {0}, j;
    string b;
    cin >> n;
    cin.ignore();
    for(i = 0; i < n; i++){
        getline(cin, b);
        for(j = 0; b[j] != '\0'; j++){
            a[i][b[j]-'a']++;
        }
    }
    int countGem = 0, missingFlag;
    for(j = 0; j < 26; j++){
        missingFlag = 0;
        for(i = 0; i < n; i++){
            if(a[i][j] == 0)
                missingFlag = 1;
        }
        if(missingFlag == 0)
            countGem++;
    }
    cout << countGem;
    return 0;
}



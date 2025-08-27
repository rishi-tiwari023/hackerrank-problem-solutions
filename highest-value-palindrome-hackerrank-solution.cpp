#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code  here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    bool ok =true;
    int c = 0;
    for(int i=0;i<n/2;i++){
        if(str[i]!=str[n-i-1])c++;
    }
    if(c > k){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n/2;i++){
        if(str[i]!=str[n-i-1]){
            if(max(str[i] ,str[n-i-1]) == '9') {
                str[i] = str[n-i-1] = '9'; k--; c--;
            }
            else if(k > c){
                str[i] = str[n-i-1] = '9'; k-=2; c--; 
            }
            else{
                str[i] = str[n-i-1] =max(str[i] ,str[n-i-1]) ; k--; c--;
            }
        }else{
            if(max(str[i] ,str[n-i-1]) == '9') {
                continue;
            }
            else if(k > c+1){
                str[i] = str[n-i-1] = '9'; k-=2;
            }
        }
    }
    
    if(k && n%2==1) str[n/2] = '9';
    cout<<str<<endl;
    return 0;
}

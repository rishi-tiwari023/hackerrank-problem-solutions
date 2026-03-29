#include <bits/stdc++.h>
using namespace std;

vector<long long> queries;
map<long long, long long> dp;

long long max(long long a, long long b) {
  if (a>b) {
    return a;
  }
  return b;
}

bool isNotDivisible(long long count, long long query) {
  return (count % query != 0) || count == query;
}

// top bottom dp
long long solve(long long countOfStones) {
  if (countOfStones <= 1) {
    return 0;
  }
  if (dp[countOfStones] != 0) {
    return dp[countOfStones];
  }
  long long maxCount = 0;
  for (long long i=0;i<queries.size();i++) {
    long long query = queries[i];
    if (isNotDivisible(countOfStones, query)) {
      continue;
    }
    long long countOfDividedStonesByQuery = countOfStones / query;
    long long sumOfNextDivisionByRemainingStones = countOfDividedStonesByQuery * solve(query);
    long long sum = 1 + sumOfNextDivisionByRemainingStones;
    maxCount = max(maxCount, sum);
  }
  dp[countOfStones] = maxCount;
  return maxCount;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    long long countOfStones, countOfQueries;
    cin>>countOfStones>>countOfQueries;
    for(int i=0;i<countOfQueries;i++) {
      long long query;
      cin>>query;
      queries.push_back(query);
    }
    cout<<solve(countOfStones)<<endl;
    queries.clear();
    dp.clear();
  }
  return 0;
}

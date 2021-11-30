#include <iostream>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

priority_queue<ll> pq;

void push235(ll n) {
  pq.push(-2*n);
  pq.push(-3*n);
  pq.push(-5*n);
  return;
}

int main() {
  int n;
  cin >> n;
  vector<ll> dp(n);

  dp[0] = 1;
  push235(dp[0]);

  for(int i=1; i<n; i++) {
    do {
      dp[i] = -pq.top();
      pq.pop();
    } while(dp[i] == dp[i-1]);
    push235(dp[i]);
  }

  for(int i=0; i<n; i++) {
    cout << dp[i] << " ";
  }
  cout << '\n';
  cout << dp[n-1] << '\n';

  return 0;
}

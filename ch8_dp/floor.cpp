#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> dp(N+1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 3;
  for(int i=3; i<N+1; i++) {
    dp[i] = dp[i-1] + 2*dp[i-2];
  }

  cout << dp[N] << '\n';
}


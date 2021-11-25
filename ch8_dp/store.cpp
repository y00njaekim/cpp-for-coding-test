#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, K;
  cin >> N;
  vector<int> store;
  vector<int> dp(N, 0);
  for(int i=0; i<N; i++) {
    cin >> K;
    store.push_back(K);
  }
  for(int i=0; i<N; i++) {
    int tmp1 = (i-1 < 0) ? 0 : dp[i-1];
    int tmp2 = (i-2 < 0) ? store[i] : dp[i-2] + store[i];
    dp[i] = max(tmp1, tmp2);
  }

  cout << dp[N-1] << '\n';
}

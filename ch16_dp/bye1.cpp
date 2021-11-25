#include <iostream>
#include <vector>
#define pii pair<int, int>

using namespace std;

int main() {
  int N, T, P;
  cin >> N;
  vector<pii> v;
  vector<int> dp(N+1, 0);
  for(int i=0; i<N; i++) {
    cin >> T >> P;
    v.push_back(make_pair(T, P));
  }
  for(int i=0; i<N+1; i++) {
    int mx = 0;
    for(int j=-5; j<0; j++) {
      if(i+j < 0) continue;
      if(v[i+j].first > -j) continue;
      mx = (mx < dp[i+j] + v[i+j].second) ? dp[i+j] + v[i+j].second : mx;
    }
    dp[i] = (dp[i] < mx) ? mx : dp[i];
  }

  cout << dp[N] << '\n';

  return 0;
}

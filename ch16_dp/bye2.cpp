#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

void updateDp(int i, int val, vector<int>& dp) {
  for(int j=i; j<dp.size(); j++) {
    dp[j] = max(val, dp[j]);
  }
}

int main() {
  int N;
  cin >> N;

  vector<pii> plan;
  vector<int> dp(N+1, 0);
  int t, p;
  for(int i=0; i<N; i++) {
    cin >> t >> p;
    plan.push_back(make_pair(t, p));
  }

  for(int i=0; i<N; i++) {
    int next = i + plan[i].first;
    if(next > N) continue;
    dp[next] = max(dp[next], dp[i]+plan[i].second);
    updateDp(next, dp[next], dp);
  }

  cout << dp[N] << '\n';
  return 0;
}

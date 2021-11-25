#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pii> plan(N+1);
  vector<int> dp(N+2, 0);

  int t, p;
  for(int i=1; i<N+1; i++) {
    cin >> t >> p;
    plan[i] = make_pair(t, p);
  }

  int mx = 0;
  for(int i=N; i>0; i--) {
    int bottomOne = i + plan[i].first;
    int candidate = (bottomOne <= N+1) ? plan[i].second + dp[bottomOne] : 0;
    mx = (mx < candidate) ? candidate : mx;
    dp[i] = mx;
  }

  for(int i=1; i<N+1; i++) {
    cout << i << "/" << dp[i] << " ";
  }
  cout << '\n';
  cout << dp[1] << '\n';
  return 0;
}

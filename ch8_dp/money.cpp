#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> coin;
  vector<int> dp(M);

  int tmp;
  for(int i=0; i<N; i++) {
    cin >> tmp;
    coin.push_back(tmp);
    dp[tmp] = 1;
  }

  bool success = false;
  for(int i=0; i<M+1; i++) {
    if(dp[i] == 0) continue;
    for(int j=0; j<coin.size(); j++) {
      int next = i + coin[j];
      if(next > M) continue;
      dp[next] = (dp[next] != 0) ? min(dp[next], dp[i]+1) : dp[i]+1;
      if(next == M) success = true;
      if(success) break;
    }
    if(success) break;
  }

  int ans = (dp[M] == 0) ? -1 : dp[M];
  cout << ans << '\n';
  return 0;
}

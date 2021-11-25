#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, f;
  cin >> N;

  vector<int> v;
  vector<int> dp(N, 1);

  for(int i=0; i<N; i++) {
    cin >> f;
    v.push_back(f);
  }
  
  int mx = 0;
  for(int i=0; i<N; i++) {
    for(int j=i-1; j>=0; j--) {
      if(v[i] < v[j]) {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    mx = (mx < dp[i]) ? dp[i] : mx;
  }

  cout << N-mx << '\n';
  return 0;
}

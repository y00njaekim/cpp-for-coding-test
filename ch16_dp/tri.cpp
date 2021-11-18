#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int> > tri(n, vector<int>(n, 0));

  int tmp;
  for(int i=0; i<n; i++) {
    for(int j=0; j<i+1; j++) {
      cin >> tmp;
      tri[i][j] = tmp;
    }
  }

  vector<vector<int> > dp = tri;
  for(int r=1; r<n; r++) {
    for(int c=0; c<r+1; c++) {
      int leftUp = (c < 0) ? 0 : dp[r-1][c-1];
      int rightUp = (tri[r-1][c] == 0) ? 0 : dp[r-1][c];
      dp[r][c] = max(leftUp, rightUp) + tri[r][c];
    }
  }

  int mx = 0;
  for(int c=0; c<n; c++) {
    mx = (mx < dp[n-1][c]) ? dp[n-1][c] : mx;
  }

  cout << mx << '\n';
  
  return 0;
}

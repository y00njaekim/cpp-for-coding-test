#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string a;
  int aSize;
  string b;
  int bSize;

  cin >> a >> b;
  aSize = a.size();
  bSize = b.size();

  vector<vector<int> > dp(aSize+1, vector<int>(bSize+1));
  for(int i=0; i<aSize+1; i++) {
    dp[i][0] = i;
  }
  for(int i=0; i<bSize+1; i++) {
    dp[0][i] = i;
  }

  for(int r=1; r<aSize+1; r++) {
    for(int c=1; c<bSize+1; c++) {
      char aC = a[r-1];
      char bC = b[c-1];
      if(aC == bC) {
        dp[r][c] = dp[r-1][c-1];
      } else {
        dp[r][c] = 1 + min(min(dp[r-1][c], dp[r][c-1]), dp[r-1][c-1]);
      }
    }
  }

  cout << dp[aSize][bSize] << '\n';
  return 0;
}

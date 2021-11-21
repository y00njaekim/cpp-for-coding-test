#include <iostream>
#include <vector>

using namespace std;

int main() {
  int X;
  cin >> X;
  vector<int> dp(X+1, 1e9);
  dp[X] = 0;
  for(int x=X; x>0; x--) {
    if(x % 5 == 0) {
      int tar = x/5;
      dp[tar] = (dp[x]+1 < dp[tar]) ? dp[x]+1 : dp[tar]; 
      if(tar == 1) break;
    }
    if(x % 3 == 0) {
      int tar = x/3;
      dp[tar] = (dp[x]+1 < dp[tar]) ? dp[x]+1 : dp[tar]; 
      if(tar == 1) break;
    }
    if(x % 2 == 0) {
      int tar = x/2;
      dp[tar] = (dp[x]+1 < dp[tar]) ? dp[x]+1 : dp[tar]; 
      if(tar == 1) break;
    }
    int tar = x-1;
    dp[tar] = (dp[x]+1 < dp[tar]) ? dp[x]+1 : dp[tar]; 
    if(tar == 1) break;
  }

  cout << dp[1] << '\n';
  return 0;
}

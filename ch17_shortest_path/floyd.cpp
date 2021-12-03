#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > cost(n+1, vector<int>(n+1, -1));
  vector<vector<int> > dp(n+1, vector<int>(n+1, 1e9));

  int a, b, c;
  for(int i=0; i<m; i++) {
    cin >> a >> b >> c;
    if(cost[a][b] < 0) {
      cost[a][b]= c;
    } else {
      cost[a][b] = (c < cost[a][b]) ? c : cost[a][b];
    }
    dp[a][b] = cost[a][b];
  }

  for(int i=1; i<n+1; i++) {
    for(int j=1; j<n+1; j++) {
      //cout << cost[i][j] << " ";
    }
    //cout << '\n';
  } 

  for(int i=1; i<n+1; i++) {
    cout << "The main character is " << i << '\n';
    int t1, t2;
    for(int r=1; r<n+1; r++) {
      cout << "@@@@@ Start point is " << r << '\n';
      if(i == r) continue;
      //bool isOk = true;
      if(cost[r][i] < 0) {
        //isOk = false;
        continue;
      } else {
        t1 = cost[r][i];
      }
      for(int c=1; c<n+1; c++) {
        if(r == c) continue;
        if(i == c) continue;
        cout << "@@@@@ @@@@@ End point is " << c << '\n';
        if(cost[i][c] < 0) {
          //isOk = false;
          continue;
        } else {
          t2 = cost[i][c];
          //if(!isOk) continue;
          int t = t1 + t2;
          //cout << "##### " << "Main is " << i << ", Start is " << r << ", End is " << c << ", cost is " << t << ", dp[r][c] is " << dp[r][c] << " #####" << '\n';
          cout << "##### " << "Main is " << i << ", Start is " << r << ", End is " << c << ", cost is " << t1 << " + " << t2 << ", dp[r][c] is " << dp[r][c] << " #####" << '\n';
          dp[r][c] = (t < dp[r][c]) ? t : dp[r][c];
        }
      }
    }
  }

  for(int r=1; r<n+1; r++) {
    for(int c=1; c<n+1; c++) {
      dp[r][c] = (dp[r][c] == 1e9) ? 0 : dp[r][c];
      cout << dp[r][c] << " ";
    }
    cout << '\n';
  }

  return 0;

    
}

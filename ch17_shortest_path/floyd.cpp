#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dp(n+1, vector<int>(n+1, 1e9));
    for(int i=1; i<=n; i++) {
        dp[i][i] = 0;
    }
    int a, b, c;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        dp[a][b] = (c < dp[a][b]) ? c : dp[a][b];
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dp[i][k] == 1e9) continue;
                if(dp[k][j] == 1e9) continue;
                dp[i][j] = (dp[i][k] + dp[k][j] < dp[i][j]) ? dp[i][k] + dp[k][j] : dp[i][j];
            }
        }
    }
    cout << "n is " << n << '\n';  
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << dp[i][j] << " ";
        }
      cout << '\n';
    }
    
    return 0;
}

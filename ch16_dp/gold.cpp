#include <iostream>
#include <vector>

using namespace std;

int T;

int solution(int n, int m, vector<int> gold1D) {
  vector<vector<int> > gold2D(n, vector<int>(m, 0));
  vector<vector<int> > dpTable(n, vector<int>(m, 0));
  for(int i=0; i<gold1D.size(); i++) {
    int r = i / 4;
    int c = i % 4;
    gold2D[r][c] = gold1D[i];
    if(c == 0) dpTable[r][c] = gold1D[i];
  }

  for(int c=1; c<m; c++) {
    for(int r=0; r<n; r++) {
      int max = 0;
      for(int j=-1; j<2; j++) {
        if(r+j < 0 || r+j >= n) continue;
        int cur = dpTable[r+j][c-1] + gold2D[r][c];
        if(max < cur) max = cur;
      }
      dpTable[r][c] = max;
    }
  }

  int ans = 0;
  for(int r=0; r<n; r++) {
    ans = (ans < dpTable[r][m-1]) ? dpTable[r][m-1] : ans;
  }

  return ans;
}

int main() {
  cin >> T;
  for(int i=0; i<T; i++) {
    int n, m;
    cin >> n >> m;
    vector<int> gold1D;
    int tmp;
    for(int j=0; j<n*m; j++) {
      cin >> tmp;
      gold1D.push_back(tmp);
    }
    int ans = solution(n, m, gold1D);
    cout << ans << '\n';
  }
}

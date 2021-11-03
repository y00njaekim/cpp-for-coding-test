#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<vector<int> > arr;

void DFS(pii X, vector<vector<int> >& trial, vector<vector<bool> >& visited) {
  // cout << "DFS" << endl;
  visited[X.first][X.second] = true;
  trial[X.first][X.second] = (trial[X.first][X.second] == 0) ? 2 : 2;
  for(int i=0; i<4; i++) {
    pii next = make_pair(X.first+dx[i], X.second+dy[i]);
    if(next.first < 0 || next.first >= N) continue;
    if(next.second < 0 || next.second >= M) continue;
    if(visited[next.first][next.second]) continue;
    if(trial[next.first][next.second] == 1) continue;
    DFS(next, trial, visited);
  }
  return;
}

int main() {
  vector<int> ans;

  cin >> N >> M;

  for(int i=0; i<N; i++) {
    vector<int> temp(M);
    arr.push_back(temp);
  }

  int temp;
  for(int r=0; r<N; r++) {
    for(int c=0; c<M; c++) {
    cin >> temp;
    arr[r][c] = temp;
    }
  }
  
  vector<bool> binary(N*M);
  fill(binary.end()-3, binary.end(), true);

  do {
    vector<pii> cand;
    for(int i=0; i<N*M; i++) {
      if(binary[i]) {
        int _r = i / M;
        int _c = i % M;
        cand.push_back(make_pair(_r, _c));
      }
    }

    if(arr[cand[0].first][cand[0].second] != 0) continue;
    if(arr[cand[1].first][cand[1].second] != 0) continue;
    if(arr[cand[2].first][cand[2].second] != 0) continue;

    
    arr[cand[0].first][cand[0].second] = 1;
    arr[cand[1].first][cand[1].second] = 1;
    arr[cand[2].first][cand[2].second] = 1;

    vector<vector<int> > trial = arr;
    vector<vector<bool> > visited(N, vector<bool>(M, false));
    int safeZone = 0;
    for(int r=0; r<N; r++) {
      for(int c=0; c<M; c++) {
        if(trial[r][c] != 2) continue;
        if(visited[r][c]) continue;
        // cout << r << " " << c << endl;
        DFS(make_pair(r, c), trial, visited);
      }
    }
    for(int r=0; r<N; r++) {
      for(int c=0; c<M; c++) {
        if(trial[r][c] == 0) safeZone++; 
      }
    }

    ans.push_back(safeZone);
    /*
    for(int r=0; r<N; r++) {
      for(int c=0; c<M; c++) {
        cout << trial[r][c] << " ";
      }
      cout << endl;
    }
    
    cout << "##########" << endl;
    */

    arr[cand[0].first][cand[0].second] = 0;
    arr[cand[1].first][cand[1].second] = 0;
    arr[cand[2].first][cand[2].second] = 0;
  } while(next_permutation(binary.begin(), binary.end()));

  sort(ans.begin(), ans.end());
  if(ans.size() != 0) cout << ans[ans.size()-1] << endl;
  else cout << 0 << endl;

  return 0;
}

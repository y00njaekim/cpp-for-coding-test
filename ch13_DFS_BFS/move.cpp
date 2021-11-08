#include <iostream>
#include <vector>
#include <cmath>
#define pii pair<int, int>

using namespace std;

int N, L, R;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

vector<vector<int> > land;

/*
vector<vector<int> > adj(int& count) {
  vector<int> adj(N*N);
  for(int r=0; r<N; r++) {
    for(int c=0; c<N; c++) {
      for(int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= N) continue;
        if(nc < 0 || nc >= N) continue;
        int diff = abs(land[r][c] - land[nr][nc]);
        if(L <= diff && diff <= R) {
          adj[r*N + c].push_back(nr*N + nc);
          adj[nr*N + nc].push_back(r*N + c);
          count++;
      }
    }
  }
  return adj;
}
*/

void DFS(pii x, vector<vector<bool> >& visited, vector<pii>& unite, int& totCon, int& totPop) {
  int r = x.first;
  int c = x.second;
  visited[r][c] = true;
  totCon++;
  totPop += land[r][c];
  unite.push_back(make_pair(r, c));
  for(int i=0; i<4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if(nr < 0 || nr >= N) continue;
    if(nc < 0 || nc >= N) continue;
    if(visited[nr][nc]) continue;
    int diff = abs(land[r][c] - land[nr][nc]);
    if(diff < L || R < diff) continue;
    DFS(make_pair(nr, nc), visited, unite, totCon, totPop);
  }
  /*
  for(int i=0; i<adj[x].size(); i++) {
    int ar = adj[x][i] / N;
    int ac = adj[x][i] % N;
    if(visited[ar][ac]) continue;
    DFS(adj[x][i], adj, visited, totCon, totPop);
  }
  */

}

int main() {
  cin >> N >> L >> R;

  int temp;
  for(int i=0; i<N; i++) {
    vector<int> tempV;
    for(int j=0; j<N; j++) {
      cin >> temp;
      tempV.push_back(temp);
    }
    land.push_back(tempV);
  }

  int day = 0;
  while(true) {
  //  cout << "while" << endl;
    bool isBreak = true;
    /*
    int count = 0;
    vector<int> adj = adj(count);
    if(count == 0) {
      break;
    }
    */
    vector<vector<bool> > visited(N, vector<bool>(N, false));
    for(int r=0; r<N; r++) {
      for(int c=0; c<N; c++) {
        if(visited[r][c]) continue;
        vector<pii> unite;
        int totCon = 0, totPop = 0;
        DFS(make_pair(r, c), visited, unite, totCon, totPop);
        if(totCon > 1) isBreak = false;
        int finalPop = totPop / totCon;
        for(int i=0; i<unite.size(); i++) {
          land[unite[i].first][unite[i].second] = finalPop;
        }
      }
    }
    if(isBreak) break;
    day++;
  }
/*
  for(int r=0; r<N; r++) {
    for(int c=0; c<N; c++) {
      cout << land[r][c] << " ";
    }
    cout << endl;
  }
*/
  cout << day << endl;



  return 0;
}

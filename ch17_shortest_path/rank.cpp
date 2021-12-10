#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int s, int& cnt, vector<vector<int> > adj, vector<bool>& visited) {
  visited[s] = true;
  cnt++;
  for(int i=0; i<adj[s].size(); i++) {
    int next = adj[s][i];
    if(visited[next]) continue;
    DFS(next, cnt, adj, visited);
  }
  return;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > up(N+1);
  vector<vector<int> > down(N+1);
  for(int i=1; i<N+1; i++) {
    int A, B;
    cin >> A >> B;
    up[A].push_back(B);
    down[B].push_back(A);
  }
  
  int ans = 0;
  for(int i=1; i<N+1; i++) {
    int upCount = 0, downCount = 0;
    vector<bool> visited(N+1, false);
    DFS(i, upCount, up, visited);
    upCount--;
    fill(visited.begin(), visited.end(), false);
    DFS(i, downCount, down, visited);
    downCount--;
    if(upCount + downCount == N-1) {
      cout << i << '\n';
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}

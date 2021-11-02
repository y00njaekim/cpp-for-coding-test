#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K ,X;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> ans;
int d = 0;

void BFS(int x) {
  int d = 0;
  queue<int> q;
  q.push(x);
  while(!q.empty()) {
    int qSize = q.size();
    for (int i = 0; i < qSize; i++) {
      int cur = q.front();
      q.pop();
      if(visited[cur]) continue;
      else {
        visited[cur] = true;
      }
      if(d == K) {
        ans.push_back(cur);
      } else if(d > K) {
          return;
      }
      for (int j = 0; j < adj[cur].size(); j++)
      {
        int next = adj[cur][j];
        if (visited[next])
          continue;
        q.push(next);
      }
    }
    d++;
  }

  return;
}

int main() {
  cin >> N >> M >> K >> X;
  adj.resize(N+1);
  visited.resize(N+1);
  fill(visited.begin(), visited.end(), false);

  int tmp1, tmp2;
  for(int i=0; i<M; i++) {
    cin >> tmp1 >> tmp2;
    adj[tmp1].push_back(tmp2);
  }

  BFS(X);
  sort(ans.begin(), ans.end());

  if(ans.size() == 0) {
    cout << -1 << endl;
  } else {
    for(int i=0; i<ans.size(); i++) {
      cout << ans[i] << endl;
    }
  }

  return 0;
}

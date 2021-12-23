#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void swap(int a, int b, vector<vector<int> >& adj, vector<int>& inD) {
  for(int i=0; i<adj[a].size(); i++) {
    int cur = adj[a][i];
    if(cur == b) {
      adj[a].erase(adj[a].begin() + i);
      inD[b]--;
      adj[b].push_back(a);
      inD[a]++;
      return;
    }
  }
  for(int i=0; i<adj[b].size(); i++) {
    int cur = adj[b][i];
    if(cur == a) {
      adj[b].erase(adj[b].begin() + i);
      inD[a]--;
      adj[a].push_back(b);
      inD[b]++;
      return;
    }
  }
}

void solution(int n) {
  vector<int> olderRank;
  for(int i=0; i<n; i++) {
    int temp;
    cin >> temp;
    olderRank.push_back(temp);
  }

  vector<int> inD(n+1, 0);
  vector<vector<int> > adj(n+1);
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      adj[olderRank[i]].push_back(olderRank[j]);
      inD[olderRank[j]]++;
    }
  }

  int m;
  cin >> m;
  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    swap(a, b, adj, inD);
  }
  

  queue<int> q;

  int totNode = 0;
  int cnt = 0;
  for(int i=1; i<n+1; i++) {
    if(inD[i] == 0) {
      q.push(i);
      ++cnt;
    }
  }
  if(cnt > 1) {
    cout << "?" << '\n';
    return;
  } else if(cnt == 0) {
    cout << "IMPOSSIBLE" << '\n';
    return;
  }

  vector<int> res;
  do {
    int tp = q.front();
    q.pop();
    res.push_back(tp);
    ++totNode;


    for(int i=0; i<adj[tp].size(); i++) {
      int cur = adj[tp][i];
      if(--inD[cur] == 0) {
        q.push(cur);
      }
    }
  } while(q.size() == 1);

  if(totNode == n) {
    for(int i=0; i<res.size(); i++) {
      cout << res[i] << " ";
    }
    cout << '\n';
    return;
  } else if(q.size() > 1) {
    cout << "?" << '\n';
    return;
  } else if(q.size() == 0) {
    cout << "IMPOSSIBLE" << '\n';
    return;
  }
}

int main() {
  int t;
  cin >> t;
  for(int i=0; i<t; i++) {
    int n;
    cin >> n;
    solution(n);
  }

  return 0;
}

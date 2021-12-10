#include <iostream>
#include <vector>
#include <queue>


using namespace std;


int main() {
  int N;
  cin >> N;

  vector<vector<int> > adj(N+1);
  vector<int> inD(N+1, 0);
  vector<int> cost(N+1, 0);
  vector<int> ans(N+1, 0);
  
  for(int i=1; i<N+1; i++) {
    cin >> cost[i];

    int temp;
    while(true) {
      cin >> temp;
      if(temp == -1) break;
      adj[temp].push_back(i);
      inD[i]++;
    }
  }
  for(int i=1; i<N+1; i++) {
    cout << inD[i] << " "; 
  }
  cout << '\n';

  priority_queue<pair<int, int> > pq;
  for(int i=1; i<N+1; i++) {
    cout << "initialize " << i << '\n'; 
    if(inD[i] == 0) pq.push(make_pair(-cost[i], i)); 
  }

  int t = 0;
  while(!pq.empty()) {
    pair<int, int> todo = pq.top();
    t = t + (-todo.first);
    ans[todo.second] = t;
    pq.pop();

    queue<pair<int, int> > q;
    for(int i=0; i<adj[todo.second].size(); i++) {
      int next = adj[todo.second][i];
      inD[next]--;
      if(inD[next] == 0) q.push(make_pair(-cost[next], next));
    }

    int pqSize = pq.size();
    for(int i=0; i<pqSize; i++) {
      pair<int, int> temp = pq.top();
      pq.pop();
      
      temp.first -= todo.first;
      q.push(temp);
    }

    while(!q.empty()) {
      pq.push(q.front());
      q.pop();
    }
  }

  for(int i=1; i<ans.size(); i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}

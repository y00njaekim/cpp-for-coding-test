#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define INF 1e9

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int> > adj(N+1);
  for(int i=0; i<M; i++) {
    int A, B;
    cin >> A >> B;
    adj[A].push_back(B);
    adj[B].push_back(A);
  }

  vector<int> cost(N+1, INF);
  priority_queue<pii> pq;
  pq.push(make_pair(0, 1));
  cost[1] = 0;

  while(!pq.empty()) {
    cout << "IN WHILE" << '\n';
    int cst = -pq.top().first;
    int loc = pq.top().second;
    pq.pop();
    
    cout << "cst is " << cst << ", cost[loc] is " << cost[loc] << '\n'; 
    if(cost[loc] < cst) continue;
    cout << "Loc is " << loc << '\n';
    for(int i=0; i<adj[loc].size(); i++) {
      cout << "for" << '\n';
      int nextLoc = adj[loc][i];
      int nextCost = cst + 1;
      if(nextCost < cost[nextLoc]) {
        cost[nextLoc] = nextCost;
        cout << "Updated, Loc = " << nextLoc << ", Cost = " << nextCost << '\n'; 
        pq.push(make_pair(-nextCost, nextLoc));
      }
    }
  }
  for(int i=0; i<cost.size(); i++) {
    if(cost[i] == INF) cost[i] = -1;
  }
  int ansLoc = -1, cnt = 0;
  int ansCost = *max_element(cost.begin(), cost.end());
  for(int i=0; i<cost.size(); i++) {
    if(cost[i] == ansCost && ansLoc == -1) ansLoc = i;
    if(cost[i] == ansCost) cnt++;
  }
  cout << ansLoc << " " << ansCost << " " << cnt << '\n';
  for(int i=0; i<cost.size(); i++) {
    cout << cost[i] << " ";
  }
  cout << '\n';
}

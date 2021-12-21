#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent;

int find_parent(int x) {
  if(parent[x] == x) return x;
  return parent[x] = find_parent(parent[x]);
}

void union_parnet(int a, int b) {
  a = find_parent(a);
  b = find_parent(b);

  if(a < b) parent[b] = a;
  else parent[a] = b;
}

int main() {
  int N, M;
  cin >> N >> M;

  parent.resize(N);
  for(int i=0; i<N; i++) {
    parent[i] = i;
  }

  priority_queue<pair<int, pair<int, int> > > costs;

  int totCost = 0;
  for(int i=0; i<M; i++) {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    totCost += Z;
    costs.push(make_pair(-Z, make_pair(X, Y)));
  }
  
  int optCost = 0;
  int connected = 0;
  while(!costs.empty() && connected != N) {
    pair<int, pair<int, int> > cost = costs.top();
    costs.pop();
    int d = -cost.first;
    int x = cost.second.first;
    int y = cost.second.second;

    x = find_parent(x);
    y = find_parent(y);

    if(x == y) continue;

    union_parnet(x, y);
    optCost += d;
    ++connected;
  }

  cout << totCost - optCost << '\n';
}

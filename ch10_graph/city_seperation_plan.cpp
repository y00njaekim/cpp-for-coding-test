#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> parent;

int findParent(int x) {
  if(parent[x] == x) return x;
  else return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  if(a < b) parent[b] = a;
  else parent[a] = b;
}

int main() {
  cin >> N >> M;
  parent.resize(N+1);
  for(int i=1; i<N+1; i++) {
    parent[i] = i;
  }
  vector<pair<int, pair<int, int> > > graph;

  for(int i=0; i<M; i++) {
    int temp1, temp2, cost;
    cin >> temp1 >> temp2 >> cost;
    graph.push_back(make_pair(cost, make_pair(temp1, temp2)));
  }

  sort(graph.begin(), graph.end());

  int gSize = graph.size();
  int cost = 0, max = 0;
  for(int i=0; i<gSize; i++) {
    //cout << "hi" << endl;
    if(findParent(graph[i].second.first) == findParent(graph[i].second.second)) continue;
    cout << "Discuss about ";
    cout << graph[i].second.first << " " << graph[i].second.second << " " << graph[i].first << endl;
    cout << "Before union ";
    for(int j=1; j<N+1; j++) {
      cout << j << "-" << parent[j] << "/ ";
    }
    cout << endl;
    unionParent(graph[i].second.first, graph[i].second.second);
    cout << "After union ";
    for(int j=1; j<N+1; j++) {
      cout << j << "-" << parent[j] << "/ ";
    }
    cout << endl << endl;
    cost += graph[i].first;
    if(max < graph[i].first) max = graph[i].first;
  }

  /*
  for(int i=0; i<gSize; i++) {
    cout << graph[i].second.first << " " << graph[i].second.second << " " << graph[i].first << endl;
  }
  */

  cout << cost << " " << max << endl;

  return 0;
}

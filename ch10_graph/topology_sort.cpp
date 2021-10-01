#include <iostream>
#include <queue>
#include <vector>

#define vi vector<int>

using namespace std;

int V, E;
vector<vi> graph;
vi inD;

int main() {
  cin >> V >> E;
  graph.resize(V+1);
  inD.resize(V+1);
  fill(inD.begin()+1, inD.end(), 0);
  queue<int> q;

  for(int i=0; i<E; i++) {
    int temp1, temp2;
    cin >> temp1 >> temp2;
    graph[temp1].push_back(temp2);
    inD[temp2]++;
  }

  int stNode;
  for(int i=1; i<V+1; i++) {
    if(inD[i] == 0) {
      stNode = i;
      break;
    }
  }
  q.push(stNode);

  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    cout << cur << " " << endl;
    int adjSize = graph[cur].size();
    for(int i=0; i<adjSize; i++) {
      int next = graph[cur][i];
      inD[next]--;
      if(inD[next] == 0) q.push(next);
    }
  }

  return 0;
}



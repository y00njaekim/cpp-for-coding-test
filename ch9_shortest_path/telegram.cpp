#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define pii pair<int, int>
#define vvii vector<vector<pii> >

using namespace std;

int N, M, C;
int d[30001];
bool visited[30001];
vvii graph;
priority_queue<pii> pq;

void dijkstra(int s) {
  fill(d, d+30001, INF);
  fill(visited, visited+30001, false);
  
  d[s] = 0;
  visited[s] = true;
  for(int i=0; i<graph[s].size(); i++) {
    d[graph[s][i].first] = graph[s][i].second;
    pq.push(make_pair(-graph[s][i].second, graph[s][i].first));
  }

  for(int i=0; i<N-1; i++) {
    int min = INF;
    int minIndex = 0;

    int pqSize = pq.size();
    for(int j=0; j<pqSize; j++) {
      if(visited[pq.top().second]) {
        pq.pop();
      }
      else {
        min = -pq.top().first; 
        minIndex = pq.top().second;
        visited[minIndex] = true;
      }
    }

    for(int j=0; j<graph[minIndex].size(); j++) {
      int cost = min + graph[minIndex][j].second;
      if(cost < d[graph[minIndex][j].first]) {
        d[graph[minIndex][j].first] = cost;
        pq.push(make_pair(-cost, graph[minIndex][j].first));
      }
    }
  }
}

int main() {
  cin >> N >> M >> C;

  graph.resize(N+1);

  for(int i=0; i<M; i++) {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    graph[X].push_back(make_pair(Y, Z));
  }
  
  dijkstra(C);

  int ansCount = 0, ansTime = 0;
  for(int i=1; i<N+1; i++) {
    if(!visited[i]) continue; // 여기서 INF 가진 노드 다 걸러짐 
    ansCount++;
    if(ansTime < d[i]) ansTime = d[i];
  }

  cout << ansCount-1 << " " << ansTime << endl;
}

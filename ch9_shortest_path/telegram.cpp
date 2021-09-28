#include <iostream>
#include <vector>
#define INF 1e9
#define vvii vector<vector<pair<int, int> > >

using namespace std;

int N, M, C;
int d[30001];
bool visited[30001];
vvii graph;

void dijkstra(int s) {
  fill(d, d+30001, INF);
  fill(visited, visited+30001, false);
  
  d[s] = 0;
  visited[s] = true;
  for(int i=0; i<graph[s].size(); i++) {
    d[graph[s][i].first] = graph[s][i].second;    
  }

  for(int i=0; i<N-1; i++) {
    int min = INF;
    int minIndex = 0;

    for(int j=1; j<N+1; j++) {
      if(!visited[j] && d[j] < min) {
        min = d[j];
        minIndex = j;
      }
    }

    if(minIndex == 0) break;
    else visited[minIndex] = true;

    for(int j=0; j<graph[minIndex].size(); j++) {
      int cost = d[minIndex] + graph[minIndex][j].second;
      if(cost < d[graph[minIndex][j].first]) d[graph[minIndex][j].first] = cost;
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

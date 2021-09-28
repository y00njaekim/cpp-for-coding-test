#include <iostream>
#include <vector>
#define vvi vector<vector<int> >
#define INF 1e9

using namespace std;

int N, M, X, K;
int d[101];
bool visited[101];
vvi graph;

void dijkstra(int s) {
  // cout << "in dijsktra" << endl;
  fill(d, d+101, INF);
  fill(visited, visited+101, false);
  d[s] = 0;

  for(int j=0; j<N; j++) {
    int min = INF;
    int minIndex = 0;
    for(int i=1; i<N+1; i++) {
      if(!visited[i] && d[i] < min) {
        min = d[i];
        minIndex = i;
      }
    }
    // cout << "minIndex is " << minIndex << endl;
    if(minIndex != 0) visited[minIndex] = true;
    for(int i=0; i<graph[minIndex].size(); i++) {
      // cout << "for" << endl;
      int next = graph[minIndex][i];
      if(min+1 < d[next]) d[next] = min+1; 
    }
  }
  // for(int i=1; i<N+1; i++) {
  //   cout << d[i] << " ";
  // }
  // cout << endl;
  return;
}

int main() {
  cin >> N >> M;
  graph.resize(N+1);

  for(int i=0; i<M; i++) {
    int temp1, temp2;
    cin >> temp1 >> temp2;
    graph[temp1].push_back(temp2);
    graph[temp2].push_back(temp1);    
  }

  cin >> X >> K;
  dijkstra(1);
  int dK = d[K];
  dijkstra(K);
  int dX = d[X];
  int ans = dK + dX;
  if(ans < INF) cout << ans << endl;
  else cout << -1 << endl;

  // cout << "dK is " << dK << " and dX is " << dX << endl;

  return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define INF 1e9

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


int main() {
  int T;
  cin >> T;

  for(int i=0; i<T; i++) {
    int N;
    cin >> N;
    priority_queue<pair<int, pii> > pq;
    bool caught = false;

    vector<vector<int> > map(N, vector<int>(N));
    vector<vector<int> > cost(N, vector<int>(N, INF));
    for(int r=0; r<N; r++) {
      for(int c=0; c<N; c++) {
        int x;
        cin >> x;
        map[r][c] = x;
      }
    }
    cost[0][0] = map[0][0];
    pq.push(make_pair(-cost[0][0], make_pair(0, 0)));
    while(!pq.empty()) {
      int curCost = -pq.top().first;
      pii curLoc = pq.top().second;
      pq.pop();
      if(cost[curLoc.first][curLoc.second] < curCost) continue;
      for(int j=0; j<4; j++) {
        int nx = curLoc.first + dx[j];
        int ny = curLoc.second + dy[j];
        if(nx < 0 || nx > N-1) continue;
        if(ny < 0 || ny > N-1) continue;
        if(curCost + map[nx][ny] < cost[nx][ny]) {
          cost[nx][ny] = curCost + map[nx][ny];
          if(nx == N-1 && ny == N-1) caught = true;
          pq.push(make_pair(-(curCost + map[nx][ny]), make_pair(nx, ny)));
        }
        if(caught) break;
      }
      if(caught) break;
    }
    cout << cost[N-1][N-1] << '\n';
  }
  return 0;
}

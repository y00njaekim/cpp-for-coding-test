#include<iostream>
#include<vector>
#include<queue>
#define pii pair<int, int>

using namespace std;

int N, K, S, X, Y;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
  cin >> N >> K;
  vector<queue<pii> > virus(K+1);
  vector<vector<int> > map(N+1, vector<int>(N+1, 0));
  int temp;
  for(int x=1; x<N+1; x++) {
    for(int y=1; y<N+1; y++) {
      cin >> temp;
      map[x][y] = temp;
      if(temp != 0) {
        virus[temp].push(make_pair(x, y));
      }
    }
  }
  cin >> S >> X >> Y;

  bool done = false;

  for(int i=1; i<=S; i++) { // i is time(s)
    for(int j=1; j<=K; j++) { // j is index of virus type
      int nthSize = virus[j].size();
      for(int k=0; k<nthSize; k++) { // k is size of specific virus type
        for(int l=0; l<4; l++) {
          int nx = virus[j].front().first + dx[l];
          int ny = virus[j].front().second + dy[l];
          if(nx < 1 || nx > N) continue;
          if(ny < 1 || ny > N) continue;
          if(map[nx][ny] != 0) continue;
          map[nx][ny] = j;
          virus[j].push(make_pair(nx, ny));
          if(nx == X && ny == Y) done = true;
          if(done) break;
        }
        virus[j].pop();
        if(done) break;
      }
      if(done) break;
    }
    if(done) break;
  }

  cout << map[X][Y] << endl;

  return 0;
}

#include <iostream>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

int N, K, L;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int main() {
  cin >> N >> K;
  vector<vector<int> > apple(N+1, vector<int>(N+1, 0));
  vector<vector<int> > snakeMap(N+1, vector<int>(N+1, 0));
  deque<pair<int, int> > snakeArr;
  queue<pair<int, char> > dir;

  apple[1][1] = 1;
  int tempR, tempC;
  for(int i=0; i<K; i++) {
    cin >> tempR >> tempC;
    apple[tempR][tempC] = 1;
  }

  cin >> L;
  int tempX;
  char tempD;
  for(int i=0; i<L; i++) {
    cin >> tempX >> tempD;
    dir.push(make_pair(tempX, tempD));
  }

  int t=-1; int d=0;
  pair<int, int> next = make_pair(1, 1);
  while(true){
    if(next.first < 1 || next.first > N) break;
    if(next.second < 1 || next.second > N) break;
    if(snakeMap[next.first][next.second] == 1) break;
    //cout << dir.front().first << endl;
    t++;
    pair<int, int> cur = next;
    cout << "t:" << t << ", cur is " << cur.first << " " << cur.second << endl;
    snakeMap[cur.first][cur.second] = 1;
    snakeArr.push_front(cur);
    if(apple[cur.first][cur.second] != 1) {
      pair<int, int> tail = snakeArr.back();
      snakeMap[tail.first][tail.second] = 0;
      snakeArr.pop_back();
    } else {
      apple[cur.first][cur.second] = 0;
    }
    if(dir.front().first == t) {
      //cout << "right now!" << endl;
      if(dir.front().second == 'L') {
        d--;
        if(d < 0) d += 4; 
      }
      else if(dir.front().second == 'D') {
        d++;
        d = d % 4;
      }
      //cout << "d is " << d << endl;
      dir.pop();
    }
    for(int i=1; i<N+1; i++) {
      for(int j=1; j<N+1; j++) {
        cout << apple[i][j] << ' ';
      }
      cout << endl;
    }
    cout << "**************" << endl;
    for(int i=1; i<N+1; i++) {
      for(int j=1; j<N+1; j++) {
        cout << snakeMap[i][j] << ' ';
      }
      cout << endl;
    }
    next = make_pair(cur.first+dr[d], cur.second+dc[d]);
    cout << "next is " << next.first << " " << next.second << endl;
    cout << endl;

  }

  cout << t+1 << endl;
  return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> home;
vector<int> dist;
int N, C;

bool isOk(int x) {
  int cur = -x, count = 0;
  for(int i=0; i<N; i++) {
    if(home[i] - cur >= x) {
      count++;
      cur = home[i];
    }
    if(count >= C) break;
  }
  if(count >= C) return true;
  else return false;
}

int bs(int low, int high) {
  if(high - low == 1) return low;
  int mid = (low + high) / 2;
  if(isOk(mid)) return bs(mid, high);
  else return bs(low, mid);
}

int main() {
  cin >> N >> C;
  int tmp;
  for(int i=0; i<N; i++) {
    cin >> tmp;
    home.push_back(tmp);
  }
  sort(home.begin(), home.end());

  /*
  for(int i=0; i<N-1; i++) {
    int d = home[i+1] - home[i];
    dist.push_back(d);
  }
  sort(dist.begin(), dist.end());
  */

  /*
  // print dist
  for(int i=0; i<dist.size(); i++) {
    cout << dist[i] << ' ';
  }
  cout << '\n';
  */

  int ans = bs(1, home.back());

  cout << ans << '\n';
}

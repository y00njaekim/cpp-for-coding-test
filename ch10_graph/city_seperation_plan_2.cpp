#include <iostream>
#include <vector>
#include <algorithm>


#define pii pair<int, int>

using namespace std;


vector<int> parent;


int findParent(int a) {
  if(parent[a] == a) return parent[a];
  return parent[a] = findParent(parent[a]);
} 


void uni(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  if(a < b) parent[b] = a;
  else parent[a] = b;
}


bool isUni(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  if(a == b) return true;
  else return false;
}


int main() {
  int N, M;
  cin >> N >> M;
  for(int i=0; i<N; i++) {
    parent.push_back(i);
  }
  vector<pair<int, pii> > cost;

  for(int i=0; i<M; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    cost.push_back(make_pair(C, make_pair(A-1, B-1)));
  }
  sort(cost.begin(), cost.end());

  int ans = 0, mx = 0;
  for(int i=0; i<M; i++) {
    int c = cost[i].first;
    int a = cost[i].second.first;
    int b = cost[i].second.second;
    if(isUni(a, b)) continue;
    uni(a, b);
    ans += c;
    if(mx < c) mx = c;
  }

  ans -= mx;
  cout << ans << '\n';
  return 0;

}

#include <iostream>
#include <vector>

using namespace std;

int find_parent(int a, vector<int>& parent) {
  if(parent[a] == a) return a;
  return parent[a] = find_parent(parent[a], parent);
}

void union_parent(int a, int b, vector<int>& parent) {
  a = find_parent(a, parent);
  b = find_parent(b, parent);

  if(a < b) parent[b] = a;
  else parent[a] = b;

  return ;
}

int main() {

  bool ans = true;
  int N, M;
  cin >> N >> M;

  vector<int> parent(N+1);
  for(int i=1; i<N+1; i++) {
    parent[i] = i;
  }

  for(int r=1; r<=N; r++) {
    for(int c=1; c<=N; c++) {
      int temp;
      cin >> temp;
      if(temp == 1) union_parent(r, c, parent);
    }
  }

  int temp;
  cin >> temp;
  int prt = find_parent(temp, parent);
  for(int i=1; i<M; i++) {
    int temp;
    cin >> temp;
    if(find_parent(temp, parent) != prt) {
      ans = false;
      break;
    }
  }

  if(ans) cout << "YES" << '\n';
  else cout << "NO" << '\n';

  return 0;
}

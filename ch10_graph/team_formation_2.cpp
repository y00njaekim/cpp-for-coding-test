#include <iostream>
#include <vector>


using namespace std;


vector<int> parent;


int findParent(int a) {
  if(a == parent[a]) return a;
  return parent[a] = findParent(parent[a]);  
}


void uni(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  if(a < b) parent[b] = a;
  else parent[a] = b;
}


bool isuni(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  if(a == b) {
    cout << "YES" << '\n';
    return true;
  }
  else {
    cout << "NO" << '\n';
    return false;
  }
}


int main() {
  int N, M;
  cin >> N >> M;
  for(int i=0; i<N+1; i++) {
    parent.push_back(i);
  }
  for(int i=0; i<M; i++) {
    int op, a, b;
    cin >> op >> a >> b;

    if(op == 0) {
      uni(a, b);
    } else {
      string ans = (isuni(a, b)) ? "YES" : "NO";
      cout << ans << '\n';
    }
  }

  return 0;
}

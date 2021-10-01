#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> parent;

int findParent(int x) {
  if(parent[x] == x) return x;
  else return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
  a = findParent(a);
  b = findParent(b);

  if(a < b) parent[b] = a;
  else parent [a] = b;
}

int main() {

  cin >> N >> M;
  
  parent.resize(N+1);
  for(int i=0; i<N+1; i++) {
    parent[i] = i;
  }

  for(int i=0; i<M; i++) {
    int op, temp1, temp2;
    cin >> op >> temp1 >> temp2;
    if(op == 0) {
      unionParent(temp1, temp2);
    } else if(op == 1) {
      if(findParent(temp1) == findParent(temp2)) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }

  return 0;
}

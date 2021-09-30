#include <iostream>
#include <vector>

using namespace std;

int V, E;

vector<int> parent;

int findParent(int x) {
  if(parent[x] == x) {
    return x;
  } else {
    return parent[x] = findParent(parent[x]);
  }
}

void unionParent(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  if(a < b) parent[b] = a;
  else parent[a] = b;
}

int main() {
  cin >> V >> E;
  parent.resize(V+1);
  for(int i=1; i<V+1; i++) {
    parent[i] = i;
  }

  bool cycle = false;
  for(int i=0; i<E; i++) {
    int temp1, temp2;
    cin >> temp1 >> temp2;
    if(parent[temp1] != parent[temp2]) unionParent(temp1, temp2);
    else cycle = true;
  }

  if(cycle) cout << "true" << endl;
  else cout << "false" << endl;

  return 0;
}

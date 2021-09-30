#include <iostream>
#include <vector>

using namespace std;

struct connection {
  int v1, v2, d;
  connection(int _v1, int _v2, int _d) {
    v1 = _v1;
    v2 = _v2;
    d = _d;
  }
};

bool compare(connection& a, connection& b) {
  return a.d < b.d;
}

int V, E;
vector<int> parent;
vector<connection> connectList;


int findParent(int x) {
  if(parent[x] == x) return x;
  else return parent[x] = findParent(parent[x]);
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

  for(int i=0; i<E; i++) {
    int temp1, temp2, temp3;
    cin >> temp1 >> temp2 >> temp3;
    connectList.push_back(connection(temp1, temp2, temp3));
  }

  sort(connectList.begin(), connectList.end(), compare);
  int size = connectList.size();
  int totD = 0;
  for(int i=0; i<size; i++) {
    int temp1 = connectList[i].v1, temp2 = connectList[i].v2, temp3 = connectList[i].d;
    if(findParent(temp1) == findParent(temp2)) continue;
    unionParent(temp1, temp2);
    totD += temp3;  
  }

  cout << totD << endl;

  return 0;
}

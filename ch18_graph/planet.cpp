#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find_parent(int x) {
  if(parent[x] == x) return x;
  return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b) {
  a = find_parent(a);
  b = find_parent(b);

  if(a < b) parent[b] = a;
  else parent[a] = b;
}

struct planet {
  int n;
  int x;
  int y;
  int z;
  planet(int n, int x, int y, int z) {
    this->n = n;
    this->x = x;
    this->y = y;
    this->z = z;
  }
};

bool compareX(planet& a, planet& b) {
  return a.x < b.x;
}

bool compareY(planet& a, planet& b) {
  return a.y < b.y;
}

bool compareZ(planet& a, planet& b) {
  return a.z < b.z;
}

int main() {

  int N;
  cin >> N;

  vector<pair<int, pair<int, int> > > edges;

  parent.resize(N);
  for(int i=0; i<N; i++) {
    parent[i] = i;
  }

  vector<planet> planets;
  for(int i=0; i<N; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    planets.push_back(planet(i, x, y, z));
  }

  sort(planets.begin(), planets.end(), compareX);
  for(int i=0; i<planets.size()-1; i++) {
    int dx = planets[i+1].x - planets[i].x;
    int cn = planets[i].n;
    int nn = planets[i+1].n;
    edges.push_back(make_pair(dx, make_pair(cn, nn)));
  }

  sort(planets.begin(), planets.end(), compareY);
  for(int i=0; i<planets.size()-1; i++) {
    int dy = planets[i+1].y - planets[i].y;
    int cn = planets[i].n;
    int nn = planets[i+1].n;
    edges.push_back(make_pair(dy, make_pair(cn, nn)));
  }

  sort(planets.begin(), planets.end(), compareZ);
  for(int i=0; i<planets.size()-1; i++) {
    int dz = planets[i+1].z - planets[i].z;
    int cn = planets[i].n;
    int nn = planets[i+1].n;
    edges.push_back(make_pair(dz, make_pair(cn, nn)));
  }

  sort(edges.begin(), edges.end());


  int edge = 0;
  long long cost = 0;
  for(int i=0; i<edges.size(); i++) {
    int d = edges[i].first;
    int v1 = edges[i].second.first;
    int v2 = edges[i].second.second;

    v1 = find_parent(v1);
    v2 = find_parent(v2);

    if(v1 == v2) continue;

    // cout << v1 << " and " << v2 << " connected, distance is " << d << '\n';

    union_parent(v1, v2);
    ++edge;
    cost += d;

    if(edge == N-1) break;
  }

  cout << cost << '\n';

  return 0;
}

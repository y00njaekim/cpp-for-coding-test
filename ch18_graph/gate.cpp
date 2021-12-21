#include <iostream>
#include <vector>

using namespace std;

int main() {
  int ans = 0;

  int G, P;
  cin >> G >> P;

  vector<bool> visited(G+1, false);
  for(int i=0; i<P; i++) {
    int g;
    cin >> g;

    bool isBoard = false;
    for(int j=g; j>0; j--) {
      if(!visited[j]) {
        visited[j] = true;
        isBoard = true;
        break;
      }
    }

    if(!isBoard) break;
    ans++;
  }

  cout << ans <<'\n';

  return 0;
}

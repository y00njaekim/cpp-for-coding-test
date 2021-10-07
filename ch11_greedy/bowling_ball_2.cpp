#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

int main() {
  cin >> N >> M;
  v.resize(M+1);
  fill(v.begin(), v.end(), 0);

  for(int i=0; i<N; i++) {
    int temp;
    cin >> temp;
    v[temp]++;
  }

  int ans = 0;
  for(int i=0; i<M+1; i++) {
    if(v[i] < 1) continue;
    for(int j=i+1; j<M+1; j++) {
      if(v[j] < 1) continue;
      ans += v[i]*v[j];
    }
  }

  cout << ans << endl;
}

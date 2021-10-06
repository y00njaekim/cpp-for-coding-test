#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

int main() {
  cin >> N;
  for(int i=0; i<N; i++) {
    int temp;
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());

  int ans = 0, i = 0;
  while(ans+1 >= v[i] && i < N) {
    ans += v[i];
    i++;
  };
  cout << ans+1 << endl;
}

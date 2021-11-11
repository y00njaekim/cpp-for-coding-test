#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> home;
/*
pair<int, int> near(int b, int e, float avrg) {
  int mid = (b+e) / 2;
  if(e-b == 1) return (e < N) ? make_pair(home[b], home[e]) : make_pair(home[b], home[b]);
  
  if(home[mid] > avrg) return near(b, mid, avrg);
  else return near(mid, e, avrg); 
}
*/
int main() {
  cin >> N;
  int temp;
  //long long tot = 0, cnt = 0;
  for(int i=0; i<N; i++) {
    cin >> temp;
    //tot += temp;
    //cnt++;
    home.push_back(temp);
  }

  sort(home.begin(), home.end());

  /*
  int r = tot / cnt;
  int q = tot % cnt;
  float avrg = r + ((float)q / (float)cnt);
  
  pair<int, int> cand = near(0, N, avrg); 
  cout << cand.first << " " << cand.second << '\n';
  float diffA = avrg - (float)cand.first;
  float diffB = (float)cand.second - avrg;

  int ans;
  if(diffA <= diffB) ans = cand.first;
  else ans = cand.second;
  */
  
  int ans = (N%2 == 0) ? home[N/2-1] : home[N/2];

  cout << ans << '\n';

  return 0;
}

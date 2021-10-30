#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

vector<vector<pii> > comb(int n, int k, vector<pii> v){
  vector<vector<pii> > res;
  vector<int> tempVector;

  for(int i=0; i<k; i++) {
    tempVector.push_back(1);
  }

  for(int i=0; i<n-k; i++) {
    tempVector.push_back(0);
  }

  sort(tempVector.begin(), tempVector.end());

  do {
    vector<pii> pushVector;
    for(int i=0; i<tempVector.size(); i++) {
      if(tempVector[i] == 1) {
        pushVector.push_back(v[i]);
      }
    }
    res.push_back(pushVector);
  } while(next_permutation(tempVector.begin(), tempVector.end()));

  return res;
}

int dist(pii a, pii b) {
  int dx = a.first - b.first;
  if(dx < 0) dx = -dx;
  int dy = a.second - b.second;
  if(dy < 0) dy = -dy;
  return dx + dy;
}

int main() {
  int N, M, homeCount = 0, chickenCount = 0;

  cin >> N >> M;

  vector<vector<int> > map(N, vector<int>(N, 0));
  vector<pii> chicken, home;

  int forTemp;
  for(int r=0; r<N; r++) {
    for(int c=0; c<N; c++) {
      cin >> forTemp;
      if(forTemp == 1) {
        home.push_back(make_pair(r, c));
        homeCount++;
      }
      else if(forTemp == 2) {
        chicken.push_back(make_pair(r, c));
        chickenCount++;
      }
      map[r][c] = forTemp;
    }
  }

  vector<vector<pii> > chickenCases = comb(chickenCount, M, chicken);

  vector<int> cost;
  for(int i=0; i<chickenCases.size(); i++) {
    int chickenDist = 0;
    vector<pii> trialChicken = chickenCases[i];

    for(int j=0; j<home.size(); j++) {
      pii curHome = home[j];
      int min = 999;

      for(int k=0; k<trialChicken.size(); k++) {
        int d = dist(curHome, trialChicken[k]);
        if(d < min) min = d;
      }

      chickenDist += min;
    }

    cost.push_back(chickenDist);
  }
  
  int ans = *min_element(cost.begin(), cost.end());
  cout << ans << endl;

}

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
//vector<int> dfs;

bool DFS(int tar, int cur, int ind) {
  
  /*
  int dfsSize = dfs.size();
  for(int i=0; i<dfsSize; i++) {
    cout << dfs[i] << " ";
  }
  cout << endl;
  */

  if(cur == tar) return true;
  else if(cur > tar) return false;
  bool res = false;
  for(int i=ind; i<N; i++) {
    //dfs.push_back(v[i]);
    res = DFS(tar, cur+v[i], i+1);
    //dfs.pop_back();
    if(res) break;
  }
  return res;
}

int main() {
  cin >> N;

  int tot = 0;
  for(int i=0; i<N; i++) {
    int temp;
    cin >> temp;
    tot += temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  
  for(int i=1; i<=tot+1; i++) {
    if(DFS(i, 0, 0)) continue;
    else {
      cout << i << endl;
      break;
    }
  }

  return 0;
}


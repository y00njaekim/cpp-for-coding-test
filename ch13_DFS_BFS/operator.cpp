#include <iostream>
#include <vector>

using namespace std;

int mn = 1000000000;
int mx = -1000000000;
int ops[4];
vector<int> num;
int N, res;

void DFS(int d) {
  if(d == 0) res = num[0];
  if(d == N-1) {
    if(res < mn) mn = res;
    if(mx < res) mx = res;
    return;
  }
  for(int i=0; i<4; i++) {
    if(ops[i] == 0) continue;
    ops[i]--;
    if(i == 0) { // +
      res += num[d+1];
      DFS(d+1);
      res -= num[d+1];
    }
    else if(i == 1) { // -
      res -= num[d+1];
      DFS(d+1);
      res += num[d+1];
    }
    else if(i == 2) { // *
      res *= num[d+1];
      DFS(d+1);
      if(res < 0 && num[d+1] > 0) {
        res = -res;
        res /= num[d+1];
        res = -res;
      } else {
        res /= num[d+1];
      }
    }
    else if(i == 3) { // /
      int tmp = res;
      if(res < 0 && num[d+1] > 0) {
        res = -res;
        res /= num[d+1];
        res = -res;
      } else {
        res /= num[d+1];
      }
      DFS(d+1);
      res = tmp;
    }
    ops[i]++;
  }
  return;

}


int main() {
  cin >> N;

  int temp;
  for(int i=0; i<N; i++) {
    cin >> temp;
    num.push_back(temp);
  }
  for(int i=0; i<4; i++) {
    cin >> temp;
    ops[i] = temp;
  }

  DFS(0);

  cout << mx << endl << mn << endl;

  return 0;
}

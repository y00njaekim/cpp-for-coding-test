#include <iostream>
#include <vector>

#define pii pair<int, int>

using namespace std;

int N;
vector<vector<char> > hallway;
vector<pii> teacher;
bool answer = false;

bool isOk(vector<vector<char> > v) {
  bool isOk = true;
  for(int i=0; i<teacher.size(); i++) {
    int cr = teacher[i].first;
    int cc = teacher[i].second;
    for(int nr=cr+1; nr<N; nr++) {
      if(v[nr][cc] == 'O') break;
      if(v[nr][cc] == 'T') break;
      if(v[nr][cc] == 'S') {
        isOk = false;
        return isOk;
      }
    }
    for(int nr=cr-1; nr>=0; nr--) {
      if(v[nr][cc] == 'O') break;
      if(v[nr][cc] == 'T') break;
      if(v[nr][cc] == 'S') {
        isOk = false;
        return isOk;
      }
    }
    for(int nc=cc+1; nc<N; nc++) {
      if(v[cr][nc] == 'O') break;
      if(v[cr][nc] == 'T') break;
      if(v[cr][nc] == 'S') {
        isOk = false;
        return isOk;
      }
    }
    for(int nc=cc-1; nc>=0; nc--) {
      if(v[cr][nc] == 'O') break;
      if(v[cr][nc] == 'T') break;
      if(v[cr][nc] == 'S') {
        isOk = false;
        return isOk;
      }
    }
  }
  return isOk;
}

void DFS(int d, vector<vector<char> > v) { // d = 0, 1, 2 에서 수행 된 후 3 에서 끝냄
  if(d == 3) {
    answer = isOk(v);
    return;
  }
  for(int r=0; r<N; r++) {
    for(int c=0; c<N; c++) {
      if(v[r][c] != 'X') continue;
      vector<vector<char> > nv = v;
      nv[r][c] = 'O';
      DFS(d+1, nv);
      if(answer == true) return;
    }
  }
}

int main() {
  cin >> N;

  char temp;
  for(int i=0; i<N; i++) {
    vector<char> tempV;
    for(int j=0; j<N; j++) {
      cin >> temp;
      tempV.push_back(temp);
      if(temp == 'T') teacher.push_back(make_pair(i, j)); 
    }
    hallway.push_back(tempV);
  }

  DFS(0, hallway);

  string s = (answer) ? "YES" : "NO";
  cout << s << endl;

}

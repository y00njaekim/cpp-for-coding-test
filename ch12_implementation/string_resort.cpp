#include <iostream>
#include <queue>

using namespace std;


int main () {
  string s;
  cin >> s;

  priority_queue<int> pq;
  int totNum = 0;
  int sSize = s.size();
  for(int i=0; i<sSize; i++) {
    if('A' <= s[i] && s[i] <= 'z') {
      pq.push(-s[i]);
    }
    else { 
      totNum += s[i] - '0';
    }
  }

  while(!pq.empty()) {
    cout << (char)-pq.top();
    pq.pop();
  }

  cout << totNum << endl;

  return 0;
}

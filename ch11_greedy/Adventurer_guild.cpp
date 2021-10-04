#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> q;

int main() {
  cin >> N;
  for(int i=0; i<N; i++) {
    int temp;
    cin >> temp;
    q.push(-temp);
  }

  /*
  1. second whild 문 조건 서술 방식 오류
  2. priority_queue 는 내림차순을 기억
  int res = 0;
  while(!q.empty()) {
    cout << "first while" << endl;
    int inGuild = 0, maxGuild = -q.top();
    while(inGuild != maxGuild || !q.empty()) {
      cout << "second while " << inGuild << "/" << maxGuild << endl;
      maxGuild = -q.top();
      q.pop();
      inGuild++;
    }
    if(inGuild == maxGuild) res++;
  }
  */


  int res = 0;
  while(!q.empty()) {
    //cout << "first while" << endl;
    int inGuild = 0, maxGuild = -q.top();
    while(inGuild != maxGuild && !q.empty()) {
      //cout << "second while " << inGuild << "/" << maxGuild << endl;
      maxGuild = -q.top();
      q.pop();
      inGuild++;
    }
    if(inGuild == maxGuild) res++;
  }
  
  cout << res << endl;

}

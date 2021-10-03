#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int> > graphOut;
vector<vector<int> > graphIn;
vector<int> inD;
vector<int> cost;
vector<int> totCost;
queue<int> q;

int main() {
  cin >> N;
  graphOut.resize(N+1);
  graphIn.resize(N+1);
  inD.resize(N+1);
  cost.resize(N+1);
  totCost.resize(N+1);

  fill(inD.begin()+1, inD.begin()+N+1, 0);
  fill(totCost.begin()+1, totCost.begin()+N+1, 0);

  for(int i=1; i<N+1; i++) {
    int temp1 = 0, temp2 = 0;
    cin >> temp1;
    cost[i] = temp1;
    do {
      cin >> temp2;
      if(temp2 != -1) {
        graphOut[temp2].push_back(i);
        graphIn[i].push_back(temp2);
        inD[i]++;
      }
    } while(temp2 != -1);
  }

  for(int i=1; i<N+1; i++) {
    if(inD[i] == 0) q.push(i);
  }

  int tot = 0;
  while(!q.empty()) {
    int qSize = q.size();
    for(int i=0; i<qSize; i++) {
      int cur = q.front();
      q.pop();

      int maxCost = 0;
      int prevSize = graphIn[cur].size();
      for(int j=0; j<prevSize; j++) {
        if(maxCost < totCost[graphIn[cur][j]]) maxCost = totCost[graphIn[cur][j]];
      }
      totCost[cur] = cost[cur] + maxCost;
      
      int nextSize = graphOut[cur].size();
      for(int j=0; j<nextSize; j++) {
        inD[graphOut[cur][j]]--;
        if(inD[graphOut[cur][j]] == 0) q.push(graphOut[cur][j]);
      }
    }
  }

  for(int i=1; i<N+1; i++) {
    cout << totCost[i] << endl;
  }

  return 0;
}

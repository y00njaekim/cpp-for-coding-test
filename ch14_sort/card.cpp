#include <iostream>
#include <queue>

using namespace std;

int main() {
  int N;
  priority_queue<int> pq;

  cin >> N;

  int temp;
  for(int i=0; i<N; i++) {
    cin >> temp;
    pq.push(-temp);
  }

  int tot = 0;
  while(pq.size() > 1) {
    int a = -pq.top();
    pq.pop();
    int b = -pq.top();
    pq.pop();
    int newCard = a + b;
    pq.push(-newCard);

    tot += newCard;
  }

  cout << tot << endl;

}

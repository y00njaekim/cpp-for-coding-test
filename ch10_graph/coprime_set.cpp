#include <iostream>
#include <vector>

using namespace std;

int N, K; // N 이 총 노드의 개수, K 가 주어진 union 연산 개수
vector<int> prtTable;

// 최종보스(=루트 부모) 찾는 함수
int find_parent(int x) {
  if(prtTable[x] != x) {
    prtTable[x] = find_parent(prtTable[x]);
    return prtTable[x];
  }
  else {
    return x;
  }
}

// 두 노드에 대하여 합집합 취하는 함수? 묶여있는 트리 합치는데, 이제 그 방법이 루트 노드간의 화살표 긋기를 통하여.
void union_parent(int a, int b) {
  cout << "union_parent of " << a << " and " << b;
  if(prtTable[a] != a) a = find_parent(a);
  if(prtTable[b] != b) b = find_parent(b);

  if(a == b) {
    cout << ", a == b return;" << endl;
    return;
  }
  else {
    if(a < b) prtTable[b] = a;
    else prtTable[a] = b;
    cout << " is done, a' is " << a << ", b' is " << b << endl; 
  }
}

int main() {
  cin >> N >> K;

  prtTable.resize(N+1);

  for(int i=1; i<N+1; i++) {
    prtTable[i] = i;
  }

  for(int i=0; i<K; i++) {
    int temp1, temp2;
    cin >> temp1 >> temp2;
    union_parent(temp1, temp2);
  }


  cout << "각 원소가 속한 집합: ";
  for(int i=1; i<N+1; i++) {
    cout << find_parent(i) << " "; 
  }
  cout << endl;

  cout << "경로 압축을 이용했을 떄 각 원소의 부모 노드: ";
  for(int i=1; i<N+1; i++) {
    cout << prtTable[i] << " "; 
  }
  cout << endl;

}

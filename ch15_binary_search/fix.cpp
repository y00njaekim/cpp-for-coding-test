#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;

int bs(int low, int high) {
  if(high - low == 1) return low;
  
  int mid = (low + high) / 2;
  if(arr[mid] == mid) return mid;
  else if(arr[mid] < mid) return bs(mid+1, high);
  else if(arr[mid] > mid) return bs(low, mid);
}

int main() {
  cin >> N;

  int tmp;
  for(int i=0; i<N; i++) {
    cin >> tmp;
    arr.push_back(tmp);
  }

  int ans = bs(0, N);
  ans = (arr[ans] == ans) ? ans : -1;
  cout << ans << '\n';
}

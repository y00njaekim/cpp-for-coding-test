#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int binaryLeft(int tar, int low, int high) {
  if(high - low == 1) return low;
  int mid = (low + high - 1) / 2;
  if(arr[mid] < tar) return binaryLeft(tar, mid+1, high);
  else if(arr[mid] >= tar) return binaryLeft(tar, low, mid+1);
}

int binaryRight(int tar, int low, int high) {
  if(high - low == 1) return low;
  int mid = (low + high) / 2;
  if(arr[mid] <= tar) return binaryRight(tar, mid, high);
  else if(arr[mid] > tar) return binaryRight(tar, low, mid);
}

int main() {
  int N, x;
  cin >> N >> x;
  int temp;
  for(int i=0; i<N; i++) {
    cin >> temp;
    arr.push_back(temp);
  }

  int low = binaryLeft(x-1, 0, N);
  int high = binaryRight(x+1, 0, N);

  
  int ans = (arr[low] == x) ? high - low + 1 : -1;
  cout << ans << '\n';

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> a = {1, 2, 3};
  vector<int> b = a;
  b[1] = 999;

  int aSize = a.size();
  int bSize = b.size();
  cout << "a is ";
  for(int i=0; i<aSize; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  cout << "b is ";
  for(int i=0; i<bSize; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  
  return 0;
} 

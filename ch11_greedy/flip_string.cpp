#include <iostream>

using namespace std;

string s;

int main() {
  cin >> s;
  
  int ans0 = 0, ans1 = 0;
  int sSize = s.size();
  cout << sSize << endl;
  for(int i=0; i<sSize-1; i++) {
    cout << "i is " << i << endl; 
    if(s[i] == '1' && s[i+1] == '0') {
      ans0++;
      cout << "first if" << endl;
    }//10 Detect
    else if(s[i] == '0' && s[i+1] == '1') {
      ans1++; //01 Detect
      cout << "second if" << endl;
    }//10 Detect
  }
  if(s[sSize-1] == '1') ans0++;
  else if(s[sSize-1] == '0') ans1++;

  if(ans0 < ans1) cout << "to 0" << endl;
  else cout << "to 1" << endl;
  cout << min(ans0, ans1) << endl;
}

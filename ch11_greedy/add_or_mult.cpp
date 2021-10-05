#include <iostream>

using namespace std;

string s;

int main() {
  cin >> s;
  int ans = s[0] - '0';
  for(int i=1; i<s.size(); i++) {
    ans = max(ans + (s[i]-'0'), ans * (s[i]-'0'));
  }

  cout << ans << endl;
}

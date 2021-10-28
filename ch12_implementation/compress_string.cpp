#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compress(string s, int n) {
  cout << "last index is " << s.size() - 1 << endl;
  int res = 0, tot = 0; // res 는 최종 문자열 길이, tot 은 축약된 부분의 총 개수
  vector<int> count;    // count 는 축약된 것의 개수
  vector<pair<int, string> > voc;

  string temp1 = s.substr(0, n), temp2;
  int cnt = 1, sSize = s.size();
  for (int i = 0; i < sSize; i += n)
  {
    if (sSize <= i + (2 * n) - 1)
      continue;
    cout << "index " << i << " is ok for for, ";
    temp2 = s.substr(i + n, n);
    cout << "temp1 is " << temp1 << ", temp2 is " << temp2 << endl;
    if (temp1.compare(temp2) == 0)
    {
      cnt++;
    }
    else
    {
      voc.push_back(make_pair(cnt, temp1));
      if (cnt > 1)
      {
        count.push_back(cnt);
        cnt = 1;
      }
      temp1 = temp2;
    }
  }
  if(cnt > 1)
    count.push_back(cnt);

  int cSize = count.size();
  for(int i=0; i<cSize; i++) {
    string temp;
    temp = to_string(count[i]);
    res += temp.size()+n;
    tot += count[i];
  }

  int vSize = voc.size();
  for (int i = 0; i < vSize; i++) {
    if(voc[i].first == 1) {
      cout << voc[i].second;
    } else {
      cout << voc[i].first << voc[i].second;
    }
  }
  cout << endl;
  res += sSize - n * (tot);

  return res;
}

int main() {

  int k;
  string s;
  cin >> s >> k;

  // int min = 1e9;
  // int sSize = s.size();
  // for (int i = 1; i <= sSize / 2; i++) {
  //   int temp = compress(s, i);
  //   if (temp < min) min = temp;
  // }

  // cout << min << endl;
  // return min;

  cout << compress(s, k);
  return 0;
}
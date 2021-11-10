#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

struct grade {
  string name;
  int kor, eng, mat;
  grade(string _name, int _kor, int _eng, int _mat) {
    name = _name;
    kor = _kor;
    eng = _eng;
    mat = _mat;
  }
};

bool compare(grade& a, grade& b) {
  if(a.kor != b.kor) return a.kor > b.kor;
  if(a.eng != b.eng) return a.eng < b.eng;
  if(a.mat != b.mat) return a.mat > b.mat;
  return a.name < b.name;
}

int main() {
  cin >> N;

  vector<grade> v;
  string n;
  int k, e, m;
  for(int i=0; i<N; i++) {
    cin >> n >> k >> e >> m;
    grade temp = grade(n, k, e, m);
    v.push_back(temp);
  }

  sort(v.begin(), v.end(), compare);

  for(int i=0; i<N; i++) {
    cout << v[i].name << endl;
  }
}

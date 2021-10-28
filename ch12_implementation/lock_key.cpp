#include <string>
#include <iostream>
#include <vector>
#define vii vector<vector<int> >

using namespace std;

vii rotate90(vii v) {
    vii res;
    int vSize = v.size();
    for(int i=0; i<vSize; i++) {
        vector<int> temp;
        temp.resize(vSize);
        res.push_back(temp);
    }
    for(int r=0; r<vSize; r++) {
        for(int c=0; c<vSize; c++) {
        res[c][vSize-1-r] = v[r][c]; // r, c -> c, r -> c, vSize-1-r
        }
    }
    
    return res;
}

vii shift(vii v, int down, int right) {
    vii res;
    int vSize = v.size();
    for(int i=0; i<vSize; i++) {
        vector<int> temp;
        temp.resize(vSize);
        fill(temp.begin(), temp.end(), 0);
        res.push_back(temp);
    }

    // input vector 기준으로 하자
    for(int r=0; r<vSize; r++) {
        for(int c=0; c<vSize; c++) {
            if(v[r][c] == 0) continue;
            if(r+down < 0 || r+down >= vSize) continue;
            if(c+right < 0 || c+right >= vSize) continue;
            res[r+down][c+right] = v[r][c];
        }
    }
    return res;
}

bool isKey(vii lock, vii keyFull) {
    int ans = true;
    int lockSize = lock.size();
    for(int i=0; i<lockSize; i++) {
        for(int j=0; j<lockSize; j++) {
            if(lock[i][j] == keyFull[i][j]) {
                ans = false;
                return ans;
            }
        }
    }
    return ans;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
    bool answer = false;
    
    int keySize = key.size();
    int lockSize = lock.size();
    
    vii keyFull;
    for(int i=0; i<lockSize; i++) {
        vector<int> temp;
        for(int j=0; j<lockSize; j++) {
            temp.push_back(0);
        }
        keyFull.push_back(temp);
    }
    
    vii keyRotate = key;
    for(int i=0; i<4; i++) {
        keyRotate = rotate90(keyRotate);
        for(int down=-keySize+1; down<keySize; down++) {
            for(int right=-keySize+1; right<keySize; right++) {
                // 위 세 for 문으로 key setting 끝 
                vii keyTrial = shift(keyRotate, down, right);
                
                // keyFull 초기화
                for(int j=0; j<lockSize; j++) {
                    fill(keyFull[j].begin(), keyFull[j].end(), 0);
                }
                
                // keyFull 에 key 넣기
                for(int r=0; r<lockSize-keySize+1; r++) {
                    for(int c=0; c<lockSize-keySize+1; c++) {
                        // r c 는 key 의 왼쪽 꼭지점이 들어갈 keyFull 인덱스
                        for(int y=0; y<keySize; y++) {
                            for(int x=0; x<keySize; x++) {
                                keyFull[r+y][c+x] = keyTrial[y][x];
                            }
                        }
                    }
                }
                
                answer = isKey(lock, keyFull);
                if(answer) return answer;
            }
        }    
    }
    
    return answer;
}

int main() {
  int K, L;
  cin >> K >> L;

  vii key;
  for(int i=0; i<K; i++) {
    vector<int> temp;
    for(int j=0; j<K; j++) {
      int tempInt;
      cin >> tempInt;
      temp.push_back(tempInt);
    }
    key.push_back(temp);
  }

  vii lock;
  for(int i=0; i<L; i++) {
    vector<int> temp;
    for(int j=0; j<L; j++) {
      int tempInt;
      cin >> tempInt;
      temp.push_back(tempInt);
    }
    lock.push_back(temp);
  }

  bool res = solution(key, lock);
  if(res) cout << "true" << endl;
  else cout << "false" << endl;
}

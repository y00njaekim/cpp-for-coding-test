#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bs(string tar, int low, int high, vector<string> arr) {
    cout << "bs low is " << low << ", high is " << high << '\n'; 
    if(high - low == 1) return low;
    int mid = (low + high) / 2;
    if(tar == arr[mid]) {
      cout << "same" << '\n';
      return mid;
    }
    else if(tar < arr[mid]) {
      return bs(tar, low, mid, arr);
    }
    else if(tar >= arr[mid]) return bs(tar, mid, high, arr);
}

bool isPre(string pre, string s) {
    // error handler
    if(pre.size() > s.size()) return false;
    
    bool isPre = true;
    for(int i=0; i<pre.size(); i++) {
        if(pre[i] != s[i]) {
            isPre = false;
            break;
        }
    }
    return isPre;
}

string delWild(string s) { // wild character indicates '?'
    string res;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '?') {
            continue;
        }
        res += s[i];
    }
    return res;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    int wordsSize = words.size();
    vector<string> wordsR = words;
    for(int i=0; i<wordsSize; i++) {
        reverse(wordsR[i].begin(), wordsR[i].end());
    }
    sort(words.begin(), words.end());
    sort(wordsR.begin(), wordsR.end());
    
    for(int i=0; i<queries.size(); i++) {
        cout << "@@@ cur query is " << queries[i] << " @@@" << '\n';
        bool isRev = false;
        string curQry = queries[i];
        int qryCount = 0;
        int curQrylen = curQry.length();
        if(curQry[0] == '?') {
            isRev = true;
            reverse(curQry.begin(), curQry.end());
        }
        curQry = delWild(curQry);
        
        int j;
        string curWord, nextWord;
        if(isRev) {
            j = bs(curQry, 0, wordsSize, wordsR);
            cout << "the word is " << wordsR[j] << '\n';
        } else {
            j = bs(curQry, 0, wordsSize, words);
            cout << "the word is " << words[j] << '\n';
        }
        
        // curQry 고정, curword 순회
        do {
            if(j >= wordsSize) break; // error Handler
            curWord = (isRev) ? wordsR[j] : words[j];
            j++;
            bool isKeyWord = true;
            /*
            if(curQrylen != curWord.length()) {
              cout << "*" << '\n' << "length issue, curWord is " << curWord << '\n' << "*" << '\n'; 
              continue;
            }
            */
            for(int k=0; k<curQry.length(); k++) {
                if(curQrylen != curWord.length()) {
                  cout << "*" << '\n' << "length issue, curWord is " << curWord << '\n' << "*" << '\n'; 
                  isKeyWord = false;
                  break;
                }
                if(curQry[k] != curWord[k]) {
                    isKeyWord = false;
                    break;
                }    
            }
            if(isKeyWord) {
              cout << "*" << '\n' << "count++, curWord is " << curWord << '\n'; 
              qryCount++;
            } else {
              cout << "*" << '\n' << "not counted, curWord is " << curWord << '\n';
            }
            if(j >= wordsSize) break;
            nextWord = (isRev) ? wordsR[j] : words[j];
            if(isKeyWord) {
              cout << "next word is " << nextWord << '\n' << "*" << '\n';
            }
        } while(isPre(curQry, nextWord));
        
        answer.push_back(qryCount);
    }
    
    return answer;
}

int main() {
  int N, M;
  cin >> N >> M;
  //cout << "N is " << N << ", M is " << M << '\n';
  vector<string> words;
  vector<string> queries;
  for(int i=0; i<N; i++) {
    string tmp; 
    cin >> tmp;
    words.push_back(tmp);
  }
  sort(words.begin(), words.end());
  
  for(int i=0; i<N; i++) {
    cout << words[i] << " ";
  }
  cout << '\n';
  
  //cout << '\n';
  for(int i=0; i<M; i++) {
    //cout << "for" << '\n';
    string tmp;
    cin >> tmp;
    queries.push_back(tmp);
    //cout << "queries i is " << queries[i]; 
  }
  /*
  for(int i=0; i<M; i++) {
    cout << queries[i] << " ";
  }
  */

  vector<int> ans = solution(words, queries);
  for(int i=0; i<ans.size(); i++) {
   cout << ans[i] << " ";
  }
  

  return 0;
}

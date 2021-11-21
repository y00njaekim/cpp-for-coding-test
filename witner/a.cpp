#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  string character = "10 5 2";
      
    vector<string> result;
    result.clear();
    int current, previous;
    current = character.find(' ');
    while(current != string::npos) {
        string substring = character.substr(previous,current-previous);
        result.push_back(substring);
        previous = current+1;
        current = character.find(' ', previous);
    }
    result.push_back(character.substr(previous,current-previous));

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << '\n';
  }
}
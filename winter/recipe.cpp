#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>


using namespace std;

int solution(int n, vector<string> recipe, vector<string> order) {

  unordered_map<string, int> recipeMap;
  
  for(int i=0; i<recipe.size(); i++) {
    istringstream istrstream(recipe[i]);
    string strBuffer;
    vector<string> res;
    while(getline(istrstream, strBuffer, ' ')) {
      res.push_back(strBuffer);
    }
    recipeMap[res[0]] = res[1];
  }

  vector<pair<string, int> > orderVector;
  for(int i=0; i<order.size(); i++) {
    istringstream istrstream(order[i]);
    string strBuffer;
    vector<string> res;
    res.clear();
    while(getline(istrstream, strBuffer, ' ')) {
      res.push_back(strBuffer);
    }
    orderVector.push_back(make_pair(res[0], res[1]));
  }

  int used = 0;
  priority_queue<int> cooked;
  for(int i=0; i<orderVector.size(); i++) {
    int orderTime = orderVector[i].second;
    int cookingTime = recipeMap[orderVector[i].first];
    while(!cooked.empty() && -cooked.top() <= orderTime) {
      cooked.pop()
      used--;
    }
    if(used < n) {
      cooked.push(-(orderTime + cookingTime));
      used++;
    } esle {
      int orderTime = -cooked.top();
      while(!cooked.empty() && -cooked.top() <= orderTime) {
        cooked.pop()
        used--;
      }
      cooked.push(-(orderTime + cookingTime));
      used++;
    }
    if(i == orderVector.size() - 1) answer = -(orderTime + cookingTime);
  }
}

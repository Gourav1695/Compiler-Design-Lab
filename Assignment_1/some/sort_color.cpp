#include<bits/stdc++.h>

using namespace std;

int solve(string str) {

  if(str.size()==0)
      return 0;
    unordered_set < int > set;
  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
  {
    for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(str[j]);
    }
  }
  return max(maxans,set.size());
}

int main() {
  string str = "dvdf";
  cout << "The length of the longest substring without repeating characters is " << 
  solve(str);
  return 0;
}
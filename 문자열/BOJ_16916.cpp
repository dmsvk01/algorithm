#include <iostream>
#include <vector>

using namespace std;

string parent, pattern;

void input(){
  cin >> parent;
  cin >> pattern;
}

vector<int> getFail(){
  int patternSize = pattern.size();
  vector<int> fail(pattern.size(), 0);
  
  for(int j=0, i=1; i<patternSize; i++){
    while(j>0 && pattern[i] != pattern[j]){
      j = fail[j-1];
    }
    if(pattern[i] == pattern[j]){
      fail[i] = ++j;
    }
  }
  return fail;
}

int solve(){
  int parentSize = parent.size();
  int patternSize = pattern.size();
  vector<int> fail = getFail();
  // for(int i=0; i<fail.size(); i++){
  //   printf("%d ", fail[i]);
  // }
  for(int j=0, i=0; i<parentSize; i++){
    while(j>0 && parent[i]!=pattern[j]){
      j = fail[j-1];
    }
    if(parent[i] == pattern[j]){
      j++;
      if(j == patternSize) return 1;
    }
  }
  return 0;
}

int main(){
  input();
  cout << solve();
  return 0;
}

/*
baekjoon
aek
*/

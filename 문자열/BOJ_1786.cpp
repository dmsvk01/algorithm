#include <iostream>
#include <vector>

using namespace std;

string parent, pattern;
vector<int> list;
int result=0;


void input(){
  getline(cin, parent);
  getline(cin, pattern);
}

vector<int> getfail(int patternSize){
  vector<int> fail(patternSize,0);
  for(int j=0, i=1; i<patternSize; i++){
    while(j>0 && pattern[i]!=pattern[j]) j = fail[j-1];
    if(pattern[i]==pattern[j]) fail[i] = ++j;
  }
  return fail;
}

void solve(){
  int parentSize = parent.size();
  int patternSize = pattern.size();
  vector<int> fail = getfail(patternSize);

  for(int j=0,i=0; i<parentSize; i++){
    while(j>0 && parent[i]!=pattern[j]) j = fail[j-1];
    if(parent[i] == pattern[j]){
      if(j == patternSize-1){
        j = fail[j];
        result++;
        list.push_back(i-patternSize+2);
      }else{
        j++;
      }
    }
  }

  printf("%d\n", result);
  for(int i=0; i<list.size(); i++){
    printf("%d ", list[i]);
  }
}

int main(){
  input();
  solve();
  return 0;
}

/*
ABC ABCDAB ABCDABCDABDE
ABCDABD

1 ->  총 개수
16 -> 위치

공백이 포함되는 문자열의 경우 scanf or cin으로 입력받아서 공백을 인식하지 못했다.
해결책 : getline(cin, str); 로 입력받기!

*/

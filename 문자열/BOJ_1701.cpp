#include <iostream>
#include <vector>

using namespace std;

string str;

void input(){
  cin >> str;
}
int maxn = 0;
void printVector(vector<int> fail, int k){
  for(int i=k; i<fail.size(); i++){
      //printf("%d ", fail[i]-k);
      if(maxn < fail[i]-k) maxn = fail[i]-k;
  }
  //printf("\n");
}

void solve(){
  int j=0;
  int strSize = str.size();
  for(int k=0; k<str.size()-1; k++){
    
    vector<int> fail(strSize, k);
    for(int i=k+1, j=k; i<strSize; i++){
     // printf("i:%d j:%d, str[i]:%c, str[j]:%c\n", i,j,str[i], str[j]);
      while(j>k && str[i]!=str[j]) j = fail[j-1];
      if(str[i]==str[j]) fail[i] = ++j;
    }
    printVector(fail, k);
    
  }
  printf("%d", maxn);
}


int main(){
  input();
  solve();
  return 0;
}

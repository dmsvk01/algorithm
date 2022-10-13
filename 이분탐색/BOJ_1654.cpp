#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int k,n;
vector<int> num;

void input(){
  cin >> k >> n;
  for(int a,i=0; i<k; i++){
    scanf("%d", &a);
    num.push_back(a);
  }
}

int check(int target){
  int size = num.size();
  int res=0;

  for(int i=0; i<size; i++){
    res = res + num[i]/target;
  }

  if(res >= n) return 1;
  else return 0;
}

int init(){
  int size = num.size();
  long res=0;

  for(int i=0; i<size; i++){
    res = res + num[i];
  }

  res = res / n;
  return (int)res;
}

void solve(){
  long low=0,high=init();
  long middle=0;
  while(low != high){
    middle = (low + high + 1) / 2;
    if(check(middle)){
      low = middle;
    }else{
      high = middle - 1;
    }
  }
  printf("%ld\n", high);
}

int main(){
  input();
  solve();
  return 0;
  }

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
  int t; cin >> t;
  for(int T=0; T<t; T++){
    int n; cin >> n;
    int num[100000]={0};
    int i=1;
    while(n!=1){
      i++;
      while(n%i==0){
        num[i]++;
        n = n/i;
      }
    }
    for(int i=0; i<100000; i++){
      if(num[i]!=0){
        printf("%d %d\n", i, num[i]);
      }
    }
  }
}
/*
2
6
24
*/

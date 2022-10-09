#include <iostream>

using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
 
  int res = 1;
  
  for(int i=n; i>=n-k+1; i--){
   res*=i; 
  }
  
  for(int i=k; i>1; i--){
   res/=i; 
  }
  
  printf("%d", res);
  
  return 0;
  }

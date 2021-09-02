#include <iostream>

using namespace std;

int main(){
  long long dp0[101]={0};
  long long dp1[101]={0};
  dp0[0] = 0;
  dp1[0] = 1;
  for(int i=1; i<=100; i++){
    dp0[i] = dp0[i-1] + dp1[i-1];
    dp1[i] = dp0[i-1];
  }

  int x; cin >> x;
  printf("%lld\n", dp0[x-1] + dp1[x-1]);
  
}

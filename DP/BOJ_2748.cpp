#include <iostream>

using namespace std;

int main(){
  long long  dp[101]={0};
  dp[0] = 0;
  dp[1] = 1;
  for(int i=2; i<=100; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }

  int x; cin >> x;
  printf("%lld\n", dp[x]);
  
}

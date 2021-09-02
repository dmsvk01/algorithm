#include <iostream>

using namespace std;

int main(){
  int  dp[1001]={0};
  dp[1] = 1;
  dp[2] = 2;
  for(int i=3; i<=1000; i++){
    dp[i] = (dp[i-1] + dp[i-2])%10007;
  }

  int x; cin >> x;
  printf("%d\n", dp[x]);
  
}

#include <iostream>

using namespace std;

int main(){
  int n,k;
  int v[101]={0,};
  int w[101]={0,};
  int dp[101][100001]={0,};
  int result=0;
  scanf("%d %d", &n, &k);
  for(int i=1; i<=n; i++){
    scanf("%d %d", &w[i], &v[i]);
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=k; j++){
      if(w[i] <= j)
        dp[i][j] = max(v[i] + dp[i-1][j-w[i]], dp[i-1][j]);
      else
        dp[i][j] = dp[i-1][j];
      result = max(result, dp[i][j]);
    }
  }
  cout << result;
}

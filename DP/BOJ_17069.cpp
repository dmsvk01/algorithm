#include <iostream>

using namespace std;

long dp[32][32][3]={0,};
int a[32][32]={0,};
int n;

void input(){
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &a[i][j]);
    }
  }
}

void solve(){
  for(int i=1; i<n; i++){
    if(a[0][i]==1) break;
    dp[0][i][1] = 1;
  }

  for(int i=1; i<n; i++){
    for(int j=2; j<n; j++){
      if(a[i][j]==1) continue;

      if(a[i][j-1]==0 && a[i-1][j]==0)
        dp[i][j][0] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
      dp[i][j][1] = dp[i][j-1][0] + dp[i][j-1][1];
      dp[i][j][2] = dp[i-1][j][0] + dp[i-1][j][2];
    }
  }
  cout << dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2];
}

int main(){
  input();
  solve();
  return 0;
}

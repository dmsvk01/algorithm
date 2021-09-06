#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[301][21]={0};
int dp[301][21]={0};

int main(){
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    for(int j=0; j<=m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  for(int i=0; i<=n; i++) arr[i][0]=0;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      int val = 0;
      for(int k=0; k<i; k++){
        val = max(val, arr[i-k][j] + dp[k][j-1]);
      }
      dp[i][j] = max(dp[i][j-1], val); 
    }
  }

  cout << dp[n][m];

  return 0;
}
/*
4 2
1 5 1
2 6 5
3 7 9
4 10 15

5 3
1 5 2 8
2 7 6 12
3 1 11 9
4 4 3 14
5 13 8 10


4 3
 1

5

1

2

 2

6

5

4

 3

7

9

11

 4

8

15

12


*/

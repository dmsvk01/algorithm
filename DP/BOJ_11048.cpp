#include <iostream>
#include <algorithm>
#define VMAX 1001

using namespace std;

int main(){
  int n,m; cin >> n >> m;
  int s[VMAX][VMAX]={0};
  int d[VMAX][VMAX]={0};
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      scanf("%d", &s[i][j]);
      if(i==1 || j==1) d[i][j] = s[i][j];
    }
  }
  for(int i=1; i<=n; i++){
    d[i][1]+=d[i-1][1];
  }
  for(int j=1; j<=m; j++){
    d[1][j]+=d[1][j-1];
  }
  for(int i=2; i<=n; i++){
    for(int j=2; j<=m; j++){
      d[i][j] = max({d[i][j-1], d[i-1][j], d[i-1][j-1]}) + s[i][j];
    }
  }
  printf("%d", d[n][m]);
}
/*
3 4
1 2 3 4
0 0 0 5
9 8 7 6
*/

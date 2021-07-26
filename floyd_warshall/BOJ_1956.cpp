#include <iostream>
#include <vector>
#include <algorithm>
#define VMAX 401
#define INF 987654321
using namespace std;

int dist[VMAX][VMAX];

int main(){
  int n,m; cin >> n >> m;
  int result=INF;
  int x=INF;
  for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        dist[i][j] = INF;
      }
  }
  for(int x,y,w,i=0; i<m; i++){
    scanf("%d %d %d", &x, &y, &w);
    dist[x][y]=w;
  }
  for(int i=1; i<=n; i++){
    dist[i][i]=0;
  }


  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(dist[i][j] > dist[i][k] + dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(i!=j && dist[i][j]!=INF && dist[j][i]!=INF){
          result = min(result, dist[i][j]+dist[j][i]);
        }
      }
  }
  result==INF?printf("-1\n"):printf("%d\n", result);
}
/*
3 4
1 2 1
3 2 1
1 3 5
2 3 2
*/

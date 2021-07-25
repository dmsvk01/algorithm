#include <iostream>
#include <vector>
#include <algorithm>

#define VMAX 101
#define INF 987654321

using namespace std;

vector<pair<pair<int,int>,int>> a;
int n,e;

void floyd_warshall(){
  int dist[VMAX][VMAX];
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      dist[i][j]= i==j? 0 : INF;
  
  for(int i=0; i<e; i++){
    int x = a[i].first.first;
    int y = a[i].first.second;
    int w = a[i].second;
    //printf("x:%d, y:%d w:%d\n",x,y,w);
    if(dist[x][y]!=INF) dist[x][y] = min(dist[x][y], w);
    else dist[x][y] = w;
  }
  for(int i=1; i<=n; i++) // i 를 거쳐서 가는
    for(int j=1; j<=n; j++) // j 와
      for(int k=1; k<=n; k++){ // k 사이의 dist
      if(i==j || i==k || j==k) continue;
            dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
        
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      dist[i][j]==INF?printf("0 ") : printf("%d ",dist[i][j]);
    }
    printf("\n");
  }

}

int main(){
  cin >> n;
  cin >> e;
  for(int x,y,w,i=0; i<e; i++){
    scanf("%d %d %d", &x, &y, &w);
    a.push_back({{x,y},w});
  }
  floyd_warshall();
}

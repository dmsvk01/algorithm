#include <iostream>
#include <vector>
#define VMAX 101
#define INF 2100000000

using namespace std;

vector<pair<pair<int,int>,int>> a;
int n,e;

void floyd_warshall(){
  int dist[VMAX][VMAX];
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      dist[i][j]=INF;
  
  for(int i=0; i<e; i++){
    int x = a[i].first.first;
    int y = a[i].first.second;
    int w = a[i].second;
    //printf("x:%d, y:%d w:%d\n",x,y,w);
    dist[x][y] = w;
  }
  for(int i=1; i<=n; i++){ // i 를 거쳐서 가는
    for(int j=1; j<=n; j++){ // j 와
      for(int k=1; k<=n; k++){ // k 사이의 dist
        if (dist[j][i] != INF && dist[i][k] != INF){
          if(dist[j][k] > dist[j][i] + dist[i][k]){
            dist[j][k] = dist[j][i] + dist[i][k];
          }
        }
      }
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      printf("%d ", dist[i][j]);
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

/*
5
14
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
3 5 10
3 1 8
1 4 2
5 1 7
3 4 2
5 2 4
*/

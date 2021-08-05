#include <iostream>
#include <algorithm>
#include <queue>
#define VMAX 301

using namespace std;

int n,m;
int b[VMAX][VMAX];
bool c[VMAX][VMAX];
int v[VMAX][VMAX]={0};  

int result=0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int countb=0;
int years=0;

void bfs(int sx, int sy, int v[][VMAX]){
  //printf("bfs----------------------\n");
  queue<pair<int,int>> q;
  q.push({sx,sy});
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    //printf("x:%d y:%d\n",x,y);
    for(int i=0; i<4; i++){
      int X = x+dx[i];
      int Y = y+dy[i];
      if(b[X][Y]!=0 && v[X][Y]==0){ // 빙산이 있고 방문안했으면
        v[X][Y]=1;
        q.push({X,Y});
      }
    }
  }
}

int main(){
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &b[i][j]);
    }
  }
  while(1){
    for(int i=0; i<=n; i++){ // 빙산체크초기화
      for(int j=0; j<m; j++){
        if(b[i][j]==0) c[i][j]=false; // 빙산이 있으면 true이다.
        else c[i][j] = true;
      }
    }
    for(int i=0; i<n; i++){ // 빙산체크초기화
      for(int j=0; j<m; j++){
        //printf("%d ", b[i][j]);
      }
      //printf("\n");
    }

    countb=0;

    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        v[i][j]=0;
    
    for(int i=1; i<n-1; i++){ // BFS로 이분되었는지 탐색
      for(int j=1; j<m-1; j++){
        if(b[i][j]!=0 && v[i][j]==0){
          bfs(i,j, v);
          countb++;
        }
      }
    }
    if(countb>=2) break;
    if(countb==0){ // 모든 빙산이 없어졌으므로 끝까지 분리되지 못한것이다.
      printf("0");
      return 0;
    }
    years++;
    for(int i=1; i<n-1; i++){ // 1년 후 시간진행
      for(int j=1; j<m-1; j++){
        for(int k=0; k<4; k++){
          int X = i+dx[k];
          int Y = j+dy[k];
          if(c[X][Y]==false && b[i][j] > 0){
            b[i][j]--;
          }
        }
      }
    }

  }
  printf("%d", years);
}

/*
N과 M은 3 이상 300 이하
칸에 들어가는 값은 0 이상 10 이하
배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0

5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0

2

*/

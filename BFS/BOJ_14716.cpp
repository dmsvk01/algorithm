#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define VMAX 250+1
#define INF 987654321

using namespace std;

int n,m;
int b[VMAX][VMAX];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};

void bfs(int sx, int sy){
  queue<pair<int,int>> q;
  int v[VMAX][VMAX]={0};
  q.push({sx,sy});
  v[sx][sy]=1;
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int i=0; i<8; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx >=0 && ny >=0 && nx <n && ny <m){
        if(v[nx][ny]==0 && b[nx][ny]==1){
          v[nx][ny]=1;
          b[nx][ny]=0;
          q.push({nx,ny});
        }
      }
    }
  }
}

int main()
{
  int result=0;
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> b[i][j];
    }
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(b[i][j]==1){
        bfs(i,j);
        result++;
      }
    }
  }

  cout << result;

  return 0;
}

/*
8 19
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 1 0 0 0 1 0 1 1 1 1 1 0
0 0 1 0 1 0 0 1 1 0 0 1 0 0 0 1 0 0 0
0 1 0 0 0 1 0 1 0 1 0 1 0 0 0 1 0 0 0
0 1 1 1 1 1 0 1 0 1 0 1 0 0 0 1 0 0 0
0 1 0 0 0 1 0 1 0 0 1 1 0 0 0 1 0 0 0
0 1 0 0 0 1 0 1 0 0 0 1 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

*/

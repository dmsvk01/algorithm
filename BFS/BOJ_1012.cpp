#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int input[50][50]={0};
queue<pair<int, int>> q;
int m,n,x; 

void bfs(int a, int b){
  int v[50][50]={0};
  v[a][b]=1;
  input[a][b]=0;
  q.push(make_pair(a,b));
  while(!q.empty()){
    int x,y;
    x = q.front().first;
    y = q.front().second;
    q.pop();
    if(v[x-1][y]==0 && input[x-1][y]==1 && x!=0){
      v[x-1][y]=1;
      input[x-1][y]=0;
      q.push(make_pair(x-1,y));
    }
    if(v[x+1][y]==0 && input[x+1][y]==1 && x!=n-1){
      v[x+1][y]=1;
      input[x+1][y]=0;
      q.push(make_pair(x+1,y));
    }
    if(v[x][y-1]==0 && input[x][y-1]==1 && y!=0){
      v[x][y-1]=1;
      input[x][y-1]=0;
      q.push(make_pair(x,y-1));
    }
    if(v[x][y+1]==0 && input[x][y+1]==1 && y!=m-1){
      v[x][y+1]=1;
      input[x][y+1]=0;
      q.push(make_pair(x,y+1));
    }
  }
}
int main(){
  int t; cin >> t;
  for(int w=0; w<t; w++){
    cin >> m >> n >> x;
    int result=0;
    fill(&input[0][0], &input[n-1][m-1], 0);
    for(int i=0; i<x; i++){
      int a,b; cin >> a >> b;
      input[b][a]=1;
    }
    
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        if(input[i][j]==1){
          bfs(i,j);
          result++;
        }
      printf("%d\n", result);
  }
    return 0;
}

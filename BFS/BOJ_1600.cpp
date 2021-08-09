#include <iostream>
#include <algorithm>
#include <queue>
#define VMAX 200
#define KMAX 31

using namespace std;

int k,w,h;
int b[VMAX][VMAX];
bool v[VMAX][VMAX][KMAX]={0};
int dx[12]={0, 0, 1, -1, -1, -2, -2, -1, 1, 2, 2, 1};
int dy[12]={1, -1, 0, 0, -2, -1, 1, 2, 2, 1, -1, -2}; // 0~3은 인접이동, 4~11은 말이동
void bfs(int sk){
  queue<pair<pair<int,int>,pair<int,int>>> q; // x,y, depth, k
  q.push({{0,0},{0,0}}); 
  v[0][0][0]=true;
  while(!q.empty()){
    int x = q.front().first.first;
    int y = q.front().first.second;
    int depth = q.front().second.first;
    int k = q.front().second.second;
    q.pop();
    if(x==h-1 && y==w-1){
      printf("%d", depth);
      return ;
    }
    for(int i=0; i<4; i++){
      int X = x + dx[i];
      int Y = y + dy[i];
      if(X>=0 && Y>=0 && X<h && Y<w && v[X][Y][k]==false && b[X][Y]==0){
        v[X][Y][k]=true;
        q.push({{X,Y},{depth+1,k}});
      }
    }
    if(sk > k){
      for(int i=4; i<12; i++){
      int X = x + dx[i];
      int Y = y + dy[i];
      if(X>=0 && Y>=0 && X<h && Y<w && v[X][Y][k+1]==0 && b[X][Y]==0){
        v[X][Y][k+1]=1;
        q.push({{X,Y},{depth+1,k+1}});
      }
    }
    }
  }
  printf("-1");
}

int main(){
  cin >> k;
  cin >> w >> h;
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      scanf("%d", &b[i][j]);
    }
  }
  bfs(k);
  return 0;
}

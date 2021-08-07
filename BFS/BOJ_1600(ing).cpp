#include <iostream>
#include <algorithm>
#include <queue>
#define VMAX 201
#define KMAX 310

using namespace std;

int k,w,h;
int b[VMAX][VMAX];
int v[VMAX][VMAX][KMAX]={0};
int dx[12]={0,0,1,-1,-2,-1,1,2,2,1,-1,-2};
int dy[12]={1,-1,0,0,1,2,2,1,-1,-2,-2,-1}; // 0~3은 인접이동, 4~11은 말이동

void bfs(int sk){
  queue<pair<pair<int,int>,pair<int,int>>> q; // x,y, depth, k
  q.push({{0,0},{0,sk}}); 
  v[0][0][k]=1;
  while(!q.empty()){
    int x = q.front().first.first;
    int y = q.front().first.second;
    int depth = q.front().second.first;
    int k = q.front().second.second;
    q.pop();
    if(x==h-1 && y==w-1){
      printf("%d", depth);
      break;
    }
    for(int i=0; i<12; i++){
      if(k==0 && i>3) continue;
      int X = x + dx[i];
      int Y = y + dy[i];
      if(X>=0 && Y>=0 && X<h && Y<w && v[X][Y][k]==0){
        v[X][Y][k]=1;
        q.push({{X,Y},{depth+1,i<=3?k:k-1}});
      }
    }
  }
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
/*

 	x	 	x	 
x	 	 	 	x
 	 	말	 	 
x	 	 	 	x
 	x	 	x	 

남아있는 k개수가 같아야지 방문체크가 가능하다.

 W와 H는 1이상 200이하의 자연수이고, K는 0이상 30이하의 정수
1
4 4
0 0 0 0
1 0 0 0
0 0 1 0
0 1 0 0

4

1
10 2
0 0 0 0 0 0 0 0 0 0
0 1 1 0 1 1 1 0 1 0
*/

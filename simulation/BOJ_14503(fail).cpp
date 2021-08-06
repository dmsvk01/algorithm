#include <iostream>
#define VMAX 51

using namespace std;

int n,m;
int b[VMAX][VMAX]={0};
int v[VMAX][VMAX]={0};
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
void solve(int x, int y, int d){
  int count=0;
  int back=0;
  int result=0;
  /*
  현재 위치를 청소한다.
현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색한다.
왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
로봇 청소기는 이미 청소되어있는 칸을 또 청소하지 않으며, 벽을 통과할 수 없다.
*/
  while(1){
    if(v[x][y]==0){ // 현재 칸 청소 후 result 하나 올린다.
      v[x][y]=1;
      result++;
    }
    if(count==5){ // 4방향 모두 탐색했는데 걸린게 없으면 후진.
      count=0;
      if(d==0) back=2;
      if(d==1) back=3;
      if(d==2) back=0;
      if(d==3) back=1;
      //만약 후진불가능이면 끝
      x += dx[back];
      y += dy[back];
      if(b[x][y]==1) break;
    }else{ // 4방향 탐색 중
      if(d==-1) d=3;
      count++;
      int X = x + dx[d]; // 왼쪽방향에 
      int Y = y + dy[d];
      if(b[X][Y]==0 && v[X][Y]==0){ // 만약 왼쪽방향이 빈칸이고 청소하지 않은 곳이라면
        x = X; // d(해당) 방향으로 전진한다.
        y = Y;
        count=0;
      }
      d--; // 현재위치에서 왼쪽방향 설정
    }
  }
  printf("%d", result);
  return ;
}

int main(){
  cin >> n >> m;
  int x,y,d; cin >> x >> y >> d;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &b[i][j]);
    }
  }
  solve(x,y,d-1);
  return 0;
}
/*


11 10
7 4 0
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1

57
*/

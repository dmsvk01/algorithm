#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int b[300][300];
int check[300][300];
int v[300][300];
int count=0, n, m, startx, starty, endx, endy;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void input(){
  string a;
  scanf("%d %d", &n, &m);
  scanf("%d %d %d %d", &startx, &starty, &endx, &endy);
  for(int i=0; i<n; i++){
    cin >> a;
    for(int j=0; j<m; j++){
      b[i][j] = a[j] - 48;
    }
  }
}

void solve(){
  while(1){
    //체크, 방문배열 초기화
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        check[i][j]=0;
        v[i][j]=0;
      }
    }
    //start 넣고 초기 세팅
    queue<pair<int,int>> q;
    q.push({startx-1,starty-1});
    v[startx-1][starty-1]=1;
    check[startx-1][starty-1]=1;

    // 0 영역 체크
    while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=m)
          continue;
        if(b[nx][ny] == 0 && v[nx][ny] == 0){// 빈공간 중 방문 안한 곳 발견
          q.push({nx,ny}); // 빈공간 q에 넣기
          v[nx][ny]=1; // 방문체크
          check[nx][ny]=1; // 빈공간 체크
        }
      }
    }
    count++;
    //빈공간 체크한 것 토대로 점프 연산
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(check[i][j]==1){
          for(int k=0; k<4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx<0 || ny<0 || nx>=n || ny>=m)
              continue;
            // 빈공간 영역의 상하좌우를 b - 0으로 초기화
            if(b[nx][ny]=='#'-48){
              printf("%d", count);
              return ;
            }
            b[nx][ny]=0;
          }
        }
      }
    }
  }
}

int main(){
  input();
  solve();
  return 0;
}

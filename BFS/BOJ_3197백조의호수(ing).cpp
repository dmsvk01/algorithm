#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define VMAX 100
#define INF 987654321

using namespace std;

int n,m;
char b[VMAX][VMAX];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<pair<int,int>> a;

bool bfs(){
  queue<pair<int,int>> q;
  //printf("------------%d, %d\n",a[0].first, a[0].second);
  //printf("------------%d, %d\n",a[1].first, a[1].second);
  int v[VMAX][VMAX]={0};
  q.push({a[0].first, a[0].second});
  v[a[0].first][a[0].second]=1;
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    //printf("x:%d, y:%d b[%d][%d]:%c\n", x,y,x,y,b[x][y]);
    if(x == a[1].first && y == a[1].second){
      return true;
    }
    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(x>=0 && y>=0 && x<n && y<m && v[nx][ny]==0){
        if(b[nx][ny]=='.' || b[nx][ny]=='L'){
          v[nx][ny]=1;
          q.push({nx,ny});
        }
      }
    }
  }
  return false;
}

int main(){
  cin >> n >> m;
  int count=0;
  for(int i=0; i<n; i++){
    string s; cin >> s;
    for(int j=0; j<s.size(); j++){
      b[i][j] = s[j];
      if(b[i][j]=='L'){
        a.push_back({i,j});
      }
    }
  }
  while(1){
    bool v[VMAX][VMAX];
    for(int i=0; i<n; i++){ // 얼음깨기
      for(int j=0; j<m; j++){
        printf("%c", b[i][j]);
      }
      printf("\n");
    }
    printf("\n");
    if(bfs()){
     // printf("-------------%d--------------\n",p);
      printf("%d", count);
      return 0;
    }

    count++;

    for(int i=0; i<n; i++){ // 다음날에 깨질 얼음들 체크
      for(int j=0; j<m; j++){
        if(b[i][j]=='.' || b[i][j]=='L'){
          for(int k=0; k<4; k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(x>=0 && y>=0 && x<n && y<m){
              if(b[x][y]=='X'){
                v[x][y]=true;
              }
            }
          }
        }
      }
    }

    for(int i=0; i<n; i++){ // 얼음깨기
      for(int j=0; j<m; j++){
        if(b[i][j]=='X' && v[i][j]==true){
          b[i][j]='.';
        }
      }
    }
  }
  return 0;
}
/*
4 11
..XXX...X..
.X.XXX...L.
....XXX..X.
X.L..XXX...

5 5
LXXXX
XXXXX
XXXXX
XXXXX
XXXXL


bool 배열 초기값
*/

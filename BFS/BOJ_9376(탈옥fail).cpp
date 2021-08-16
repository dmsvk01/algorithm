#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define VMAX 100
#define INF 987654321

using namespace std;

int n,m;
char b[VMAX+2][VMAX+2];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int result[VMAX+2][VMAX+2]={0};

struct point {
	int x, y, c;
};

struct cmp{
	bool operator()(point a, point b) {
		return a.c > b.c;
	}
};
void bfs(int sx, int sy){
  int v[VMAX+2][VMAX+2]={0};
  priority_queue<point, vector<point>, cmp> q;
  q.push({sx,sy,0});
  v[sx][sy]=1;
  while(!q.empty()){
    point p = q.top();
    int x = p.x;
    int y = p.y;
    int c = p.c;
    q.pop();
    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx>=0 && nx<n+2 && ny>=0 && ny<m+2 && v[nx][ny]==0){
          //printf("x:%d, y:%d\n",nx,ny);
        if(b[nx][ny]=='$' || b[nx][ny]=='.'){
          q.push({nx, ny, c});
          v[nx][ny]=1;
          result[nx][ny]+=c;
        }
        if(b[nx][ny]=='#'){
          q.push({nx, ny, c+1});
          v[nx][ny]=1;
          result[nx][ny]+=c+1;
        }
      }
    }
  }
}

int main(){
    int t=0; cin >> t;
    for(int T=0; T<t; T++){
    for(int i=0; i<n+2; i++){
        for(int j=0; j<m+2; j++){
          result[i][j]=0;
        }
      }
  cin >> n >> m;
  int vmin=INF;
  vector<pair<int,int>> start;
  for(int i=0; i<m+2; i++){
      b[0][i]='.';
      b[n+1][i]='.';
  }
  for(int i=1; i<=n; i++){
    string s;
    cin >> s;
    s = '.' + s + '.';
    for(int j=0; j<s.size(); j++){
      char a = s[j];
      b[i][j] = a;
      if(a=='$'){
        start.push_back({i,j});
      }
    }
  }
  bfs(0,0);
  bfs(start[0].first, start[0].second);
  bfs(start[1].first, start[1].second);
  
  for(int i=0; i<n+2; i++){
    for(int j=0; j<m+2; j++){
      if(b[i][j]=='#'){
          result[i][j]-=2;
      }
    }
  }
  for(int i=0; i<n+2; i++){
    for(int j=0; j<m+2; j++){
      if(b[i][j]!='*'){
          vmin = min(vmin, result[i][j]);
      }
    }
  }
  printf("%d\n", vmin);
    }
  return 0;
}

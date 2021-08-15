#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define VMAX 100
#define INF 987654321

using namespace std;

typedef struct{
  int door;
  vector<pair<int,int>> d;
  int x;
  int y;
}Point;

int n,m; 
vector<pair<int,int>> result;
char b[VMAX][VMAX];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct compare{
	bool operator()(Point a, Point b){
		return a.door > b.door;
	}
};



void bfs(int sx, int sy){
  priority_queue<Point, vector<Point>, compare> pq;
  int v[VMAX][VMAX]={0};
  Point sp;
  pq.push({-0, sp.d, sx, sy});
  v[sx][sy]=1;
  printf("-----------------------\n");
  while(!pq.empty()){
    Point p = pq.top();
    pq.pop();
    vector<pair<int,int>> d = p.d;
    int x = p.x;
    int y = p.y;
    int door = p.door;
    if(x==0 || x==n-1 || y==0 || y==m-1){
      while(!d.empty()){
        result.push_back(d.back());
        int kx = d.back().first;
        int ky = d.back().second;
        b[kx][ky]='.';
        printf("x:%d, y:%d\n", kx,ky);
        d.pop_back();
      }
      break;
    }
    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx>=0 && nx<n && ny>=0 && ny<m && v[nx][ny]==0){
        if(b[nx][ny]=='$' || b[nx][ny]=='.'){
          pq.push({door, d, nx, ny});
          v[nx][ny]=1;
        }
        if(b[nx][ny]=='#'){
          d.push_back({nx,ny});
          pq.push({door+1, d, nx, ny});
          d.pop_back();
          v[nx][ny]=1;
        }
      }
    }
  }
}

int main(){
  cin >> n >> m;
  vector<pair<int,int>> start;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    for(int j=0; j<s.size(); j++){
      char a = s[j];
      b[i][j] = a;
      if(a=='$'){
        start.push_back({i,j});
      }
    }
  }
  bfs(start[0].first, start[0].second);
  printf("\n");
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      printf("%c",b[i][j]);
    }
    printf("\n");
  }

  bfs(start[1].first, start[1].second);
  sort(result.begin(), result.end());
  result.erase(unique(result.begin(), result.end()), result.end());
  cout << result.size();
  return 0;
}

/*
3
5 9
****#****
*..#.#..*
****.****
*$#.#.#$*
*********
5 11
*#*********
*$*...*...*
*$*.*.*.*.*
*...*...*.*
*********.*
9 9
*#**#**#*
*#**#**#*
*#**#**#*
*#**.**#*
*#*#.#*#*
*$##*##$*
*#*****#*
*.#.#.#.*
*********
*/

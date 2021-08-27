#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define VMAX 1000
#define INF 987654321

using namespace std;

pair<int,int> from;
pair<int,int> to;

int dx[8] = {3,3,2,-2,-3,-3,-2,2};
int dy[8] = {2,-2,-3,-3,-2,2,3,3};

bool check(int x,int y,int i){
  int tx = to.first;
  int ty = to.second;
  if(i==0)
    if((tx==x+1&&ty==y)||(tx==x+2&&ty==y+1)) return false;
  if(i==1)
    if((tx==x+1&&ty==y)||(tx==x+2&&ty==y-1)) return false;
  if(i==2)
    if((tx==x&&ty==y-1)||(tx==x+1&&ty==y-2)) return false;
  if(i==3)
    if((tx==x&&ty==y-1)||(tx==x-1&&ty==y-2)) return false;
  if(i==4)
    if((tx==x-1&&ty==y)||(tx==x-2&&ty==y-1)) return false;
  if(i==5)
    if((tx==x-1&&ty==y)||(tx==x-2&&ty==y+1)) return false;
  if(i==6)
    if((tx==x&&ty==y+1)||(tx==x-1&&ty==y+2)) return false;
  if(i==7){
    if((tx==x&&ty==y+1)||(tx==x+1&&ty==y+2)) return false;
    }
  return true;
}
int bfs(){
  int v[10][9]={0};
  queue<pair<pair<int,int>,int>> q;
  q.push({{from.first, from.second}, 0});
  v[from.first][from.second] = 1;
  while(!q.empty()){
    int x = q.front().first.first;
    int y = q.front().first.second;
    int c = q.front().second;
    q.pop();
    if(x==to.first && y==to.second){
      return c;
    }
    for(int i=0; i<8; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx>=0 && ny>=0 && nx < 10 && ny < 9 && v[nx][ny]==0){
        if(check(x,y,i)==true){
          //printf("x:%d, y:%d, c:%d, i:%d\n",x,y,c,i);
          v[nx][ny]=1;
          q.push({{nx,ny}, c+1});
        }
      }
    }

  }

  return -1;
}

int main(){
  cin >> from.first >> from.second;
  cin >> to.first >> to.second;

  cout << bfs();

  return 0;
}

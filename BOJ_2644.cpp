#include <iostream>
#include <vector>
#include <queue>
#define VMAX 101

using namespace std;

vector<int> a[VMAX];
int v[VMAX]={0};

int bfs(int src, int dst){
  queue<pair<int, int>> q;
  q.push({src, 0});
  v[src]=1;
  while(!q.empty()){
    int x = q.front().first;
    int c = q.front().second;
    q.pop();
    if(x==dst){
      return c;
    }
    for(int i=0; i<a[x].size(); i++){
      int y = a[x][i];
      //printf("x:%d y:%d\n",x,y);
      if(v[y]==0){
        v[y]=1;
        q.push({y,c+1});
      }
    }
  }
  
  return -1; 
}

int main(){
  int n; cin >> n;
  int src, dst; cin >> src >> dst;
  int m; cin >> m;
  for(int x,y,i=0; i<m; i++){
    scanf("%d %d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }
  int result = bfs(src, dst);
  printf("%d", result);
}
/*
9
8 6
7
1 2
1 3
2 7
2 8
2 9
4 5
4 6
*/

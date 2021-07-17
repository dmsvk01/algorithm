#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#define NUM 2100000000

using namespace std;

queue<int> q;
int v;
vector<pair<int,int>> a[20001]; 
int res[20001];
int visit[20001]={0};

void bfs(int start){
  for(int i=1; i<=v; i++) res[i]=NUM;
  q.push(start);
  res[start]=0;
  visit[start]=1;
  while(!q.empty()){
    int x = q.front();
    q.pop();
    for(int i=0; i<a[x].size(); i++){
      int y = a[x][i].first;
      int w = a[x][i].second;
      if(visit[y]==0){
        q.push(y);
        visit[y]=1;
      }
      res[y] = min(res[y], res[x]+w);
    }
  }
  for(int i=1; i<=v; i++){
    if(res[i]==NUM) printf("INF\n");
    else printf("%d\n", res[i]);
  }
}

int main(){
  int e; cin >> v >> e;
  int start; cin >> start;
  for(int x,y,w,i=0; i<e; i++){
    scanf("%d %d %d",&x,&y,&w);
    a[x].push_back(make_pair(y,w));
  }
  bfs(start);
  return 0;
}

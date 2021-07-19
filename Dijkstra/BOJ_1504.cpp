#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define VMAX 801
#define INF 2100000000

using namespace std;

vector<pair<int,int>> a[VMAX];
bool pass = true;

int dijkstras(int start, int end){
  priority_queue<pair<int,int>> pq;
  int dist[VMAX];
  for(int i=1; i<VMAX; i++) 
    dist[i] = INF;
  dist[start]=0;
  pq.push({-0, start});
  while(!pq.empty()){
    int x = pq.top().second;
    int wx = -pq.top().first;
    pq.pop();
    if(x==end) return wx;

    for(int i=0; i<a[x].size(); i++){
      int y = a[x][i].first;
      int wy = a[x][i].second;
      if(dist[y] > dist[x] + wy){
        dist[y] = dist[x] + wy;
        pq.push({-dist[y], y});
      }
    }
  }
  pass = false;
  return 0;
}

int main(){
  int n,e; cin >> n >> e;
  int v1, v2;
  for(int x,y,w,i=0; i<e; i++){
    scanf("%d %d %d", &x, &y, &w);
    a[x].push_back({y,w});
    a[y].push_back({x,w});
  }
  cin >> v1 >> v2;
  int num1 = dijkstras(1, v1) + dijkstras(v1, v2) + dijkstras(v2, n);
  int num2 = dijkstras(1, v2) + dijkstras(v2, v1) + dijkstras(v1, n);
  int result = min(num1, num2);
  if(pass)
    printf("%d\n", result);
  else
    printf("-1\n");
}

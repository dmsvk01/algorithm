#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define VMAX 20001
#define INF 210000000

using namespace std;

int dist[VMAX];
int v[VMAX]={0};
vector<pair<int, int>> a[VMAX];

void dijkstras(int start, int n){
  for(int i=1; i<VMAX; i++) dist[i] = INF;
  priority_queue<pair<int, int>> pq;
  pq.push({-0, start});  // first : 가중치 합  second : 현재노드 인덱스  왜 first가 가중치인가? -> 우선순위 큐 활용을 위해서인가??
  // 그냥 push(start)만 하면 되는거 아닌가? -> NO! 굳이 거리인 0을 추가하는 이유는 우선순위큐의 성질을 활용해서 연결된 노드중 최단path를 갖는 index를 찾기 위해서 이다. 
  dist[start]=0;
  while(!pq.empty()){
    int wx = -pq.top().first;
    int x = pq.top().second;
    v[x] = 1;
    pq.pop();
    for(int i=0; i<a[x].size(); i++){
      int y = a[x][i].first;
      int wy = a[x][i].second;
      if(v[y]==1) continue;
      if(dist[y] > wx + wy){
        dist[y] = dist[x] + wy; //여기서 wx와 dist[x]는 같다?
        pq.push({-dist[y], y});
      }
    }
  }
  for(int i=1; i<=n; i++){
    if(dist[i]==INF) printf("INF\n");
    else printf("%d\n", dist[i]);
  }
}

int main(){
  int n,e; cin >> n >> e;
  int start; cin >> start;
  for(int x,y,w,i=0; i<e; i++){
    scanf("%d %d %d", &x,&y,&w);
    a[x].push_back({y,w});
  }

  dijkstras(start, n);

}
/*
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
*/

#include <iostream>
#include <vector>
#include <queue>
#define VMAX 10001

using namespace std;

vector<pair<int,int>> a[VMAX];

int solve(){
  int result=0;;
  int v[VMAX]={0};
  priority_queue<pair<int,int>> pq; // priority_queue를 사용하여 연결된 간선중 가장 작은 가중치를 갖는 값을 우선적으로 탐색한다.
  pq.push({-0, 1}); // 어디서 시작하는지 관계없으므로 임의로 1번 정점에서 시작한다.
  //이때 1번 노드는 방문처리 하지 않는다. 1번 노드로 시작하는 것이지 탐색을 진행한게 아니기 때문이다.
  while(!pq.empty()){
    int x = pq.top().second;
    int w = -pq.top().first;
    pq.pop();
    if(v[x]==1) continue; // 이미 방문한 정점이면 pass
    
    result+=w; // 가중치 ++ 
    v[x]=1; // 방문체크
    for(int i=0; i<a[x].size(); i++){ // 방문한 노드에 연결된 모든 간선을 pq에 추가한다.
      int y = a[x][i].first;
      int wy = a[x][i].second;
      pq.push({-wy,y});
    }
  }

  return result;
}

int main(){
  int n,e; cin >> n >> e;
  for(int x,y,w,i=0; i<e; i++){
    scanf("%d %d %d", &x, &y ,&w);
    a[x].push_back({y,w});
    a[y].push_back({x,w});
  }
  cout << solve();
  return 0;
}
/*
3 3
1 2 1
2 3 2
1 3 3

6
9
1 2 5
1 3 4
2 3 2
2 4 7
3 4 6
3 5 11
4 5 3
4 6 8
5 6 8

최소스패닝 트리 
1. 크루스칼 알고리즘
-간선 중심으로 탐색
-유니온 파인드 알고리즘 기반
-w작은 간선부터 쭉 연결하면서 사이클생기면 pass
-V-1개의 간선을 선택할때 까지 진행

2. 프림 알고리즘
- 노드 중심으로 탐색
- priority_queue 사용.
- 지금까지의 노드 집합과 연결된 w가 가장 작은 간선의 노드를 선택한다.
- 이때 이미 방문한 노드면 pass 방문한 노드만 아니면 싸이클이 무조건 안 생긴다.
- pq 빌때까지 진행 -> 이미 방문한 정점들이면 알아서 다 빠지기 때문이다.
* 프림으로 풀거야
*/

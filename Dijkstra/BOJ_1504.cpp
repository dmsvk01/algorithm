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
/*
접근방식
디엑스트라 알고리즘을 응용하는 문제였다.
1번과 n번사이 최단경로 중에 두 정점 v1, v2를 들려야 한다는 조건이 붙는다.
여기서 그러한 경로가 없다면 -1을 출력하라는 조건이 뭔가 걸렸다. 생각해 보니 그러한 경로가 없는 것은 그래프가 단절되어서 아예 연결이 안된 경우를 의미하는 것이었다.

두 정점을 들리는 조건을 만족하는 경우는 2가지다
1 -> v1 -> v2 -> n
1 -> v2 -> v1 -> n
이 두가지 경우 중에 더 작은 값이 최종 답이 된다.

그럼 그래프가 단절된 경우를 어떻게 구별하나?
디엑스트라를 수행시에 도착해야 하는 정점에 도착하면 그 정점의 dist값을 반환하도록 했다.
여기서 걸리지 않고 while을 빠져나오는 경우는 도착 정점을 발견하지 못한, 즉 그래프가 끊어졌다고 판단하고 bool 변수로 체크해준다.
그리고 결과 출력시에 bool 변수를 고려한다.
false 라면 최단경로 탐색 불가능 -> -1
true 라면 최단경로 탐색 완료 -> result
를 출력한다.
*/





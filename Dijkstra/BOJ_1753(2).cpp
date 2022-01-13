#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int v,e, start;
vector<pair<int,int>> a[20001];
priority_queue<pair<int,int>> pq;
int dist[20001];

void input(){
  scanf("%d %d %d", &v,&e,&start);
  for(int i=0,x,y,w; i<e; i++){
    scanf("%d %d %d", &x, &y, &w);
    a[x].push_back({y,w});
    //a[y].push_back({x,w});
  }
}

void solve(){
  //1. dist 초기화
  for(int i=1; i<=v; i++){
    dist[i] = INF;
  }

  //2. 시작점 계산
  dist[start] = 0;
  pq.push({-0, start});

  //3. while loop
  while(!pq.empty()){
    int x = pq.top().second;
    int wx = -pq.top().first;
    pq.pop();

    //이미 구해진 값 즉, dist[x]의 값이 이미 더 작을 경우는 고려할 필요 없음.
    if(wx > dist[x]) continue;

    for(int i=0; i<a[x].size(); i++){
      int y = a[x][i].first;
      int wy = a[x][i].second;
      // 현재 계산된 최소가중치 갖는 노드를 들려서 가는 경로가 더 짧은 경우에 갱신해준다.
      if(wx + wy < dist[y]){
        dist[y] = wx + wy;
        pq.push({-dist[y], y});
      }
    }
  }
  for(int i=1; i<=v; i++){
    if(dist[i]==INF)
      printf("INF\n");
    else 
      printf("%d\n", dist[i]);
  }
}

int main(){
  input();
  solve();
  return 0;
}

/*
반성포인트
1. priority_queue 의 비교값은 first가 우선이므로 first자리에 -w이 들어가야 한다.
2. outofbound - 간선은 자연수로 계산하게 되므로 배열할당시 +1만큼 늘린다. 20000 -> 20001

*/

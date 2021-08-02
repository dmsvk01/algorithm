#include <iostream>
#include <vector>
#include <queue>
#define VMAX 1001
#define INF 987654321

using namespace std;

vector<pair<int,int>> v[VMAX];
vector<pair<int,int>> opt;
int dist[VMAX];
int n;

void dijkstras1(int start){
  priority_queue<pair<int,int>> pq;
  for(int i=0; i<=n; i++) dist[i] = INF;
  dist[1]=0;
  pq.push({-0, 1});
  while(!pq.empty()){
    int x = pq.top().second;
    int wx = -pq.top().first;
    pq.pop();
    if(x==n) return ;
    for(int i=0; i<v[x].size(); i++){
      int y = v[x][i].first;
      int wy = v[x][i].second;
      //printf("%d %d\n", x,y);
      if(dist[y] > dist[x] + wy){
        dist[y] = dist[x] + wy;
        pq.push({-dist[y], y});
        opt.push_back({x,y});
        //printf("%d %d발견 초기화 : dist[%d]:%d\n", x,y,y,dist[y]);
      }
    }
  }
}

void dijkstras2(int start, pair<int,int> a){
  int tx = a.first;
  int ty = a.second;
  priority_queue<pair<int,int>> pq;
  for(int i=0; i<=n; i++) dist[i] = INF;
  dist[1]=0;
  pq.push({-0, 1});
  while(!pq.empty()){
    int x = pq.top().second;
    int wx = -pq.top().first;
    pq.pop();
    if(x==n) return ;
    for(int i=0; i<v[x].size(); i++){
      int y = v[x][i].first;
      int wy = v[x][i].second;
      if(!(y==ty && x==tx) && !(y==tx && x==ty) && dist[y] > dist[x] + wy){
        dist[y] = dist[x] + wy;
        pq.push({-dist[y], y});
      }
    }
  }
}

int main(){
  int m; cin >> n >> m;
  int result=0;
  for(int x,y,w,i=0; i<m; i++){
    scanf("%d %d %d", &x, &y, &w);
    v[x].push_back({y,w});
    v[y].push_back({x,w});
  }
  dijkstras1(1); // st에 담기
  //printf("init value : %d\n", dist[n]);
  for(int i=1; i<=n; i++){
    //printf("%d : %d\n", i,dist[i]);
  }
  if(dist[n]==INF){
    printf("0");
    return 0;
  }
  int minv = dist[n];

  for(int i=0; i<opt.size(); i++){
    dijkstras2(1, opt[i]);
    //printf("----%d----\n", i+1);
    //printf("%d : %d\n", i,dist[n]);

    if(dist[n]==INF){
      printf("-1");
      return 0;
    }else{
      result = max(result, dist[n] - minv);
    }
  }
  printf("%d", result);
}
/*

6 7
1 2 1
1 4 3
3 6 1
4 5 1
2 3 2
3 4 1
5 6 2

2

8 11
1 2 1
1 5 8
1 7 9
2 5 2
3 4 4
3 6 3
3 8 5
4 6 10
4 8 11
5 6 6
5 7 7

-1


1->n
도로는 유일하고 양방향 가중치양의정수
어떤 도로를 막아 탈출 불가능하게 만들면 -1
도로를 막아 탈출시간을 지연할 수 있는 최대값 구하기
지연효과가 없으면 0 -> 무슨경우지? 아예 탈출 불가능한 경우?

1. 1부터n으로의 dijkstras 진행 -> 만약 탈출불가능 한 경우 0 출력
2. 1을 진행하면서 opt에 다가 거치는 도로들을 담는다.
3. opt에 있는 도로 개수만큼 for문 진행하면서 각 도로를 막는 경우에 대해 
dijkstras를 진행하면서 기존 최소값보다 얼마나 큰지를 계산한다.
-> 만약 탈출불가능 (INF)이면 -1
-> INF 아니면 기존 최소값과 차이를 구해서 max와 비교 후 갱신
*/

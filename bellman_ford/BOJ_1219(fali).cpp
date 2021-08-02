#include <iostream>
#include <vector>
#define VMAX 101
#define INF 987654321

using namespace std;

vector<pair<pair<int,int>,int>> a;
int value[VMAX];
int dist[VMAX];
int n,e,src,dst,result;
bool pass = true;

void ballmen_ford(int start){ 
  for(int i=0; i<n; i++) dist[i] = INF;
  dist[start] = -value[start];

  for(int i=0; i<n-1; i++){
    for(int j=0; j<e; j++){
        int x = a[j].first.first;
        int y = a[j].first.second;
        int w = a[j].second;
          if(dist[x]!=INF && dist[y] > dist[x] + w - value[y]){
            dist[y] = dist[x] + w - value[y];
          }
    }
  }

  result = dist[dst];

  for(int j=0; j<e; j++){
        int x = a[j].first.first;
        int y = a[j].first.second;
        int w = a[j].second;
          if(dist[x]!=INF && dist[y] > dist[x] + w - value[y]){
            pass = false;
            dist[y] = dist[x] + w - value[y]; // *
          }
  }
}


int main(){
  scanf("%d %d %d %d", &n, &src, &dst, &e);
  for(int x,y,w,i=0; i<e; i++){
    scanf("%d %d %d", &x, &y, &w);
    a.push_back({{x,y},w});
  }
  for(int i=0; i<n; i++){
    scanf("%d", &value[i]);
  }

  ballmen_ford(src);
  if(dist[dst]==INF){
    printf("gg");
    return 0;
  }

  pass==true && result==dist[dst]? printf("%d", -dist[dst]) : printf("Gee");
}

/*
5 0 4 7
0 1 13
1 2 17
2 4 20
0 3 22
1 3 4747
2 0 10
3 4 10
0 0 0 0 0

5 0 4 5
0 1 10
1 2 10
2 3 10
3 1 10
2 4 10
0 10 10 110 10

1. 연결이 되어있는지 확인
-> 안되어 있으면 gg
2. 출발도시부터 모든 도시로의 최단경로 구하기
-> 음의 싸이클을 찾기 위해서 이다.
-> 만약 음의 싸이클이 존재한다면 -> Gee

-> 이때 중요한 것. 싸이클이 존재한다고 해서 돈을 무제한 으로 벌 수있는 것이 아니었다.
싸이클이 돈다면 그 싸이클에서 도착지점으로 갈 수 있어야 한다.

1. 싸이클이 있다는 것이 무제한으로 돈을 벌수있다는 것을 의미하지 않는다.
2. 최대값 오버플로우 판단하지 못했음 int를 왜 넘어가는가?

*/

#include <iostream>
#include <vector>
#include <algorithm>
#define VMAX 20001
#define INF 210000000

using namespace std;

vector<pair<int, int>> a[VMAX];
// first : 연결된 노드 인덱스
// second : 가중치
int v[VMAX]={0};
int dist[VMAX];

int find_min(int n){
  int min_index=0;
  int min_value=INF;
  for(int i=1; i<=n; i++){
    if(v[i]==1) continue; // 방문안한 노드 중에
    if(min_value > dist[i]){ // dist 최소값을 갖는 인덱스를 찾아라
      min_value = dist[i];
      min_index = i;
    }
  }
  return min_index;
}

void update(int min_index){
  for(int i=0; i<a[min_index].size(); i++){
    int y = a[min_index][i].first;
    int w = a[min_index][i].second;
    if(v[y]==1) continue;
    if(dist[y] > dist[min_index] + w){
      dist[y] = dist[min_index] + w;
    }
  }
}

void dijkstras(int start, int n){
  for(int i=1; i<=n; i++) dist[i] = INF;

  //시작 인덱스 방문 처리 후 인접한 노드들의 dist값 초기화
  v[start]=1;
  dist[start]=0;
  for(int i=0; i<a[start].size(); i++){
    int y = a[start][i].first;
    int w = a[start][i].second;
    dist[y] = w;
  }
  for(int i=0; i<n-1; i++){
    int min_index = find_min(n);
    v[min_index] = 1;
    update(min_index);
  }
  return ;
}


int main(){
  int n,e; cin >> n >> e;
  int start; cin >> start;
  for(int x,y,w,i=0; i<e; i++){
    scanf("%d %d %d", &x,&y,&w);
    a[x].push_back({y,w});
  }
  dijkstras(start, n);
  for(int i=1; i<=n; i++){
    if(dist[i]==INF) printf("INF\n");
    else printf("%d\n", dist[i]);
  }
}

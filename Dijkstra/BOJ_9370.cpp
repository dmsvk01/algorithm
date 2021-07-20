#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2100000000
#define VMAX 2001

using namespace std;

int dist[VMAX]={0};

void dijkstras(int start, vector<pair<int,int>> a[]){
  for(int i=0; i<VMAX; i++) dist[i]=INF;
  dist[start]=0;
  priority_queue<pair<int,int>> pq;
  pq.push({-0, start});
  while(!pq.empty()){
    int x = pq.top().second;
    int wx = -pq.top().first;
    pq.pop();
    for(int i=0; i<a[x].size(); i++){
      int y = a[x][i].first;
      int wy = a[x][i].second;
      if(dist[y] > dist[x] + wy){
        dist[y] = dist[x] +wy;
        pq.push({-dist[y], y});
      }
    }
  }
}
int main(){
  int T; cin >> T;
  for(int k=0; k<T; k++){
    int n,m,t; cin >> n >> m >> t; // 교차로, 도로, 목적지 후보
    int s,g,h; cin >> s>> g >> h; // 출발지, g과h 사이의 도로
    
    vector<pair<int,int>> a[VMAX];
    vector<int> dst;
    int init[VMAX]={0};
    int hdist[VMAX]={0};
    int gdist[VMAX]={0};
    vector<int> res;
    int gh=0, hg=0;
    int sg=0,sh=0;

    for(int x,y,w,i=0; i<m; i++){
      scanf("%d %d %d", &x, &y, &w);
      a[x].push_back({y,w});
      a[y].push_back({x,w});
    }
    for(int x,i=0; i<t; i++){
      scanf("%d", &x);
      dst.push_back(x);
    }
    for(int i=0; i<a[g].size(); i++)
      if(a[g][i].first == h){
        gh = a[g][i].second;
        hg = a[g][i].second;
      }
    dijkstras(s,a);
    for(int i=1; i<=n; i++) init[i] = dist[i];
    sg = dist[g];
    sh = dist[h];

    dijkstras(h,a);
    for(int i=1; i<=n; i++) hdist[i] = dist[i];

    dijkstras(g,a);
    for(int i=1; i<=n; i++) gdist[i] = dist[i];

    for(int i=0; i<dst.size(); i++){
      int d = dst[i];
      if(init[d] == sg + gh + hdist[d]){
        res.push_back(d);
      }
      if(init[d] == sh + hg + gdist[d]){
        res.push_back(d);
      }
    }
    sort(res.begin(), res.end());
    for(int i=0; i<res.size(); i++) printf("%d ", res[i]);
    printf("\n");
  }
}

/*

접근방법
g와h를 잇는 간선을 통과하는 것이 최단거리라는 것을 이용해야 한다.
!! gh간선을 들러서 가는 경로와 s지점에서 바로 목적지로 탐색한 최단 경로의 가중치가 같다면 범인이 그곳으로 가고 있는 것이다.
gh간선을 들르는 2가지 방법이 있다.
s -> g -> h -> dst
s -> h -> g -> dst

dijkstras를 3번 진행해 준다.
s,g,h로 부터 시작하는 모든노드에 대한 최단거리를 구해준다. -> 배열을 3개 할당하였다.
그리고 s로 부터 출발하는 경로가 위의 2가지 방법중 하나의 루트와 경로 가중치가 같다면 최단거리로 이동하는 경우이므로 답이 된다.
답이 되는 최단경로를 모두 구하고 오름차순 정렬 후 출력해준다.


첫 번째 줄에는 테스트 케이스의 T(1 ≤ T ≤ 100)가 주어진다. 각 테스트 케이스마다

첫 번째 줄에 3개의 정수 n, m, t (2 ≤ n ≤ 2 000, 1 ≤ m ≤ 50 000 and 1 ≤ t ≤ 100)가 주어진다. 각각 교차로, 도로, 목적지 후보의 개수이다.
두 번째 줄에 3개의 정수 s, g, h (1 ≤ s, g, h ≤ n)가 주어진다. s는 예술가들의 출발지이고, g, h는 문제 설명에 나와 있다. (g ≠ h)
그 다음 m개의 각 줄마다 3개의 정수 a, b, d (1 ≤ a < b ≤ n and 1 ≤ d ≤ 1 000)가 주어진다. a와 b 사이에 길이 d의 양방향 도로가 있다는 뜻이다.
그 다음 t개의 각 줄마다 정수 x가 주어지는데, t개의 목적지 후보들을 의미한다. 이 t개의 지점들은 서로 다른 위치이며 모두 s와 같지 않다.
교차로 사이에는 도로가 많아봐야 1개이다. m개의 줄 중에서 g와 h 사이의 도로를 나타낸 것이 존재한다. 또한 이 도로는 목적지 후보들 중 적어도 1개로 향하는 최단 경로의 일부이다.

2
5 4 2
1 2 3
1 2 6
2 3 2
3 4 4
3 5 3
5
4
6 9 2
2 3 1
1 2 1
1 3 3
2 4 4
2 5 5
3 4 3
3 6 2
4 5 4
4 6 3
5 6 7
5
6

4 5
6
*/

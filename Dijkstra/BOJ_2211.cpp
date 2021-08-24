/******************************************************************************

1. 모든 노드 연결 -> 최소개수의 회선복구
2. 슈퍼컴퓨터가 다른 컴퓨터들과 통신하는데 걸리는 최소 시간이, 
원래의 네트워크에서 통신하는데 걸리는 최소 시간보다 커져서는 안 된다.

4 5
1 2 1
1 4 4
1 3 2
4 2 2
4 3 3

-> 다익스크라?
*******************************************************************************/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define VMAX 1000 + 1
#define INF 987654321

using namespace std;

int n,m;
vector<pair<int,int>> a[VMAX];
int parent[VMAX];

void dijkstra(int start){
    int dist[VMAX];
    for(int i=0; i<VMAX; i++) dist[i] = INF;
    priority_queue<pair<int,int>> pq;
    pq.push({-0, start});
    dist[start]=0;
    //parent[start]=-1;
    while(!pq.empty()){
        int x = pq.top().second;
        int wx = -pq.top().first;
        pq.pop();
        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i].first;
            int wy = a[x][i].second;
            if(dist[y] > wy + wx){
                dist[y] = wy + wx;
                pq.push({-dist[y], y});
                parent[y] = x;
            }
        }
    }
    return ;
}

int main()
{
    cin >> n >> m;
    for(int x,y,w,i=0; i<m; i++){
        scanf("%d %d %d", &x, &y, &w);
        a[x].push_back({y,w});
        a[y].push_back({x,w});
    }
    dijkstra(1);
    printf("%d\n", n-1);
    for(int i=2; i<=n; i++){
        printf("%d %d\n", parent[i], i);
    }
    return 0;
}

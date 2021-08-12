#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define VMAX 1001
#define INF 987654321

using namespace std;

int n,e,target;
vector<pair<int,int>> a[VMAX];
int dist[VMAX];

int dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    for(int i=0; i<VMAX; i++) dist[i]=INF;
    pq.push({-0, start});
    dist[start]=0;
    while(!pq.empty()){
        int x = pq.top().second;
        int wx = -pq.top().first;
        pq.pop();
        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i].first;
            int wy = a[x][i].second;
            if(dist[y] > dist[x] + wy){
                dist[y] = dist[x] + wy;
                pq.push({-dist[y], y});
            }
        }
    }
    return -1;
}

int main(){
    cin >> n >> e >> target;
    int tdist[VMAX];
    int result=0;
    for(int x,y,w,i=0; i<e; i++){
        scanf("%d %d %d", &x, &y, &w);
        a[x].push_back({y,w});
    }
    
    dijkstra(target);
    for(int i=1; i<=n; i++){
        tdist[i] = dist[i];
    }

    for(int i=1; i<=n; i++){
        if(i==target) continue;
        dijkstra(i);
        result = max(result, tdist[i] + dist[target]);
    }
    cout << result;
}

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define VMAX 100 + 1
#define INF 987654321

using namespace std;

int n,r,m;
int item[VMAX];
vector<pair<int,int>> a[VMAX];
int result=0;

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    int dist[VMAX];
    int v[VMAX]={0};
    for(int i=0; i<VMAX; i++) dist[i]=INF;
    int sum=0;
    
    pq.push({-0,start});
    dist[start]=0;
    v[start]=1;
    sum+=item[start];

    while(!pq.empty()){
        int x = pq.top().second;
        int wx = -pq.top().first;
        pq.pop();
        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i].first;
            int wy = a[x][i].second;
            if(dist[y] > wy + wx && wy + wx <= r){
                dist[y] = wy + wx;
                pq.push({-dist[y], y});
                if(v[y]==0)
                  sum+=item[y];
                v[y]=1;
            }
        }
    }
    
    result = max(result, sum);
    //printf("%d : %d\n", start, sum);
    return ;
}

int main()
{
    cin >> n >> r >> m;
    for(int i=1; i<=n; i++) scanf("%d", &item[i]);
    for(int x,y,w,i=0; i<m; i++){
        scanf("%d %d %d", &x, &y, &w);
        a[x].push_back({y,w});
        a[y].push_back({x,w});
    }
    for(int i=1; i<=n; i++)
        dijkstra(i);
    cout << result;
    return 0;
}

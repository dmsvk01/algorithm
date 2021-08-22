/******************************************************************************
7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4

최소스패닝 트리 priority_queue 구현 방법 remaining
1. 아무 노드나 잡는다. -> 1번 마을로 하자.
2. 1번 마을 주위에 있는 모든 간선을 pq에 넣느다.
3. pq가 널이 될떄까지 진행
3.1 가장 짧은 간선을 넣고 해당 간선의 목적지 노드 즉 y와 연결된 모든 간선을 pq에 넣는다.
n-1번 반복

관리비용이 최소가 되도록 마을들을 2개의 집합으로 나눈다는 것은 곧 
최소스패닝 트리를 구한 후 그 중에서 가장 큰 가중치는 갖는 간선을 제거한다는 의미와 같다.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define VMAX 100000 + 1

using namespace std;

int n,m;
int v[VMAX]={0};
vector<pair<int,int>> a[VMAX];
int maxWeight=0;

int solve(){
    int result=0;
    priority_queue<pair<int,int>> pq; // w값과 y 값을 저장. -> 이 둘만 해도 가능하기 때문
    pq.push({-0, 1});
    // 굳이 1번 마을에 대한 주변 간선들을넣지 않아도 루프문에 의해 해결된다.
    while(!pq.empty()){
        int w = -pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if(v[x]==1) continue;
        v[x]=1;
        
        result += w;
        maxWeight = max(maxWeight, w);
        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i].first;
            int w = a[x][i].second; // 양방향 그래프인것을 고려하지 않음.
            pq.push({-w,y});
        }
    }
    return result;
}

int main()
{
    cin >> n >> m;
    for(int x,y,w,i=0; i<m; i++){
        scanf("%d %d %d", &x, &y, &w);
        a[x].push_back({y,w});
        a[y].push_back({x,w});
    }
    
    cout << solve() - maxWeight;
    
    return 0;
}





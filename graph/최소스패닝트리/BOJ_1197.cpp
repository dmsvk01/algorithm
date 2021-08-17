#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define VMAX 10001
#define INF 987654321

using namespace std;

vector<pair<int,int>> a[VMAX];

int solve(){
  int result=0;;
  int v[VMAX]={0};
  priority_queue<pair<int,int>> pq;
  pq.push({-0, 1});

  while(!pq.empty()){
    int x = pq.top().second;
    int w = -pq.top().first;
    pq.pop();
    if(v[x]==1) continue;
    
    result+=w;
    v[x]=1;
    for(int i=0; i<a[x].size(); i++){
      int y = a[x][i].first;
      int wy = a[x][i].second;
      pq.push({-wy,y});  
    }
  }

  return result;
}

int main(){
  int n,e; cin >> n >> e;
  for(int x,y,w,i=0; i<e; i++){
    scanf("%d %d %d", &x, &y ,&w);
    a[x].push_back({y,w});
    a[y].push_back({x,w});
  }
  cout << solve();
  return 0;
}

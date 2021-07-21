#include <iostream>
#include <vector>
#define INF 100000000000
#define VMAX 501
#define EMAX 6001

using namespace std;

vector<pair<pair<int,int>, int>> a;
int n,e; 
long long dist[VMAX];
bool path_ok=true;

void bellman_ford(){
  for(int i=1; i<=n; i++) dist[i] = INF;

  dist[1] = 0;

  for(int i=1; i<=n-1; i++){
    for(int j=0; j<e; j++){
      int x = a[j].first.first;
      int y = a[j].first.second;
      int w = a[j].second;
      if(dist[x] == INF) continue;
      if(dist[y] > dist[x] + w){
        dist[y] = dist[x] + w;
      }
    }
  }
  for(int j=0; j<e; j++){
      int x = a[j].first.first;
      int y = a[j].first.second;
      int w = a[j].second;
      if(dist[x] == INF) continue;
      if(dist[y] > dist[x] + w){
        path_ok=false;
      }
    }

}
int main(){
  cin >> n >> e;
  for(int x,y,w,i=0; i<e; i++){
    scanf("%d %d %d", &x, &y, &w);
    a.push_back({{x,y},w});
  }
  bellman_ford();
  if(path_ok){
    for(int i=2; i<=n; i++){
      if(dist[i]!=INF) printf("%lld\n", dist[i]);
      else printf("-1\n");
    }
  }else{
    printf("-1\n");
  }
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
#define VMAX 401

using namespace std;

int n,m;
vector<pair<int,int>> a[VMAX];

int bfs(int start){
  int pass=0;
  queue<pair<int,int>> q; // index, weight
  q.push({start, 0});
  printf("\n\nstart:%d\n", start);
  while(!q.empty()){
    if(pass > m) break;
    int x = q.front().first;
    int wx = q.front().second;
    q.pop();
    if(pass>0 && x==start){
      printf("x:%d wx:%d 싸이클 발견!\n",x,wx);
      return wx;
    }
    pass++;
    for(int i=0; i<a[x].size(); i++){
      int y = a[x][i].first;
      int wy = a[x][i].second;
      printf("x:%d, y:%d\n",x,y);
      q.push({y,wx+wy});
    }
  }
  return -1;
}

int main(){
  int result=INF;
  cin >> n >> m;
  for(int x,y,w,i=0; i<m; i++){
    scanf("%d %d %d", &x, &y, &w);
    a[x].push_back({y,w});
  }
  for(int i=1; i<=n; i++){
    int k = bfs(i);
    result = k==-1 ? result : min(result, k);
  }
  printf("%d\n", result);
}
/*
3 4
1 2 1
3 2 1
1 3 5
2 3 2

3

9 12
1 2 1
2 3 2
3 4 3
4 1 4
5 1 5
2 8 6
5 9 7
6 9 8
7 9 9
6 5 10
6 8 11
6 7 12

*/

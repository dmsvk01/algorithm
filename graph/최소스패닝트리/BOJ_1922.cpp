#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define VMAX 1001
#define INF 987654321

using namespace std;

vector<int> findN;
priority_queue<pair<int,int>> pq[VMAX];
int n,e;
int result=0;

int solve(int x){
  findN.push_back(x);
  while(1){
    if(findN.size() == n) break;
    int minW=INF, minX, minY;
    for(int i=0; i<findN.size(); i++){
      int x = findN[i];
      if(!pq[x].empty()){ // 지금까지 만들어진 그래프의 중 한 노드에 대해 - 노드 값이 존재하면
        int w = -pq[x].top().first;
        int y = pq[x].top().second;
        if(minW > w){
          minW = w;
          minX = x;
          minY = y;
        //printf("size:%zu, x:%d, minx:%d, miny:%d\n",findN.size(), x, minX, minY);
        }
      }
    }
    if(find(findN.begin(), findN.end(), minY) == findN.end()){ // 없음 -> 즉 통과, 추가해야함
      findN.push_back(minY);
      result+=minW;
    }else{
      pq[minX].pop();
    }
  }
  return result;
}

int main(){
  cin >> n >> e;
  int minW=INF, minX, x;
  for(int y,w,i=0; i<e; i++){
    scanf("%d %d %d", &x, &y, &w);
    pq[x].push({-w, y});
    pq[y].push({-w, x});
    if(minW > w){
      minW = w;
      minX = x;
    }
  }
  for(int i=1; i<=n; i++){
    //printf("pq[%d] : %d\n", i, -pq[i].top().first);
  }
  cout << solve(minX);
  return 0;
}
/*
6
9
1 2 5
1 3 4
2 3 2
2 4 7
3 4 6
3 5 11
4 5 3
4 6 8
5 6 8
*/

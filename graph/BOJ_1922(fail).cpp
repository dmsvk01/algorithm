#include <iostream>
#include <vector>
#include <queue>
#define VMAX 1001
#define INF 987654321

using namespace std;

int n,e;
priority_queue<pair<int,int>> a[VMAX];

int solve(){
  vector<int> findC;
  int result=0;
  int mw=INF, mx, my, mj;
  for(int i=1; i<=n; i++){
    int x = i;
    int y = a[i].top().second;
    int w = -a[i].top().first;
    if(mw > w){
      mw = w;
      mx = x;
      my = y;
    }
  }
  findC.push_back(mx);
  findC.push_back(my);
  result+=mw;
  a[mx].pop();
  a[my].pop();
  while(findC.size() < n){ // n보다 같거나 커질때 까지 계속
    int mw = INF, my, mx;
    for(int i=0; i<findC.size(); i++){ // 현재까지 저장된 모든 노드들을 돌면서
      int cur = findC[i];
      int x = cur;
      int y = a[cur].top().second;
      int w = -a[cur].top().first;
      bool pass = true;
      printf("queue top\n");
      for(int k=0; k<findC.size(); k++){ // 새로추가할 노드가 기존 저장된 노드인지 판단
        if(findC[k] == y) pass = false;
        printf("%d : %d\n", findC[k], -a[findC[k]].top().first);
      }
      if(mw > w && pass){ // 최소 가중치를 갖는 간선을 찾는다.
        mw = w;
        my = y;
        mx = x;
      }
    }
    // 최소가중치를 갖는 간선의 노드를 추가한다.
    findC.push_back(my);
    result+=mw;
    a[mx].pop();
    printf("x: %d y: %d, w: %d result:%d-------------\n", mx, my, mw, result);
  }
  for(int i=0; i<findC.size(); i++){
    printf("%d ", findC[i]);
  }
  return result;
}

int main(){
  cin >> n >> e;
  for(int x,y,w,i=0; i<e; i++){
    scanf("%d %d %d", &x, &y, &w);
    a[x].push({-w,y});
    a[y].push({-w,x});
  }
  cout << solve();
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

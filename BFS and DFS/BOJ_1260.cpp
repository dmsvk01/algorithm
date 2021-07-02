#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> a[1001];
queue<int> q;
int v[1001]={0,};

void BFS(int start){
  int vb[1001]={0,};
  q.push(start);
  vb[start]=1;
  printf("%d ", start);
  while(!q.empty()){
    int x = q.front();
    q.pop();
    for(int i=0; i<a[x].size(); i++){
      int index = a[x][i];
      if(vb[index]==0){
        vb[index]=1;
        q.push(index);
        printf("%d ", index);
      }
    }
  }
}

void DFS(int x){
  printf("%d ", x);
  v[x]=1;
  for(int i=0; i<a[x].size(); i++){
    int index = a[x][i];
    if(v[index]==0){
      v[index]=1;
      DFS(index);
    }
  }
}
int main(){
  int n,m,v; cin >> n >> m >> v;
  int x,y;
  for(int i=0; i<m; i++){ // 간선개수만큼 입력받기 vector를 이용
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  //1~n까지의 인덱스를 이용
  for(int i=1; i<=n; i++){ // 각 간선의 연결된 index들을 오름차순으로 sort
    sort(a[i].begin(), a[i].end());
    for(int j=0; j<a[i].size(); j++){
      //printf("%d",a[i][j]);
    }
    //printf("\n");
  }
  DFS(v);
  printf("\n");
  BFS(v);

  return 0;
}

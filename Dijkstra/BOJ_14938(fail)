#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
//그래프가 완전히 연결이 안되어 있을 수가 있다. 전부 0으로 초기화 시키면 연결이 안되도 res값이 0이되어서 아이템을 먹어버리게 된다!!

int item[110]={0};
int n,m;
queue<int> q;
int input[110][110]={0};

int dfs(int start, int input[][110]){
  int v[110]={0};
  int res[110];
  for(int i=0; i<110; i++) res[i] = 987654321;
  int result=0;
  q.push(start);
  v[start]=1;
  res[start]=0;
  while(!q.empty()){
    int x = q.front();
    q.pop();
    for(int i=1; i<=n; i++){ // 주어진 정점 개수만큼 탐색 n
      if(input[x][i]!=0 && v[i]==0){ // 연결이 되어 있고, 방문을 안했으면
        v[i]=1;//방문체크하고
        if((res[x] + input[x][i] < res[i])) 
            res[i] = res[x] + input[x][i];
        q.push(i);
      }
    }
  }
  //printf("\n\nresult\n");
  for(int i=1; i<=n; i++){
    //printf("%d ", res[i]);
  }
  for(int i=1; i<=n; i++){
      if(m >= res[i] && res[i]!=-1){
          result+=item[i];
      }
  }
  //printf("\n!%d!\n", result);
  return result;
}

int main(){

  int r; cin >> n >> m >> r;
  for(int i=1; i<=n; i++) cin >> item[i];
  int a,b,k;
  for(int i=0; i<r; i++){
    cin >> a >> b >> k;
    input[a][b]=k;
    input[b][a]=k;
  }
  int result=0;
  for(int i=1; i<=n; i++){
    int x = dfs(i, input);
    result = max(x,result);
  }
  printf("%d\n", result);
}
/*
6 5 4
5 7 8 2 3 1
1 4 5
5 2 4
3 2 3
1 2 3
*/

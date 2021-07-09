#include <iostream>
#include <queue>

using namespace std;

int item[101]={0};
int n,m;
queue<int> q;

int dfs(int start, int v[], int res[], int input[][101]){
  int max=0;
  q.push(start);
  v[start]=1;
  while(!q.empty()){
    int x = q.front();
    q.pop();
    for(int i=0; i<n; i++){ // 주어진 정점 개수만큼 탐색 n
      if(input[x][i]!=0 && v[i]==0){ // 연결이 되어 있고, 방문을 안했으면
        v[i]=1;//방문체크하고
        if(res[i]==0) res[i] = res[x] + input[x][i];
        q.push(i);
      }
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%d ", input[i][j]);
    }
    printf("\n");
  }
  printf("\n\n\nresult\n");
  for(int i=0; i<n; i++){
    printf("%d ", res[i]);
  }
  return max;
}

int main(){
  int input[101][101]={0};
  int v[101]={0};
  int res[101]={0};

  int r; cin >> n >> m >> r;
  for(int i=1; i<=n; i++) cin >> item[i];
  int a,b,k;
  for(int i=0; i<r; i++){
    cin >> a >> b >> k;
    input[a][b]=k;
    input[b][a]=k;
  }
  int result = dfs(1, v, res, input);
}
/*
5 5 4
5 7 8 2 3
1 4 5
5 2 4
3 2 3
1 2 3

*/

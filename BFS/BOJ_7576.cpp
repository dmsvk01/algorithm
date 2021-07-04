#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> q[10];
int input[1002][1002]={0};
int v[1001][1001]={0};

int main(){
  int m,n; cin >> m >> n;

//input, v테두리 -1로 만들기
  for(int i=0; i<=m+1; i++){
    input[0][i]=-1;
    input[n+1][i]=-1;
    v[0][i]=1;
    v[n+1][i]=1;
  }
  for(int i=0; i<=n+1; i++){
    input[i][0]=-1;
    input[i][m+1]=-1;
    v[i][0]=1;
    v[i][m+1]=1;
  }
//입력받기
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      cin >> input[i][j];
    }
  }
//test code
  for(int i=0; i<=n+1; i++){
    for(int j=0; j<=m+1; j++){
      printf("%d ", input[i][j]);
    }
    printf("\n");
  }
  //불가능 체크
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(input[i-1][j]==-1 && input[i+1][j]==-1 && input[i][j-1]==-1 && input[i][j+1]==-1){
        cout << "-1" << "\n";
        return 0;
      }
    }
  }
  // 익은 토마토는 방문할 필요 없으므로 방문체크한다.
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(input[i][j]==1)
        v[i][j]=1;
    }
  }
  
  // bfs
  // how can i do?

}

/*

6 4
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1

6

*/

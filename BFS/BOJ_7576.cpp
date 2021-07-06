#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>> q;
int input[1000][1000]={0};
int v[1000][1000]={0};
vector<pair<int, int>> start;
int m,n;

int bfs(vector<pair<int, int>> start){
    int k=0, count=0;
    int kx, ky;
    for(int i=0; i<start.size(); i++){
        int x,y;
        x = start[i].first;
        y = start[i].second;
        v[x][y]=1;
        q.push(make_pair(x,y));
    }
    if(start.size()>=1){
        kx = start[0].first; // Put key value 
        ky = start[0].second;
    }
    q.push(make_pair(kx, ky));
    //printf("kx : %d, ky : %d\n", kx, ky);
    while(q.size() > 1){ // 1이면 종료
        k++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //printf("%d\n",k);
        //printf("x : %d, y : %d\n",x,y);
        if(k!=1 && x==kx && y==ky){
            count++;
            q.push(make_pair(kx,ky));
        }else{
            //토마토가 안익었고 즉 0 이고 방문 안했으면 넣는다. 방문체크까지
            if(input[x-1][y]==0 && v[x-1][y]==0 && x!=0){ // 위쪽 
                v[x-1][y]=1;
                q.push(make_pair(x-1, y));
                input[x-1][y]=1;
            }
            if(input[x+1][y]==0 && v[x+1][y]==0&&x!=n-1 ){ // 아래쪽 
                v[x+1][y]=1;
                q.push(make_pair(x+1, y));
                input[x+1][y]=1;
            }
            if(input[x][y-1]==0 && v[x][y-1]==0 &&y!=0){ // 왼쪽
                v[x][y-1]=1;
                q.push(make_pair(x, y-1));
                input[x][y-1]=1;
            }
            if(input[x][y+1]==0 && v[x][y+1]==0 && y!=m-1){ // 오른쪽 
                v[x][y+1]=1;
                q.push(make_pair(x, y+1));
                input[x][y+1]=1;
            }
        }
    }
    return count;
}
int main(){
  cin >> m >> n;

//입력받기
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> input[i][j];
    }
  }
  
  // 익은 토마토는 방문할 필요 없으므로 방문체크한다.
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(input[i][j]==1)
        start.push_back(make_pair(i,j));
    }
  }
  
  int result = bfs(start);
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(input[i][j]==0){
        printf("-1\n");
        return 0;
      }
    }
  }
  
  printf("%d\n", result);
  
  
  return 0;

}

/*
6 4
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1
6
*/

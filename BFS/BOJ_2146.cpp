#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100 

using namespace std;

int n,key=1, result=987654321;
int b[MAX][MAX]={0};
int v[MAX][MAX]={0};
int k[MAX][MAX]={0};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int i, int j, int key){
    queue<pair<int,int>> q;
    q.push({i,j});
    v[i][j]=1;
    while(!q.empty()){
        int find=0;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0&&nx<n&&ny<n){
                if(v[nx][ny]==0 && b[nx][ny]==1){
                    v[nx][ny]=1;
                    q.push({nx,ny});
                }
                if(b[nx][ny]==0){//b = 0 바다라면
                    k[x][y] = key;
                    find=1;
                }
            }
        }
        if(find==0){
            k[x][y]=-1;
        }
    }
    return ;
}

void bfs2(int i, int j, int key){
    //탐색조건 k[][] 가 -1(육지) 혹은 key(같은 테두리)가 아니라면 탐색
    int v[MAX][MAX]={0};
    queue<pair<pair<int,int>, int>> q;
    q.push({{i,j},0});
    v[i][j]=1;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int c = q.front().second;
        q.pop();
        if(k[x][y]!=0 && k[x][y]!=key){
            result = min(result, c);
            return ;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0&&nx<n&&ny<n){
                if(v[nx][ny]==0 && k[nx][ny]>=0 && k[nx][ny]!=key){ // 메모리초과 -> v체크안했었음
                    v[nx][ny] = 1;
                    q.push({{nx,ny}, c+1});
                }
            }
        }
    }
    return ;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &b[i][j]);
        }
    }
    
    //step1 : 테두리 번호 부여하기 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(b[i][j]==1 && v[i][j]==0){
                bfs(i,j,key);
                key++;
            }
        }
    }
    //step2 : 각 테두리 칸에 대해 bfs하여 다른 테두리 카능로 가는 최단거리 탐색 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int key = k[i][j];
            if(key > 0){ // key가 0보다 크다면 번호가 부여된 테두리이다.
                bfs2(i,j,key);
            }
        }
    }
    
    cout << result-1;
    
    return 0;
}

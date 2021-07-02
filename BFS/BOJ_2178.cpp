#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n,m;
int it[102][102];
int res[102][102];
int v[102][102];
queue<pair<int, int>> q;

void bfs(){
    q.push(make_pair(1,1));
    v[1][1]=1;
    res[1][1]=1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==n && y==m){
            printf("%d\n", res[x][y]);
            return ;
        }
        if(v[x-1][y]==0 && it[x-1][y]==1){
            v[x-1][y]=1;
            res[x-1][y]=res[x][y]+1;
            q.push(make_pair(x-1,y));
        }
        if(v[x+1][y]==0 && it[x+1][y]==1){
            v[x+1][y]=1;
            res[x+1][y]=res[x][y]+1;
            q.push(make_pair(x+1,y));
        }
        if(v[x][y+1]==0 && it[x][y+1]==1){
            v[x][y+1]=1;
            res[x][y+1]=res[x][y]+1;
            q.push(make_pair(x,y+1));
        }
        if(v[x][y-1]==0 && it[x][y-1]==1){
            v[x][y-1]=1;
            res[x][y-1]=res[x][y]+1;
            q.push(make_pair(x,y-1));
        }
        
    }
}

int main()
{   
    cin >> n >> m;
    string a[102];
    for(int i=0; i<102; i++){
        for(int j=0; j<102; j++){
            it[i][j]=0;
            res[i][j]=0;
            v[i][j]=0;
        }
    }
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            it[i][j+1] = a[i][j]-48;
        }
    }
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=m+1; j++){
            //printf("%d, %d : %d\n", i, j,it[i][j]);
        }
        //printf("\n");
    }
    //printf("input is done\n");
    bfs();
    
    return 0;
}

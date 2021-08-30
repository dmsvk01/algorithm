#include <iostream>
#include <queue>
#define MAX 1000

using namespace std;

int n,m;
int b[MAX][MAX];

struct P{
    int x;
    int y;
    int c;
};

struct cmp{
    bool operator()(P a, P b){
        return a.c > b.c; // 작은 것부터 빼야하므로 오름차순정렬 즉 앞이 커 클때 반환
    }
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(){
    int v[MAX][MAX]={0};
    priority_queue<P, vector<P>, cmp> pq;
    
    int start = b[0][0];
    if(start==-1) return -1;
    if(start==0) pq.push({0,0,0});
    if(start==1) pq.push({0,0,1});
    if(start==2) pq.push({0,0,2});
    v[0][0]=1;
    
    while(!pq.empty()){
        P p = pq.top();
        int x = p.x;
        int y = p.y;
        int c = p.c;
        pq.pop();
        //printf("x:%d, y:%d, c:%d\n",x,y,c);
        if(x==n-1 && y==m-1){
            return c;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                int k = b[nx][ny];
                if(v[nx][ny]==0 && b[nx][ny]!=-1){ // 방문안했고 다리 못놓는 자리가 아니라면 건설 or 통과가능
                    v[nx][ny]=1; // v[nx][ny]==1; 로 했더니 방문체크가 안되서 계속 돌고도는 현상 발생함.
                    if(k==0){
                        //printf("k:0 : nx:%d, ny:%d, c:%d\n",nx,ny,c);
                        pq.push({nx,ny,c});
                    }
                    if(k==1){
                        //printf("k:1 : nx:%d, ny:%d, c:%d\n",nx,ny,c);
                        pq.push({nx,ny,c+1});
                    }
                    if(k==2){
                        //printf("k:2 : nx:%d, ny:%d, c:%d\n",nx,ny,c);
                        pq.push({nx,ny,c+2});
                    }
                }
                
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &b[i][j]);
        }
    }
    cout << bfs();
    return 0;
}

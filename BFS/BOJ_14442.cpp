#include <iostream>
#include <queue>
#include <cstring>
#define VMAX 1000

using namespace std;

int n,m,kmax;
int b[VMAX][VMAX];
int v[VMAX][VMAX][11]={0}; // 최대 10개 까지 부술수 있다. 0 ~ 10
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(){
    queue<pair<pair<int,int>,pair<int, int>>> q;
    q.push({{0,0},{0,1}});
    v[0][0][0]=1;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int k = q.front().second.first;
        int c = q.front().second.second;
        //printf("x:%d, y:%d, k:%d, c:%d\n", x,y,k,c);
        q.pop();
        if(x==n-1 && y==m-1){
            return c;
        }
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && nx < n && ny >=0 && ny < m && v[nx][ny][k]==0){
                if(k < kmax && b[nx][ny]==1){
                    v[nx][ny][k+1]=1;
                    q.push({{nx,ny},{k+1, c+1}});
                }
                if(b[nx][ny]==0){
                    v[nx][ny][k]=1;
                    q.push({{nx,ny},{k,c+1}});
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m >> kmax;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.length(); j++){
            b[i][j] = s[j]-'0';
        }
    }
    cout << bfs();
    return 0;
}

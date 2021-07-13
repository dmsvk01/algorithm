#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>
#define MAX 1000

using namespace std;

int n,m;
int input[MAX][MAX];
int v[MAX][MAX][2];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

// 현재좌표 , 이동횟수, 벽부순횟수
queue<pair<pair<int, int>, pair<int, int>>> q;

int bfs(){
    q.push({{0,0},{1,0}});
    v[0][0][0]=1;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int count = q.front().second.first;
        int wall = q.front().second.second;
        if(x==n-1 && y==m-1){
            return count;
        }
        q.pop();
        for(int i=0; i<4; i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X >= 0 && X < n && Y >= 0 && Y < m){
              //벽이고 안부쉈으면 부수고 간다.
                if(input[X][Y]==1 && wall == 0){
                  v[X][Y][1]=1;
                  q.push({{X,Y}, {count+1, wall+1}});
                }else if(input[X][Y]==0 && v[X][Y][wall]==0){
                  v[X][Y][wall]=1;
                  q.push({{X,Y}, {count+1, wall}});
                }
            }
        }
        
    }
    return -1;
}
int main()
{
    cin >> n >> m;
    string line[n];
    for(int i=0; i<n; i++)
      cin >> line[i];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            input[i][j] = line[i][j]-48;

    printf("%d\n", bfs());
    
}

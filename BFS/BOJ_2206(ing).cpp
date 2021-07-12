#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;
int input[1000][1000];
int v[1000][1000][2]={0};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
queue<pair<pair<int, int>, int >> q;

int bfs(){
    // 좌표 , count와벽부수기횟수
    q.push({{0,0},0});
    v[0][0][0]=1; // v값이 곧 카운트값임
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int crush = q.front().second;
        printf("%d, %d, %d\n",x,y,crush);
        if(x==n-1 && y==m-1){
            return v[x][y][crush];
        }
        q.pop();
        for(int i=0; i<4; i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X >= 0 && X < n && Y >= 0 && Y < m){ // 범위안에 있는지 체크
                if(input[X][Y]==0 && v[X][Y][0]==0){ // 이동가능 + 방문안함
                    //갈 수 있는데 벽 안깨고 간 경우가 clear라면 최단경로 이므로 넣는다.
                    v[X][Y][0]=v[x][y][0]+1;
                    q.push({{X,Y}, crush});
                }
                if(input[X][Y]==1 && crush==0 && v[X][Y][1]==0){
                  // 벽이 있고 기회가 있고 이미깬 경우가 없다면
                  // 깨고 깬 방문 경우를 카운트
                    v[X][Y][1]=v[x][y][1]+1;
                    q.push({{X,Y}, crush+1});
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

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }
    
}

/*
6 4
0100
1110
1000
0000
0111
0000

15

4 4
0111
1111
1111
1110

-1

방문체크할때 실수함
깨부수고 간것인지 안깨부순 상태인지 파악해야 한다.
엄한 곳을 부수고 간 경로가 정답경로의 일부에 빨리 도달하면
정답경로를 탐색하지 않으므로 이 경우 정답을 구할 수 없다.

길이고 방문안한경우 -> 최단경로 보장
길이고 방문한 경우 -> x
벽이고 방문안한 경우 -> 깨고 서 이 다음부터 v[][][1]로 다님.
벽이고 방문한 경우 -> x

-> 어디서 깼는지에 따라 달려져 한다??
깬곳이 같고 경로가 겹치면 가지치기가 맞는데,
깬곳이 다른 경로들이 중간에 겹치면 가자치기 하면 안됨. 늦은 경로가 최적경로일 수 있음.
따라서 v를 깬곳별로 할당한다.
*/

#include <iostream>
#include <algorithm>
#include <queue>

#define VMAX 101

using namespace std;

int n;
int b[VMAX][VMAX];
int v[VMAX][VMAX];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int sx, int sy){
    queue<pair<int, int>> q;
    q.push({sx,sy});
    v[sx][sy] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X>=0 && Y>=0 && X<n && Y<n){
                if(v[X][Y]==0){
                    v[X][Y]=1;
                    q.push({X,Y});
                }
            }
        }
    }
}


int main()
{
    cin >> n;
    int result=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &b[i][j]);
        }
    }
    for(int k=0; k<=100; k++){ // 물높이 0 부터 100까지 각각의 경우의 집합수를 구한다.
        int temp=0;
        for(int i=0; i<n; i++){ // 물높이에 따른 v배열 즉 물의 잠기는 지역을 표시한다..
            for(int j=0; j<n; j++){
                v[i][j]=0;
            }
        }
        for(int i=0; i<n; i++){ // 물높이에 따른 v배열 즉 물의 잠기는 지역을 표시한다..
            for(int j=0; j<n; j++){
                if(b[i][j] <= k){
                    v[i][j] = 1;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(v[i][j] == 0){
                    bfs(i,j);
                    temp++;
                }
            }
        }
        result = max(result, temp);
    }
    cout << result;

    return 0;
}

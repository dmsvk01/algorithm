#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 105

using namespace std;

int input[MAX][MAX][MAX];
int v[MAX][MAX][MAX]={0};
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
int m,n,h;

queue<pair<pair<int,int>,pair<int,int>>> q;

int bfs(vector<pair<pair<int,int>,int>> start){
    int result=0;
    for(int i=0; i<start.size(); i++){
        int x = start[i].first.first;
        int y = start[i].first.second;
        int z = start[i].second;
        q.push({{x,y}, {z,0}});
        v[x][y][z]=1;
    }
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second.first;
        int cnt = q.front().second.second;
        result = max(result, cnt);
        q.pop();
        
        for(int i=0; i<6; i++){
            int X = dx[i]+x;
            int Y = dy[i]+y;
            int Z = dz[i]+z;
            if(X>=0&&X<n && Y>=0&&Y<m&&Z>=0&&Z<h){
                if(v[X][Y][Z]==0 && input[X][Y][Z]==0){
                    v[X][Y][Z]=1;
                    input[X][Y][Z]=1;
                    q.push({{X,Y},{Z,cnt+1}});
                }
            }
        }
        
    }
    return result;
}

int main()
{
    cin >> m >> n >> h;
    vector<pair<pair<int,int>,int>> start;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> input[j][k][i];
            }
        }
    }
    
    //익은토마토 저장
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(input[j][k][i]==1){
                    start.push_back({{j,k}, i});
                }
            }
        }
    }
    
    int result = bfs(start);
    
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(input[j][k][i]==0){
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    printf("%d\n", result);
    return 0;
}

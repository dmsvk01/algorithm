#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define VMAX 1000001

using namespace std;

int height;
int src, dst;
int u,d;
int v[VMAX]={0};
int result=-1;

void bfs(){
    queue<pair<int,int>> q;
    q.push({src, 0});
    v[src]=1;
    while(!q.empty()){
        int x = q.front().first;
        int c = q.front().second;
        q.pop();
        if(x==dst){
            result = max(result, c);
        }
        if(x+u <= height && v[x+u]==0){
            v[x+u]=1;
            q.push({x+u, c+1});
        }
        if(x-d >= 1 && v[x-d]==0){
            v[x-d]=1;
            q.push({x-d, c+1});
        }
    }
}

int main()
{
    cin >> height >> src >> dst >> u >> d;
    if(src == dst){
        printf("0");
        return 0;
    }
    bfs();
    
    if(result==-1){
        cout << "use the stairs";
    }else{
        cout << result;
    }
    return 0;
}

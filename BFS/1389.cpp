#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[101];
int rs[101][101];
queue<int> q;

void bfs(int start){
    bool count = true;
    int v[101]={0,};
    int depth=0;
    q.push(start);
    v[start]=1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<a[x].size(); i++){
            int index = a[x][i];
            if(v[index]==0){
                v[index]=1;
                q.push(index);
                rs[index][start] = rs[x][start]+1;
                rs[start][index] = rs[start][x]+1;
               // printf("%d, %d : %d\n", start, index, depth);
            }
        }
    }
}

int main()
{   
    int n,m; cin >> n >> m;
    int x,y;
    int sum=0, result=0, min=2000000000;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        bool find=true;
        for(int i=0; i<a[x].size(); i++){
            if(a[x][i] == y){
                find = false;
            }
        }
        if(find){
            a[x].push_back(y);
            a[y].push_back(x);
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            rs[i][j]=0;
        }
    }
    
    for(int i=1; i<=n; i++){
        //printf("\n\n---------%d----------\n",i);
        bfs(i);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            //printf("(%d, %d) : %d\n",i,j,rs[i][j]);
        }
        //cout << endl;
    }
    for(int i=1; i<=n; i++){
        sum=0;
        for(int j=1; j<=n; j++){
            sum+=rs[i][j];
        }
        //printf("%d : %d\n", i, sum);
        if(min > sum){ 
            min = sum;
            result = i;
        }
    }
    
    cout << result << "\n";

    return 0;
}

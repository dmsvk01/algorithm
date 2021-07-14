#include <iostream>
#include <queue>
#include <vector>
#define vMAX 20005 // 범위설정 잘못함 20000 -> 20001
using namespace std;

int check[vMAX];

bool bfs(int start, vector<int> a[]){
    queue<pair<int, int>> q;
    bool result = true;
    q.push({start, 1});
    check[start]=1;
    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        int ch = check[x];
        q.pop();
        for(int i=0; i<a[x].size(); i++){
            int c = a[x][i];
            if(check[c]==ch) result = false;
            if(check[c]==-1){
                check[c] = (cnt+1)%2;
                q.push({c,cnt+1});
            }
            //printf("x:%d, ch:%d, check[%d]:%d\n", x,ch,c,check[c]);
        }
    }
    
    return result;
}

int main()
{
    int t; cin >> t;
    for(int k=0; k<t; k++){
        int v,e; cin >> v >> e;
        vector<int> a[vMAX];
        bool result=true;
        for(int x,y,i=0; i<e; i++){
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        
        for(int i=1; i<=vMAX; i++)
            check[i]=-1;
        
        for(int i=1; i<=v; i++){ // 1부터 시작해서 v와 같을때 까지 해야하는데 범위 설정을 잘못해서 오답이 나왔음.
        // + 이미 한번 false인 상황이면 이를 고정시켜야 하는데 result = bfs()로 해서 마지막 bfs가 답으로 출력되는 상황이 되었었음. 
            //printf("%d\n",i);
            if(check[i]==-1){
                if(bfs(i, a)==false)
                    result = false;
                //printf("%d번째 - in : %d\n",k+1,i);
            }
        }
        if(result==false){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    
    return 0;
}

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> input[20001];
queue<int> q;
int visit[20001]={0};
int res[20001];

int dijk(int start, int v){
    for(int i=0; i<20001; i++) res[i]=987654321; // 초기화
    
    q.push(start);
    visit[start]=1;
    res[start]=0; // 이거 때문 고생함 ㅜㅜ
    while(!q.empty()){
        int x  = q.front();
        q.pop();
        for(int i=0; i<input[x].size(); i++){
            int a = input[x][i].first; // 어디 연결 되어있는지
            int b = input[x][i].second; // 가중치
            if(visit[a]==0){
                visit[a]=1;
                if(res[a] > res[x] + b){ 
                    res[a] = res[x] + b;
                }
                q.push(a);
            }
        }
    }
    //res가 다 채워짐 
    for(int i=1; i<=v; i++){
        if(res[i]==987654321) printf("INF ");
        else printf("%d ", res[i]);
    }
}


int main(){
    int v,e; cin >> v >> e;
    int start; cin >> start;
    for(int a,b,k,i=0; i<e; i++){
        cin >> a >> b >> k;
        input[a].push_back({b, k});
    }
    dijk(start, v);
}

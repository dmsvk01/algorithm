#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> a[101];
queue<int> q;
int v[101]={0,};

int bfs(int start, int count){
  q.push(start);
  v[start]=1;
  while(!q.empty()){
    int x = q.front();
    count++;
    //printf("x = %d\n", x);
    q.pop();
    for(int i=0; i<a[x].size(); i++){
      int index = a[x][i];
      if(v[index]==0){
        v[index]=1;
        q.push(index);
      }
    }
  }
  return count-1;
}

int main(){
  int n,m,count=0; cin >> n >> m;
  int x,y;
  for(int i=0; i<m; i++){
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  cout << bfs(1,count) << "\n";
}

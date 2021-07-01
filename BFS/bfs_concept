#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[8];
queue<int> q;
int v[8]={0,};

void bfs(int start){
  v[start] = 1;
  q.push(start);
  while(!q.empty()){
    int x = q.front();
    q.pop();
    cout << x << " ";
    for(int i=0; i<a[x].size(); i++){
      int index = a[x][i];
      if(v[index] == 0){
        v[index]=1;
        q.push(index);
      }
    }
  }
}

int main(){
  a[1].push_back(2);
  a[1].push_back(3);
  a[2].push_back(1);
  a[2].push_back(4);
  a[2].push_back(5);
  a[3].push_back(1);
  a[3].push_back(6);
  a[3].push_back(7);
  a[4].push_back(2);
  a[5].push_back(2);
  a[6].push_back(3);
  a[7].push_back(3);

  bfs(1);
}

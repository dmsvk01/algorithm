#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int x,y;
queue<int> q;
int v[100001]={0};

int bfs(int start){
  if(start==y) return 0;
  int key=-1, result=0;
  q.push(start);
  q.push(key);
  v[start]=1;

  while(!q.empty()){
    int x = q.front();
    q.pop();

    if(x == y)
      return result;

    if(x!=key){
      if(x-1 >= 0 && v[x-1]==0){
        q.push(x-1);
        v[x-1]=1;
      }
      if(x*2 <= 100000 && v[x*2]==0){
        q.push(x*2);
        v[x*2]=1;
      }
      if(x+1 <= 100000 && v[x+1]==0){
        q.push(x+1);
        v[x+1]=1;
      }
    }
    else{
      q.push(key);
      result++;
    }
  }
  return result;
}

int main(){
  cin >> x >> y;
  cout << bfs(x) << "\n";
  return 0;
}

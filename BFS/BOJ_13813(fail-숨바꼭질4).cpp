#include <iostream>
#include <vector>
#include <queue>
#define VMAX 100000 + 1

using namespace std;

int v[VMAX]={0};
int result[VMAX]={0};
int a,b;

void bfs(){
  vector<int> res;
  res.push_back(a);
  result[a]=-1;
  queue<pair<pair<int,int>, vector<int>>> q;
  q.push({{a, 0}, res});
  while(!q.empty()){
    int x = q.front().first.first;
    int count = q.front().first.second;
    vector<int> temp = q.front().second;
    q.pop();
    if(x==b){
      printf("%d\n", count);
      for(int i=0; i<temp.size(); i++){
        printf("%d ", temp[i]);
      }
      return ;
    }

    if(v[x]==1) continue;
    v[x]=1;

    if(x-1 >=0){
      temp.push_back(x-1);
      q.push({{x-1, count+1}, temp});
      temp.pop_back();
    }
    if(x+1 <VMAX){
      temp.push_back(x+1);
      q.push({{x+1, count+1}, temp});
      temp.pop_back();
    }
    if(x*2 <VMAX){
      temp.push_back(x*2);
      q.push({{x*2, count+1}, temp});
      temp.pop_back();
    }
  }
  return ;
}

int main(){
  cin >> a >> b;
  bfs();
  return 0;
}

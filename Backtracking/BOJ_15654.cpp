#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> input;
vector<int> result;
int v[8]={0}; // 0~7 

void bt(int depth){
  if(result.size()==m){
    for(int i=0; i<result.size(); i++){
      printf("%d ", result[i]);
    }
    printf("\n");
    return ;
  }
  if(depth==n) return ;
  for(int i=0; i<n; i++){
    if(v[i]==1) continue;
    v[i]=1;
    result.push_back(input[i]);
    bt(depth+1);
    result.pop_back();
    v[i]=0;
  }
  return ;
}

int main(){
  cin >> n >> m;
  for(int x,i=0; i<n; i++){
    scanf("%d", &x);
    input.push_back(x);
  }
  sort(input.begin(), input.end());
  bt(0);
  return 0;
}

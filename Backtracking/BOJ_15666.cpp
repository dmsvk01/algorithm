#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> input;
vector<int> res;

void bt(int depth, int cur){
  if(depth==m){
    for(int i=0; i<m; i++){
      printf("%d ", res[i]);
    }
    printf("\n");
    return ;
  }
  int mul=-1;
  for(int i=cur; i<n; i++){
    if(mul == input[i]) continue;
    mul = input[i];
    res.push_back(input[i]);
    bt(depth+1, i);
    res.pop_back();
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
  bt(0,0);
}
